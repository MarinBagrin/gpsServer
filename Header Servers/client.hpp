#ifndef client
#define client

#include <iostream>
#include <vector>
#include <string>
#include <boost/asio.hpp>
#include "tracker.pb.hpp"
using namespace std;
using namespace boost::asio;

class Client {
public:
    int ID;
    string name;
    string password;
    string organisation;
    tracker_list list_t;
    tracker_list list_archive_t;
    vector<string> lists_str_archive;
    int dataBuffer[20];
    
    char authBuffer[32];
    char requestbuffer[64];
    string serializedTrackers;
    string serializedTrackersArchive;
    ip::tcp::socket* rozetka;
    bool isLeasing;
    bool isWriting;
    
    Client(io_context& io, int id = 0, string nameStr = "unAuth");
    string getNamePass();
};

#endif
