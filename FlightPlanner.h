//
// Created by leila on 3/31/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHTPLANNER_H
#define INC_22S_FLIGHT_PLANNER_FLIGHTPLANNER_H

#include "DSLinkedList.h"
#include "DSString.h"
#include "DSVector.h"
#include "Flight.h"
#include "OriginCity.h"
#include "DSStack.h"

class FlightPlanner{
    DSVector<DSLinkedList<Flight>> itinerary;


    void makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList);
    //goals is the start, end, T or C
    DSLinkedList<Flight> calculatePaths(DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList);
    bool onStack (DSStack<DSString> stack, DSString element);
};
#endif //INC_22S_FLIGHT_PLANNER_FLIGHTPLANNER_H
