//
// Created by leila on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHT_H
#define INC_22S_FLIGHT_PLANNER_FLIGHT_H

#include <iostream>
#include "DSString.h"

class Flight{
private:
    DSString startCity;
    DSString endCity;
    DSString airline;
    int cost;
    int time;

public:
    Flight();
    Flight(const DSString& s, const DSString& e, const DSString& a, int c, int t);
    ~Flight();
    Flight(const Flight&);
    Flight& operator=(const Flight&);
    bool operator==(const Flight&);
    DSString& getStart();
    DSString& getEnd();
    DSString& getAirline();
    int getCost();
    int getTime();
    friend ostream& operator<< (ostream&, const Flight&);


};
#endif //INC_22S_FLIGHT_PLANNER_FLIGHT_H
