#define INFINITY true
//--------------------//
#include <iostream>
#include <vector>
#include <thread>
//--------------------//
#include <boost/asio.hpp>
#include "mysql.hpp"
//--------------------//
#include "server.hpp"
#include "client.hpp"
#include "globals.hpp"
#include "main.hpp"
//--------------------------//
using namespace std;
using namespace boost::asio;
//--------------------------//


int main(int argc, char *argv[]) {
    
    startServer();
}




void startServer() {
    serv.startUpdateDataToAuthClients(); //этот метод отправляет данные клиентам из serv.AuthClient; раз в 5 секунд он асинхроно посылает данные
    while (INFINITY)  {
        serv.checkConnectedWithNewClient(); //этот метод првоеряет соединение с сокетом по TCP, если оно успешно то добавляет сокет в serv.unAuthClietts
        serv.checkAndSetAuthClientsFromUnAuth();//этот метод слшует клиентов на ауте.. аси... и при удачной аутен.. удаляет из unAuth и добовялет в Auth
        serv.leaseanAndExecuteRequetsAuthClients();// 


        cout << "count unAuthClients: " << serv.unAuthClients.size() << "       count authClients: " << serv.authClients.size() << endl;
        cout <<"poll" <<endl;

        serv.io.poll();
        serv.io.restart();

        sleep(3.5);
    }
}
