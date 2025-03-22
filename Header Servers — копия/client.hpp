#ifndef client
#define client

#include <iostream>
#include <vector>
#include <string>
#include <boost/asio.hpp>
#include "tracker.hpp"

using namespace std;
using namespace boost::asio;

class Client {
public:
    int ID;
    string name;
    string password;
    vector<Tracker> trakcers; //////
    int dataBuffer[20];
    char authBuffer[32];
    ip::tcp::socket* rozetka;
    bool isLeasing;
    bool isWriting;
    
    Client(io_context& io, int id = 0, string nameStr = "unAuth");
    string getNamePass();
};

#endif
