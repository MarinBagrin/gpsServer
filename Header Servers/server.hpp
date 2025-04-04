#ifndef server
#define server
//------------------------
#include <iostream>
#include <boost/asio.hpp>
#include <map>
#include <vector>
#include <string>
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
    void checkConnectedWithNewClient();
    void checkAndSetAuthClientsFromUnAuth();
    void startUpdateDataToAuthClients();
    void leaseanAndExecuteRequetsAuthClients();
};
void updateClients();
void sendDataToClients();
void checkConnection(boost::system::error_code ec);
void updateNewDataToClient(Client* ptrClient);
void updateNewDataToClients();
void timerUpdateNewDataToClients(const boost::system::error_code& ec);
void closeSocket(Client* ptrClient);
void updateNewDataToClient(Client* ptrClient);


#endif
