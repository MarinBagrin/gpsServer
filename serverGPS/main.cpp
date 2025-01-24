#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include "server.hpp"
#include "client.hpp"
#include "globals.h"
//#include "mysql.hpp"
using namespace std;
using namespace boost::asio;

bool infinity = true;

int main() {
    //
    storageClients["Marin"] = new Client(serv.io);
    storageClients["Marin"]->password = "admin";
    //
    infinity = true;


    serv.startUpdateDataToAuthClients();
    while (infinity)  {
        serv.checkConnectedWithNewClient();
        serv.checkAndSetAuthClients();

        
        
        
        
        
        
        
        
        
        cout << "size unAuthClients: " << serv.unAuthClients.size() << "       size authClients: " << serv.authClients.size() << endl;
        cout <<"poll" <<endl;

        serv.io.poll();
        serv.io.restart();

        sleep(5);
    }
}


