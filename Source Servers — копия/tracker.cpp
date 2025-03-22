#include <iostream>
#include "tracker.hpp"
#include <string>
#include <cstdlib>
#include <ctime>



    Tracker::Tracker() {
        //srand(time_t(0));
        //time = rand() % 24;
        ID = rand() % 100;
        name = to_string(ID);
        longitudine = rand() % 50;
        latitudine = rand() % 50;
    }

