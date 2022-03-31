//
// Created by leila on 3/28/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_CITY_H
#define INC_22S_FLIGHT_PLANNER_CITY_H

#include "DSString.h"
#include "DSVector.h"

class City{
private:
    DSString endCity;
    //DSString airline;
    DSVector<DSString> airlines;
    //int cost, time;
    DSVector<int> costs;
    DSVector<int> times;
public:
    City();
    City(const DSString& endCity, int cost, int time, const DSString& airline);
    ~City();
    City(const City&);
    City& operator=(const City&);
    bool operator==(const City&);
    DSString getEndCity()const;
    DSVector<DSString>& getAirline();
    DSVector<int>& getCost();
    DSVector<int>& getTime();
    friend ostream& operator<<(ostream& output, const City& temp);
};
#endif //INC_22S_FLIGHT_PLANNER_CITY_H
