#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include <vector>
#include <string>
#include "globals.hpp"
#include "client.hpp"

using namespace std;
using namespace boost::asio;


Server::Server():io(),
    acceptor(io,ip::tcp::endpoint(boost::asio::ip::tcp::v4(),49500)),
    newClient(new Client(io)),
    timer(io) {
        acceptor.async_accept(*(newClient->rozetka),&checkConnection);
}
    ///class Server functions
void Server::checkConnectedWithNewClient() {
    if (newClient->rozetka->is_open()) {
        unAuthClients.push_back(newClient);
        newClient = new Client(io);
        acceptor.async_accept(*(newClient->rozetka),&checkConnection);
    }
}
void Server::checkAndSetAuthClients() {
    for (int i = 0; i < unAuthClients.size(); ++i) {
        Client* ptrClient = unAuthClients[i];
        if (!(ptrClient->isLeasing)) {
            ptrClient->isLeasing = true;
                
            ptrClient->rozetka->async_read_some(buffer(ptrClient->authBuffer),
                                                [ptrClient,i](const boost::system::error_code& ec, size_t bytes_transferred) {
                ptrClient->isLeasing = false;
                
                if (ec) {
                    if (ec == boost::asio::error::eof) {
                        // Соединение закрыто удаленной стороной
                        std::cerr << "Connection closed gracefully by the peer." << std::endl;
                    } else if (ec == boost::asio::error::operation_aborted) {
                        // Операция была отменена
                        std::cerr << "Read operation was aborted." << std::endl;
                    } else {
                        // Обработка других типов ошибок
                        std::cerr << "Error during read: " << ec.message() << std::endl;
                    }
                    closeSocket(ptrClient);
                    delete ptrClient;
                }
                else {
                    // Если ошибка нет, то выводим количество прочитанных байт и данные
                    cout << "Successfully read " << bytes_transferred << " bytes." << std::endl;
                    //cout << "Received data: " << string(ptrClient->authBuffer, bytes_transferred) << std::endl;
                    cout << "Received data: " << ptrClient->authBuffer << std::endl;
                    string namePass[2]; //name and password values, 0 for name nad 1 for pass
                    char* recieveBuffer = ptrClient->authBuffer;
                    int j = 0;
                    for (int i = 0; i < 2; i++) {
                        for (; j < 32 ; ++j ) {
                            if (recieveBuffer[j] == '/') {
                                ++j;
                                break;
                            }
                            namePass[i] += recieveBuffer[j];
                        }
                    }
                    serv.sqlServ.getNamePassClient(ptrClient, namePass);
                    if (ptrClient->getNamePass() == namePass[0]+' '+namePass[1]) {
                        serv.authClients.push_back(ptrClient);
                        serv.unAuthClients.erase(find(serv.unAuthClients.begin(),serv.unAuthClients.end(),ptrClient));
                    }
                }
            });
        }
    }
}

void Server::startUpdateDataToAuthClients() {
    timer.expires_after(std::chrono::seconds(5));
    timer.async_wait(&updateNewDataToClients);
}

void checkConnection(boost::system::error_code ec) {
    if(ec) {
        cout << ec.message() << "-\n";
    }
    else {
        
        Client* connectedClient = serv.newClient;
        cout << connectedClient->rozetka->remote_endpoint().address().to_string() << ':' << connectedClient->rozetka->remote_endpoint().port() << endl;
    }
    
}

void updateNewDataToClients(const boost::system::error_code& ec) {
    if (ec){
        if (ec) {
            std::cout << "Ошибка отмены: " << ec.message() << "\n";
        }
        else {
            std::cout << "Таймер завершился.\n";
        }
    }
    //что делать если таймер завершится
    else {
        for (int i = 0; i < serv.authClients.size(); ++i) {
            Client* ptrClient = serv.authClients[i];
            if (!(ptrClient->isWriting)) {
                char bufferSend[20490];
                serv.sqlServ.getDataClient(ptrClient,bufferSend);
                async_write(*(ptrClient->rozetka),buffer(bufferSend),[ptrClient](const boost::system::error_code& ec, size_t bytes_transferred) {
                    if (ec) {
                        cout << ec.message();
                        closeSocket(ptrClient);
                    }
                    else {
                        ptrClient->isWriting = false;
                        cout << "TheData will send to: " + ptrClient->getNamePass() << endl;
                    }
                    
                });
            }
        }
        serv.startUpdateDataToAuthClients();
    }
}

void closeSocket(Client* ptrClient) {
    ptrClient->rozetka->close();
    if (ptrClient->name == "unAuth") {
        auto it = find(serv.unAuthClients.begin(),serv.unAuthClients.end(),ptrClient);
        if (serv.unAuthClients.end() != it)
        {
            serv.unAuthClients.erase(it);
        }
        else {
            serv.authClients.erase(find(serv.authClients.begin(),serv.authClients.end(),ptrClient));
        }
    }
    cout << "Socket is Closed and Client is deleted"<<endl;
}

