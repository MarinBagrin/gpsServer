#ifndef mysql_hpp
#define mysql_hpp
//---------------std
#include <string>
#include <iostream>
//-----------------------mysql
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
//----------------------------my.hpp
#include "client.hpp"
//----------------------------using namespaces
using namespace std;
using namespace sql;
using namespace sql::mysql;
//-------------------------define Sql
class Sql {
public:
    MySQL_Driver *driver;
    Connection *con_newgps;
    Statement *stmt_newgps;
    Connection *con_longdb;
    Statement *stmt_longdb;
    Sql();
    
    void getArchiveFor(Client* ptrClient,string begin, string end, string id);
    void getNamePassClient(Client *ptrClient, string* ptrStr);
    void updateDataClient(Client *ptrClient);
};
string intToHex(int num);

#endif
