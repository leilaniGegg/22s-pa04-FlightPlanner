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
#include "City.h"

class FlightPlanner{
private:
    //DSVector<DSLinkedList<Flight>> itinerary;

public:
    void makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList);
    //goals is the start, end, T or C
    void calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList);
    bool onStack (DSStack<OriginCity> stack, const City& element);
    DSVector<DSStack<OriginCity>> backtrack(const DSString begin, const DSString end, DSLinkedList<OriginCity>& adjList);
    DSVector<DSLinkedList<Flight>> routing(DSVector<DSStack<OriginCity>>& paths);
    DSVector<DSStack<Flight>> optimize(const DSVector<DSStack<Flight>>& routes, const DSString& condition);
    //DSLinkedList<Flight> storePath(Stack)
};
#endif //INC_22S_FLIGHT_PLANNER_FLIGHTPLANNER_H
