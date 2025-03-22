//---------------std
#include <string>
#include <iostream>
//-----------------------mysql
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
//----------------------------my.hpp
#include "mysql.hpp"
//----------------------------using namespaces
using namespace std;
using namespace sql;
using namespace sql::mysql;
void setBufferForSend(char* buffer, string gpses);
Sql::Sql():
driver(get_mysql_driver_instance()),
con(driver->connect("tcp://127.0.0.1:3306", "root", "marin18")){
    con->setSchema("gpsTrackers");
    stmt = con->createStatement();
}

void Sql::getNamePassClient(Client *ptrClient, string *ptrString) {
    ResultSet *res = stmt->executeQuery("SELECT user_id, name, pass FROM users WHERE name =\"" + ptrString[0] + "\"");
    cout << 124;
    while ( res->next() ) {
        ptrClient->ID = res->getInt("user_id");
        ptrClient->name = res->getString("name");
        ptrClient->password = res->getString("pass");
        cout << res->getInt("user_id") << endl;;
        cout << res->getString("name") << endl;
        cout << res->getString("pass") << endl;;
    }
}

void Sql::getDataClient(Client *ptrClient,  char* buffer) {
    ResultSet *res = stmt->executeQuery("SELECT longitude, latitude, gps_id FROM gpses WHERE owner_id = " + to_string(ptrClient->ID));
    string gpses;
    while ( res->next() ) {
        gpses += res->getString("latitude") + res->getString("longitude") + res->getString("gps_id");
    }
    setBufferForSend(buffer, gpses);

}

void setBufferForSend(char* buffer, string gpses) {
    *(reinterpret_cast<int*>(buffer)) = static_cast<int>(gpses.size()/20);
    for (int i = 2; i < gpses.size(); ++i) {
        buffer[i] = gpses[i-2];
    }
    
}
