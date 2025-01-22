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
    vector<Tracker> trakcers();
    char authBuffer[32];
    bool isLeasen;
    ip::tcp::socket* rozetka;
    static int unAuthsClients;
    
    
    Client(io_context& io, int id = 0, string nameStr = "unAuth"):
    rozetka(new ip::tcp::socket(io)), password("1234"), isLeasen(false){
        ID = id;
        name = nameStr;
    }
    string getNamePass() {
        return name + " " + password;
    }
    
};

#endif
