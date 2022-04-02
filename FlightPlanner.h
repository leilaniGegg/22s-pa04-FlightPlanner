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
private:
    DSVector<DSLinkedList<Flight>> itinerary;

public:
    void makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList);
    //goals is the start, end, T or C
    DSLinkedList<Flight> calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList);
    bool onStack (DSStack<DSString> stack, const DSString& element);
    //DSLinkedList<Flight> storePath(Stack)
};
#endif //INC_22S_FLIGHT_PLANNER_FLIGHTPLANNER_H
