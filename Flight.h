//
// Created by leila on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHT_H
#define INC_22S_FLIGHT_PLANNER_FLIGHT_H

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
    ~Flight();
    Flight(const Flight&);
    Flight& operator=(const Flight&);

};
#endif //INC_22S_FLIGHT_PLANNER_FLIGHT_H
