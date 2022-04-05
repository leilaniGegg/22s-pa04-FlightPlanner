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
    void makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList, const DSString& filename);
    //goals is the start, end, T or C
    DSVector<DSLinkedList<Flight>> calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList);
    bool onStack (DSStack<OriginCity> stack, const City& element);
    DSVector<DSStack<OriginCity>> backtrack(const DSString begin, const DSString end, DSLinkedList<OriginCity>& adjList);
    DSVector<DSLinkedList<Flight>> routing(DSVector<DSStack<OriginCity>>& paths, DSString& condition );
    DSVector<DSLinkedList<Flight>> optimize(DSVector<DSLinkedList<Flight>> routes, DSString& condition); //test with adding & back to routes
    int getTotalTime(DSLinkedList<Flight>& route);
    int getTotalCost(DSLinkedList<Flight>& route);
    /**
     *
     * @param filename
     * @param request i.e start, end, T||C
     * @param optimizedRoutes list of flights with best T||C
     * @param currReq current start/end request
     */
    void writeToFile(ostream& file, DSVector<DSString> requests, DSVector<DSLinkedList<Flight>> optimizedRoutes, int currReq);
};
#endif //INC_22S_FLIGHT_PLANNER_FLIGHTPLANNER_H
