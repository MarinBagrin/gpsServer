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
    Connection *con;
    Statement *stmt;
    Sql();
    
    void getNamePassClient(Client *ptrClient, string* ptrStr);
    void getDataClient(Client *ptrClient, char* buffer);
};

#endif
