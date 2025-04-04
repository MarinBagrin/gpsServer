//---------------std
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
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
con_newgps(driver->connect("tcp://192.168.100.10:3407", "root", "rootmans")),
con_longdb(driver->connect("tcp://192.168.100.10:3407", "root", "rootmans")){
    con_newgps->setSchema("gpsnew");
    stmt_newgps = con_newgps->createStatement();
    con_longdb->setSchema("long_database");
    stmt_longdb = con_longdb->createStatement();
}

void Sql::getNamePassClient(Client *ptrClient, string *ptrString) {
    con_newgps->setSchema("gpsnew");
    ResultSet *res = stmt_newgps->executeQuery("SELECT users, user_name, password FROM users_acces WHERE user_name =\"" + ptrString[0] + "\"");
    cout << 124;
    if ( res->next() ) {
        ptrClient->name = res->getString("user_name");
        ptrClient->password = res->getString("password");
        ptrClient->organisation = res->getString("users");
//        cout << res->getString("user_name") << endl;
//        cout << res->getString("password") << endl;
//        cout << res->getString("users") << endl;
        
        res = stmt_newgps->executeQuery("SELECT id FROM owners WHERE organization_name = \"" + ptrClient->organisation + "\"");
        res->next();
        ptrClient->ID = res->getInt("id");
        
        res = stmt_newgps->executeQuery("SELECT unit_id FROM user_devices WHERE user_id = " +  to_string(ptrClient->ID) );
//        cout << "organisation_name = " << ptrClient->organisation << endl;
//        cout << "organisation_id = " << ptrClient->ID << endl;
        ptrClient->list_t.clear_trackers();
        while(res->next()) {
            string id = res->getString("unit_id");
            

            ResultSet* res_obj_data = stmt_newgps->executeQuery("SELECT denumirea FROM objects_data WHERE id_dispozitiv =\"" + id + "\"");
            res_obj_data->next();
            //res->next();
            tracker* ptrTracker = ptrClient->list_t.add_trackers();
            ptrTracker->set_name(res_obj_data->getString("denumirea"));
            ptrTracker->set_id(id);
//            cout << id << " id\n";
//            cout << resultHex << " hex\n";
//            cout << ptrTracker->name() << " hex\n";
            
        }
    }
}

void Sql::updateDataClient(Client *ptrClient) {
    unsigned int high_nibble = 240;
    unsigned int low_nibble = 15;
    cout <<"count trackers of " << ptrClient->name <<" = " << ptrClient->list_t.trackers_size() << endl;
    
    for (int i = 0; i < ptrClient->list_t.trackers_size(); ++i) {
        tracker* ptrTracker = ptrClient->list_t.mutable_trackers(i);
        string id = ptrTracker->id();
        string idHex = intToHex(stoi(string(1,id[0]) + id[1] + id[2])) + intToHex(stoi(string(1,id[3]) + id[4] + id[5]));//
        for (int i = 0; i < idHex.size(); ++i) {
            if (idHex[i] >= 97 && idHex[i] <= 122) {
                idHex[i] -= 32;
            }
        }
        ResultSet* res = stmt_longdb->executeQuery("SELECT data FROM raw_data  WHERE device_id =\"" + idHex + "\" ORDER BY id DESC");

        if (res->next()) {
            cout << "ID HEX tracker: " << idHex <<endl;
//            cout << "trackers =" << " " << ptrClient->list_t.trackers_size() << endl;
//            cout << "i =" << i << endl;
//            cout << ptrTracker->id() << endl;
            string data = res->getString("data");
            char* pointer = data.data();
            if ((low_nibble & pointer[1]) != 0) {
                ptrTracker->set_battery(100 / (15 / (low_nibble & pointer[1])));
            }
            else {
                ptrTracker->set_battery(0);
            }
            //cout << "battery " << ptrTracker->battery() << endl;
            ptrTracker->set_speed(pointer[13] * 1.852);
            string coordinates;
            string latitude;
            string longitude;
            
            for(int i = 14; i < 23; ++ i) {
                coordinates += static_cast<char>(((pointer[i] & high_nibble) >> 4) + 48);
                coordinates += static_cast<char>((pointer[i] & low_nibble) + 48);
            }
            bool flagSuccesfulParcing = true;
            for(int i = 0; i < 7; ++i) {
                if(i == 2 || i == 4){
                    latitude += '.';
                    longitude += '.';
                }
                if ((coordinates[i] >= 48 && coordinates[i] <= 57) && (coordinates[i+9] >= 48 && coordinates[i] <= 57)) {
                    latitude += coordinates[i];
                    longitude += coordinates[i+9];
                }
                else {
                    cout << "неудачный парсинг\n";
                    flagSuccesfulParcing = false;
                    break;
                    
                }
                
            }
            
            cout << "longitude << " << longitude << endl;
            cout << "latitude << " << latitude << endl;
            if(flagSuccesfulParcing) {
                //            cout << "latitude: " <<to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60) << endl;
                //            cout << "longitude: " << to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, latitude.size())) / 60) << endl;
                ptrTracker->set_latitude(to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60));
                ptrTracker->set_longitude(to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, longitude.size()))/60 ));
            }
        }
        res = stmt_newgps->executeQuery("SELECT data FROM objects_logs  WHERE did =\"" + id + "\" ORDER BY id DESC");
        if (res->next()) {
            cout << "ID DEC tracker: " << id <<endl;

            string data = res->getString("data");
            char* pointer = data.data();
            ptrTracker->set_battery(100);
            //cout << "battery " << ptrTracker->battery() << endl;
            ptrTracker->set_speed(pointer[13] * 1.852);
            string latitude;
            string longitude;
            for(int i = 18; i < 24; ++ i) {
                if (i == 20 || i == 22)
                {
                    latitude += '.';
                    longitude += '.';
                }
                latitude += pointer[i];
                longitude += pointer[i+8];
            }
            cout << "longitude << " << longitude << endl;
            cout << "latitude << " << latitude << endl;
            ptrTracker->set_latitude(to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60));
            ptrTracker->set_longitude(to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, longitude.size()))/60 ));
        }

//        else {
//            time_t now = time(nullptr);
//            tm* local_time = localtime(&now);
//            string date_str = "%" + to_string(local_time->tm_year - 100) + (local_time->tm_mon + 1 < 10 ? "0"+to_string(local_time->tm_mon + 1) : to_string(local_time->tm_mon + 1)) + "%";
//            cout << date_str << "date";
//            res = stmt_longdb->executeQuery("SELECT table_name FROM information_schema.tables WHERE table_schema = 'long_database' AND table_name LIKE '"+ date_str +"'");
//            
//        }
        cout << "Data Sql Request id good\n";
    }
    
    ptrClient->list_t.SerializeToString(&ptrClient->serializedTrackers);

}

//void setBufferForSend(char* buffer, string gpses) {
//    *(reinterpret_cast<int*>(buffer)) = static_cast<int>(gpses.size()/20);
//    for (int i = 2; i < gpses.size(); ++i) {
//        buffer[i] = gpses[i-2];
//    }
//    
//}

string intToHex(int num) {
    std::stringstream ss;
    ss << std::hex << num;  // Устанавливаем шестнадцатеричный формат
    return ss.str();        // Возвращаем строку
}
