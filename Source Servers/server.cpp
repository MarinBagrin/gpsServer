#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include <cstdint> // или <stdint.h> в C
#include <arpa/inet.h>
#include <vector>
#include <string>
#include <cstring>
#include "globals.hpp"
#include "client.hpp"

using namespace std;
using namespace std::chrono;
using namespace boost::asio;


Server::Server():io(),
    acceptor(io,ip::tcp::endpoint(boost::asio::ip::tcp::v4(),49500)),
    newClient(new Client(io)),
    timer(io) {}
    ///class Server functions
void Server::startAcceptingClientsConnections() {
    acceptor.async_accept(*(newClient->rozetka),[this](boost::system::error_code ec){
        if(ec) {
            cout << ec.message() << "-Invalid connecting\n";
            delete this->newClient;
        }
        else {
            Client* connectedClient = newClient;
            this->unAuthClients.push_back(connectedClient);
            cout << connectedClient->rozetka->remote_endpoint().address().to_string() << ':' << connectedClient->rozetka->remote_endpoint().port() << endl;
            this->checkAndSetAuthClientsFromUnAuth(connectedClient);
        }
        newClient = new Client(io);
        this->startAcceptingClientsConnections();
    });
}

void Server::checkAndSetAuthClientsFromUnAuth(Client* checkClient) {
    Client* ptrClient = checkClient;
    
    ptrClient->rozetka->async_read_some(buffer(ptrClient->authBuffer),
                                        [ptrClient, this](const boost::system::error_code& ec, size_t bytes_transferred) {
        if (ec) {
            if (ec == boost::asio::error::eof) {
                // Соединение закрыто удаленной стороной
                std::cerr << "Connection closed gracefully by the peer." << std::endl;
            }
            else if (ec == boost::asio::error::operation_aborted) {
                // Операция была отменена
                std::cerr << "Read operation was aborted." << std::endl;
            }
            else {
                // Обработка других типов ошибок
                cout << "123\n";
                std::cerr << "Error during read: " << ec.message() << std::endl;
                cout << "321\n";
            }
            closeSocket(ptrClient);
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
                char* messageAllowAuth = new char[16]{"AllowAuth/"};
                strcat(messageAllowAuth, to_string(ptrClient->ID).c_str());
                cout << "strcat: " << messageAllowAuth << endl;
                sendLenghtMessage(strlen(messageAllowAuth),ptrClient);

                async_write(*(ptrClient->rozetka), buffer(messageAllowAuth,strlen(messageAllowAuth)),[](const boost::system::error_code& ec, size_t bytes_transferred){
                    cout << "AllowAuth было отправлен" <<  endl;
                    /*delete[] messageAllowAuth;*/});
                updateNewDataToClient(ptrClient);
                leaseanAndExecuteRequetsAuthClients(ptrClient);
            }
            else {
                char* messageUnAllowAuth = new char[]{"NoAuth"};
                sendLenghtMessage(strlen(messageUnAllowAuth),ptrClient);
                async_write(*(ptrClient->rozetka), buffer(messageUnAllowAuth,strlen(messageUnAllowAuth)),[](const boost::system::error_code& ec, size_t bytes_transferred){
                    cout << "UnAllowAuth было отправлено" << endl;
                });
                this->checkAndSetAuthClientsFromUnAuth(ptrClient);
            }
        }
    });
    cout << "count unAuthClients: " << serv.unAuthClients.size() << "       count authClients: " << serv.authClients.size() << endl;

}


void sendLenghtMessage(int32_t lenght,Client* ptrClient) {
    int32_t lenghtMessage = htonl(lenght);
    async_write(*(ptrClient->rozetka), buffer(reinterpret_cast<char*>(&lenghtMessage),sizeof(int32_t)),[lenght](const boost::system::error_code& ec, size_t bytes_transferred){
//        cout << "4-byte int32-t send with value: " << lenght << endl;
        //cout << "Lenght in 4 byte was sended: " << lenght << endl;
    });
}

void Server::startUpdateDataToAuthClients() {
    timer.expires_after(std::chrono::seconds(5));
    timer.async_wait(&timerUpdateNewDataToClients);
}



void updateNewDataToClients() {
    
    for (int i = 0; i < serv.authClients.size(); ++i) {
        Client* ptrClient = serv.authClients[i];
        if (!(ptrClient->isWriting)) {
            serv.sqlServ.updateDataClient(ptrClient);
            sendLenghtMessage(ptrClient->serializedTrackers.size(), ptrClient);
            async_write(*(ptrClient->rozetka),buffer(ptrClient->serializedTrackers),[ptrClient](const boost::system::error_code& ec, size_t bytes_transferred) {
                if (ec) {
                    cout << ec.message();
                    cout << "Err: not update new data to Clients:";
                    closeSocket(ptrClient);
                }
                else {
                    ptrClient->isWriting = false;
                    cout << "TheData was sended to: " + ptrClient->getNamePass() << endl;
                }
            });
        }
    }
}
void updateNewDataToClient(Client* ptrClient) {
    
    if (!(ptrClient->isWriting)) {
        serv.sqlServ.updateDataClient(ptrClient);
        sendLenghtMessage(ptrClient->serializedTrackers.size(), ptrClient);
        async_write(*(ptrClient->rozetka),buffer(ptrClient->serializedTrackers),[ptrClient](const boost::system::error_code& ec, size_t bytes_transferred) {
            if (ec) {
                cout << ec.message();
                cout << "Err: not update new data to Client:";

                closeSocket(ptrClient);
            }
            else {
                ptrClient->isWriting = false;
                cout << " First TheData was sended to: " + ptrClient->getNamePass() << endl;
            }
        });
    }
}

void timerUpdateNewDataToClients(const boost::system::error_code &ec) {
    //что делать если таймер завершится???????
    if (ec){
        if (ec) {
            std::cout << "Ошибка отмены: " << ec.message() << "\n";
        }
        else {
            std::cout << "Таймер завершился.\n";
        }
    }
    else {
        updateNewDataToClients();
        serv.startUpdateDataToAuthClients();
    }
}

void closeSocket(Client* ptrClient) {
    if (ptrClient->rozetka == nullptr) { return; }
    ptrClient->rozetka->close();
    auto it = find(serv.unAuthClients.begin(),serv.unAuthClients.end(),ptrClient);
    if (serv.unAuthClients.end() != it) {
        serv.unAuthClients.erase(it);
    }
    else {
        auto itAuth = find(serv.authClients.begin(),serv.authClients.end(),ptrClient);
        serv.authClients.erase(itAuth);
    }
    delete ptrClient->rozetka;
    delete ptrClient;
    cout << "Socket is Closed and Client is deleted"<<endl;
}

void Server::leaseanAndExecuteRequetsAuthClients(Client* ptrClient) {
    
    cout << "Start Leasen " << ptrClient->getNamePass() << endl;
    ptrClient->rozetka->async_read_some(buffer(ptrClient->requestbuffer),[ptrClient,this](const boost::system::error_code& ec, size_t bytes_transferred){
        
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
            cout << "12345\n";
            closeSocket(ptrClient);
            cout << "32141\n";
        }
        else {
            char* reqBuf = ptrClient->requestbuffer;
            string reqStrBuf = reqBuf;
            cout << "Readed: " << reqBuf << endl;
            if (reqStrBuf == "setInUnAuth") { // этот запрос выполнится при своравчивании приложения либо же при потери связи между устр.
                auto iter = find(serv.authClients.begin(),serv.authClients.end(),ptrClient);
                cout << "Client " << ptrClient->name <<" was placed in unAuth" << endl;
                serv.unAuthClients.push_back(ptrClient);
                serv.authClients.erase(iter);
            }
            else if (reqStrBuf.find("ravch") != std::string::npos) {
                ptrClient->serializedTrackersArchive.clear();
                
                string name;
                string begin;
                string end;
                string id;
                int i = 6;
                for (; reqStrBuf[i] != '/'; ++i) {
                    name += reqStrBuf[i];
                }
                cout << name << endl;
                ++i;
                for (; reqStrBuf[i] != '/'; ++i) {
                    begin += reqStrBuf[i];
                }
                cout << begin << endl;
                ++i;
                for (; reqStrBuf[i] != '/'; ++i) {
                    end += reqStrBuf[i];
                }
                cout << end << endl;
                
                for (int i = 0 ; i < ptrClient->list_t.trackers_size(); ++i) {
                    if (ptrClient->list_t.trackers(i).name() == name) {
                        id = ptrClient->list_t.trackers(i).id();
                    }
                }
                cout << "server: \nid: "<< id << endl;
                
                sqlServ.getArchiveFor(ptrClient, begin, end, id);
                tracker_list archiveBuffer;
                ptrClient->lists_str_archive.clear();
                for(int i = 0; i < ptrClient->list_archive_t.trackers_size(); ++i) {
                    cout << "cycle - " << i << endl;
//                    ptrClient->list_archive_t.mutable_trackers(i)->set_name("1");
//                    ptrClient->list_archive_t.mutable_trackers(i)->set_coordinates("1");
//                    ptrClient->list_archive_t.mutable_trackers(i)->set_id("1");
//                    ptrClient->list_archive_t.mutable_trackers(i)->set_time_track("2024:02:1 03:23");
//                    ptrClient->list_archive_t.mutable_trackers(i)->set_longitude("47");
//                    ptrClient->list_archive_t.mutable_trackers(i)->set_latitude("47");
                    if (i % 1000 == 0 && i != 0) {
                        string serializedPacketArchive;
                        archiveBuffer.SerializeToString(&serializedPacketArchive);
                        serializedPacketArchive = string("Archive../") + serializedPacketArchive;
                        ptrClient->lists_str_archive.push_back(serializedPacketArchive);
                        archiveBuffer.Clear();
                    }
                    else {
                        tracker* ptrTracker = archiveBuffer.add_trackers();
                        *ptrTracker = *(new tracker(*ptrClient->list_archive_t.mutable_trackers(i)));
                    }
                }
                cout << "archiveBuffer.count: " << archiveBuffer.trackers_size() << endl;
                if (archiveBuffer.trackers_size() != 0) {
                    string serializedPacketArchive;
                    archiveBuffer.SerializeToString(&serializedPacketArchive);
                    serializedPacketArchive = string("Archive00/") + serializedPacketArchive;
                    ptrClient->lists_str_archive.push_back(serializedPacketArchive);
                    archiveBuffer.Clear();
                }
                
                
                sendPartAchive(ptrClient,0);
            }
            cout << "типа все\n";
            this->leaseanAndExecuteRequetsAuthClients(ptrClient);
        }
        //другие запросы
    });
    
}

void sendPartAchive(Client* ptrClient, int index) {
    if (index >= ptrClient->lists_str_archive.size()){
        return;
    }
    string count = to_string(static_cast<int>(ptrClient->lists_str_archive.size()));
    if (count.size() == 2) {
        ptrClient->lists_str_archive[index][7] = count[0];
        ptrClient->lists_str_archive[index][8] = count[1];
    }
    else {
        ptrClient->lists_str_archive[index][7] = '0';
        ptrClient->lists_str_archive[index][8] = count[0];
    }
    ptrClient->lists_str_archive[index][9] = *(to_string(index).c_str());

    sendLenghtMessage(ptrClient->lists_str_archive[index].size(), ptrClient);
    async_write(*(ptrClient->rozetka), buffer(ptrClient->lists_str_archive[index]),[ptrClient,index](const boost::system::error_code& ec, size_t bytes_transferred){
        if (ec) {
            cout << ec.message();
            cout << "Err: not sended archive data to Client: " << ptrClient->getNamePass() << endl;
            closeSocket(ptrClient);
        }
        else {
            ptrClient->isWriting = false;
            cout << "The Archive was sended to: " + ptrClient->getNamePass()  << "with index i: " << index << "and size: " << ptrClient->lists_str_archive[index].size()  << endl << "-" << endl;
            //doing new send
            if (index+1 != ptrClient->lists_str_archive.size()) {
                sendPartAchive(ptrClient, index+1);
            }
        }
    });
}
