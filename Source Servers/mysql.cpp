//---------------std
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include <chrono>
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
using namespace std::chrono;
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

tracker* transformRawDataInTrackerData(string rawData); //temporrar
tracker* transformOldRawDataInTrackerData(string rawData); //temporrar


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

void Sql::getArchiveFor(Client* ptrClient,string begin, string end, string id) {
    string idHex = intToHex(stoi(string(1,id[0]) + id[1] + id[2])) + intToHex(stoi(string(1,id[3]) + id[4] + id[5]));
    ResultSet* res = stmt_longdb->executeQuery("SELECT data, device_date_time FROM raw_data WHERE device_date_time > \'" + begin + "\' AND device_date_time < \'" + end + "\' AND device_id = \"" + idHex + "\"");
    bool isHex = false;
    
    while (res->next()) {
        //cout << "raw_data |\n";
        tracker* archive_tracker = ptrClient->list_archive_t.add_trackers();
        *archive_tracker = *transformRawDataInTrackerData(res->getString("data"));
        string time_tracker = res->getString("device_date_time");
        archive_tracker->set_time_track(time_tracker);
    }
    
        cout <<"hexId archive" <<  idHex  << endl;
        year y_e(stoi(end.substr(0,4)));
        month m_e(stoi(end.substr(5,2)));
        day  d_e(stoi(end.substr(8,2)));
        year_month_day ymd_end{y_e,m_e,d_e};
        year y_b(stoi(begin.substr(0,4)));
        month m_b(stoi(begin.substr(5,2)));
        day  d_b(stoi(begin.substr(8,2)));
        year_month_day ymd_begin{y_b,m_b,d_b};
        
        std::cout << "Дата: "
        << int(ymd_end.year()) << "-"
        << unsigned(ymd_end.month()) << "-"
        << unsigned(ymd_end.day()) << "\n";
        std::cout << "Дата: "
        << int(ymd_begin.year()) << "-"
        << unsigned(ymd_begin.month()) << "-"
        << unsigned(ymd_begin.day()) << "\n";
        
        
        while (ymd_end >= ymd_begin) {
            string yearArchive = to_string(int(ymd_end.year())).substr(2,2);
            string monthArchive =  to_string(unsigned(ymd_end.month()));
            string dayArchive =  to_string(unsigned(ymd_end.day()));
            string name_archive = "a" + yearArchive;
            name_archive += (monthArchive.size() == 1) ? "0" + monthArchive : monthArchive;
            name_archive += (dayArchive.size() == 1) ? "0" + dayArchive : dayArchive;
            
            
            ResultSet* res = stmt_longdb->executeQuery("SELECT table_name FROM information_schema.tables WHERE table_schema = 'long_database' AND table_name LIKE '%"+ name_archive +"%' ORDER BY table_name DESC");
            while(res->next()) {
                cout << "for archive name " << name_archive << endl;
                ResultSet* res_t = stmt_longdb->executeQuery("SELECT data, device_date_time FROM "+ res->getString("table_name") +" WHERE device_date_time > \'" + begin + "\' AND device_date_time < \'" + end + "\' AND device_id = \"" + idHex + "\" ");
                cout << res->getString("table_name");
                while (res_t->next()) {
                    tracker* archive_tracker = ptrClient->list_archive_t.add_trackers();
                    *archive_tracker = *transformRawDataInTrackerData(res_t->getString("data"));
                    string time_tracker = res_t->getString("device_date_time");
                    archive_tracker->set_time_track(time_tracker);
                }
            }
            ymd_end = sys_days{ymd_end} - days{1};
        }
//        ptrClient->list_archive_t.SerializeToString(&ptrClient->serializedTrackersArchive);
    
    {
        res = stmt_newgps->executeQuery("SELECT data, datetime FROM objects_logs WHERE datetime > \'" + begin + "\' AND datetime < \'" + end + "\' AND did = \"" + id + "\"");
        
        while (res->next()) {
            //cout << "objects_logs |\n";
            tracker* archive_tracker = ptrClient->list_archive_t.add_trackers();
            *archive_tracker = *transformOldRawDataInTrackerData(res->getString("data"));
            string time_tracker = res->getString("datetime");
            archive_tracker->set_time_track(time_tracker);
        }
        
        cout <<"decID archive: " <<  id  << endl;
        year y_e(stoi(end.substr(0,4)));
        month m_e(stoi(end.substr(5,2)));
        day  d_e(stoi(end.substr(8,2)));
        year_month_day ymd_end{y_e,m_e,d_e};
        year y_b(stoi(begin.substr(0,4)));
        month m_b(stoi(begin.substr(5,2)));
        day  d_b(stoi(begin.substr(8,2)));
        year_month_day ymd_begin{y_b,m_b,d_b};
        
        std::cout << "Дата начало: "
        << int(ymd_end.year()) << "-"
        << unsigned(ymd_end.month()) << "-"
        << unsigned(ymd_end.day()) << "\n";
        
        std::cout << "Дата конец: "
        << int(ymd_begin.year()) << "-"
        << unsigned(ymd_begin.month()) << "-"
        << unsigned(ymd_begin.day()) << "\n";
        
        
        while (ymd_end >= ymd_begin) {
            string yearArchive = to_string(int(ymd_end.year())).substr(2,2);
            string monthArchive =  to_string(unsigned(ymd_end.month()));
            string dayArchive =  to_string(unsigned(ymd_end.day()));
            string name_archive = "a" + yearArchive;
            name_archive += (monthArchive.size() == 1) ? "0" + monthArchive : monthArchive;
            name_archive += (dayArchive.size() == 1) ? "0" + dayArchive : dayArchive;
            
            
            ResultSet* res = stmt_newgps->executeQuery("SELECT table_name FROM information_schema.tables WHERE table_schema = 'gpsnew' AND table_name LIKE '%"+ name_archive +"%' ORDER BY table_name DESC");
            while(res->next()) {
                cout << "for archive name " << name_archive << endl;
                ResultSet* res_t = stmt_newgps->executeQuery("SELECT data, datetime FROM "+ res->getString("table_name") +" WHERE datetime > \'" + begin + "\' AND datetime < \'" + end + "\' AND did = \"" + id + "\" ");
                cout << res->getString("table_name");
                while (res_t->next()) {
                    tracker* archive_tracker = ptrClient->list_archive_t.add_trackers();
                    *archive_tracker = *transformOldRawDataInTrackerData(res_t->getString("data"));
                    string time_tracker = res_t->getString("datetime");
                    archive_tracker->set_time_track(time_tracker);
                }
            }
            ymd_end = sys_days{ymd_end} - days{1};
        }
    }
        //ptrClient->list_archive_t.SerializeToString(&ptrClient->serializedTrackersArchive);
    
}

void Sql::updateDataClient(Client *ptrClient) {
    unsigned char high_nibble = 240;
    unsigned char low_nibble = 15;
    cout <<"count trackers of " << ptrClient->name <<" = " << ptrClient->list_t.trackers_size() << endl;
    ptrClient->list_archive_t.Clear();
    for (int i = 0; i < ptrClient->list_t.trackers_size(); ++i) {
        tracker* ptrTracker = ptrClient->list_t.mutable_trackers(i);
        
        string id = ptrTracker->id();
        string idHex = intToHex(stoi(string(1,id[0]) + id[1] + id[2])) + intToHex(stoi(string(1,id[3]) + id[4] + id[5]));//
        
        
        ResultSet* res = stmt_longdb->executeQuery("SELECT data, device_date_time FROM raw_data WHERE device_id =\"" + idHex + "\" ORDER BY id DESC");

        if (res->next()) {
            cout << "name for idHex " << ptrTracker->name() << endl;
//            cout << "ID HEX tracker: " << idHex <<endl;
//            cout << "trackers =" << " " << ptrClient->list_t.trackers_size() << endl;
//            cout << "i =" << i << endl;
//            cout << ptrTracker->id() << endl;
            string data = res->getString("data");
            string date = res->getString("device_date_time");
            ptrTracker->set_time_track(date);
            char* pointer = data.data();
            if ((low_nibble & pointer[1]) != 0) {
                ptrTracker->set_battery(100 / (static_cast<float>(15) / (low_nibble & pointer[1])));
            }
            else {
                ptrTracker->set_battery(0);
            }
            //cout << "battery " << ptrTracker->battery() << endl;
            ptrTracker->set_speed(pointer[13] * 1.852);
            cout << "1111";
            int rfSignal = 100.0 / (static_cast<float>(32) / ( 63 & pointer[8]));
            cout << "\n сигнал rfSignal: " << rfSignal << endl;
            cout << "2222";

            ptrTracker->set_coordinates(to_string(rfSignal));
            cout << "3333";

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
                if ((coordinates[i] >= 48 && coordinates[i] <= 57) && (coordinates[i+9] >= 48 && coordinates[i+9] <= 57)) {
                    latitude += coordinates[i];
                    longitude += coordinates[i+9];
                }
                else {
                    cout << "неудачный парсинг\n";
                    flagSuccesfulParcing = false;
                    break;
                    
                }
                
            }
            
            
            if(flagSuccesfulParcing) {
                //            cout << "latitude: " <<to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60) << endl;
                //            cout << "longitude: " << to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, latitude.size())) / 60) << endl;
                ptrTracker->set_latitude(to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60));
                ptrTracker->set_longitude(to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, longitude.size()))/60 ));
            }
        }
        res = stmt_newgps->executeQuery("SELECT data FROM objects_logs  WHERE did =\"" + id + "\" ORDER BY id DESC");
        if (res->next()) {
            
            string data = res->getString("data");
            char* pointer = data.data();
            ptrTracker->set_battery(100);
            //cout << "battery " << ptrTracker->battery() << endl;
            ptrTracker->set_speed(pointer[6] * 1.852);
            string latitude;
            string longitude;
            bool flagSuccesfulParcing = true;
            for(int i = 18; i < 24; ++ i) {
                if (i == 20 || i == 22)
                {
                    latitude += '.';
                    longitude += '.';
                }

                
                if ((pointer[i] >= 48 && pointer[i] <= 57) && (pointer[i+8] >= 48 && pointer[i+8] <= 57)) {
                    latitude += pointer[i];
                    longitude += pointer[i+8];
                }
                else {
                    cout << "неудачный парсинг\n";
                    flagSuccesfulParcing = false;
                    ptrTracker->set_latitude(to_string(0));
                    ptrTracker->set_longitude(to_string(0));
                    break;
                    
                }
            }
            
            
            ptrTracker->set_latitude(to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60));
            ptrTracker->set_longitude(to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, longitude.size()))/60 ));
        }


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
    string idHex = ss.str();
    for (int i = 0; i < idHex.size(); ++i) {
        if (idHex[i] >= 97 && idHex[i] <= 122) {
            idHex[i] -= 32;
        }
    }
    return idHex;        // Возвращаем строку
}

tracker* transformRawDataInTrackerData(string rawData) {
    tracker* ptrTracker = new tracker();
    unsigned char high_nibble = 240;
    unsigned char low_nibble = 15;
    
    char* pointer = rawData.data();
    if ((low_nibble & pointer[1]) != 0) {
        ptrTracker->set_battery(100 / (15 / (low_nibble & pointer[1])));
    }
    else {
        ptrTracker->set_battery(0);
    }
    //cout << "battery " << ptrTracker->battery() << endl;
    ptrTracker->set_speed(pointer[13] * 1.852);
    cout << "skorotsi archive tracker: " <<pointer[13] * 1.852 << endl;
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
        if ((coordinates[i] >= 48 && coordinates[i] <= 57) && (coordinates[i+9] >= 48 && coordinates[i+9] <= 57)) {
            latitude += coordinates[i];
            longitude += coordinates[i+9];
        }
        
        else {
            cout << "неудачный парсинг\n";
            flagSuccesfulParcing = false;
            break;
            
        }
        
    }
    
//    cout << "longitude << " << longitude << endl;
//    cout << "latitude << " << latitude << endl;
    if(flagSuccesfulParcing) {
        //            cout << "latitude: " <<to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60) << endl;
        //            cout << "longitude: " << to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, latitude.size())) / 60) << endl;
        ptrTracker->set_latitude(to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60));
        ptrTracker->set_longitude(to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, longitude.size()))/60 ));
    }
    return ptrTracker;
}
tracker* transformOldRawDataInTrackerData(string rawData) {
    tracker* ptrTracker = new tracker();
    unsigned char high_nibble = 240;
    unsigned char low_nibble = 15;
    
    
    char* pointer = rawData.data();
    ptrTracker->set_speed(static_cast<int>(pointer[6]) * 1.852);
    
    string coordinates;
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
    
    
    bool flagSuccesfulParcing = true;
    for(int i = 14; i < 23; ++ i) {
        coordinates += static_cast<char>(((pointer[i] & high_nibble) >> 4) + 48);
        coordinates += static_cast<char>((pointer[i] & low_nibble) + 48);
    }

    for(int i = 0; i < 7; ++i) {
        if(i == 2 || i == 4){
            latitude += '.';
            longitude += '.';
        }
        if ((coordinates[i] >= 48 && coordinates[i] <= 57) && (coordinates[i+9] >= 48 && coordinates[i+9] <= 57)) {
            latitude += coordinates[i];
            longitude += coordinates[i+9];
        }
        
        else {
            cout << "неудачный парсинг\n";
            flagSuccesfulParcing = false;
            break;
            
        }
        
    }
    if(flagSuccesfulParcing) {
        
        ptrTracker->set_latitude(to_string(stof(latitude.substr(0, 2)) + stof(latitude.substr(3, latitude.size())) / 60));
        ptrTracker->set_longitude(to_string(stof(longitude.substr(0, 2)) + stof(longitude.substr(3, longitude.size()))/60 ));
    }
    return ptrTracker;
}

