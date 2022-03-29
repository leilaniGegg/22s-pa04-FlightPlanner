//
// Created by leila on 3/28/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_CITY_H
#define INC_22S_FLIGHT_PLANNER_CITY_H

#include "DSString.h"

class City{
private:
    DSString endCity;
    DSString airline;
    int cost, time;
public:
    City(DSString endCity, DSString airline, int cost, int time);
    ~City();
    City(const City&);
    City& operator=(const City&);
    bool operator==(City&);
    DSString getEndCity();
    DSString getAirline();
    int getCost()const;
    int getTime()const;
};
#endif //INC_22S_FLIGHT_PLANNER_CITY_H
