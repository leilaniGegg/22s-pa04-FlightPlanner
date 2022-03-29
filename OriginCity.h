//
// Created by leila on 3/28/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_ORIGINCITY_H
#define INC_22S_FLIGHT_PLANNER_ORIGINCITY_H
#include "DSString.h"
#include "DSLinkedList.h"
#include "City.h"

class OriginCity{
private:
    DSString origin;
public:
    DSLinkedList<City> destinations;
    OriginCity(const DSString&);
    DSString getOrigin();
};
#endif //INC_22S_FLIGHT_PLANNER_ORIGINCITY_H
