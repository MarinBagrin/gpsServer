#ifndef server
#define server
//------------------------
#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include <vector>
#include <string>
#include <cstdint> // или <stdint.h> в C
//------------------------
#include "client.hpp"
#include "mysql.hpp"
//------------------------
using namespace std;
using namespace boost::asio;
//------------------------
class Server {
public:
//------------------------
    io_context io;
    steady_timer timer;
    ip::tcp::acceptor acceptor;
    Sql sqlServ;
    Client* newClient;
//------------------------
    vector<Client*> authClients;
    vector<Client*> unAuthClients;
//--------------------------------
    Server();
//------------------------------------
    void startAcceptingClientsConnections();
    void checkAndSetAuthClientsFromUnAuth(Client* checkClient);
    void startUpdateDataToAuthClients();
    void leaseanAndExecuteRequetsAuthClients(Client* ptrClient);
};
void sendLenghtMessage(int32_t lenght, Client* ptrClient);
void updateClients();
void sendDataToClients();
void updateNewDataToClient(Client* ptrClient);
void updateNewDataToClients();
void timerUpdateNewDataToClients(const boost::system::error_code& ec);
void closeSocket(Client* ptrClient);
void updateNewDataToClient(Client* ptrClient);
void sendPartAchive(Client* ptrClient, int index);


#endif
