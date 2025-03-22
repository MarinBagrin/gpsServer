#include <iostream>
#include <vector>
#include <string>
#include <boost/asio.hpp>
#include "client.hpp"



    
Client::Client(io_context& io, int id, string nameStr ):
    rozetka(new ip::tcp::socket(io)),
    password("1234"),
    isLeasing(false),
    isWriting(false){
    ID = id;
    name = nameStr;
}
string Client::getNamePass() {
    return name + " " + password;
}

