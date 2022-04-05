//
// Created by leila on 3/31/2022.
//

#include "FlightPlanner.h"

void FlightPlanner::makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList, const DSString& filename){
    //loop through each request, and calculate its optimal paths, then write those to output file
    ofstream file;
    file.open(filename.c_str());
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    else {
        for (int i = 0; i < req.getSize(); i++) {
            writeToFile(file, req.at(i), calculatePaths(req.at(i), adjList), i+1);
        }
    }
    file.close();
}

void FlightPlanner::writeToFile(ostream& file, DSVector<DSString> requests, DSVector<DSLinkedList<Flight>> optimizedRoutes, int currReq){
        if(optimizedRoutes.getSize() == 0){
            file << "No paths possible" << endl;
        }
        else {
            if (requests.at(2)[0] == 'T') { //if the condition is to optimize time
                file << "Flight " << currReq << ": " << requests.at(0) << ", " << requests.at(1) << " (Time)" << endl;
                for (int i = 0; i < optimizedRoutes.getSize(); i++) {
                    file << "  Itinerary " << i + 1 << ": " << endl;
                    file << optimizedRoutes.at(i);
                    file << "    " << "Totals for Itinerary " << i + 1 << ":  Time: "
                         << getTotalTime(optimizedRoutes.at(i))
                         << "  Cost:  " << getTotalCost(optimizedRoutes.at(i)) << endl;
                }
            } else { //if the condition is to optimize cost
                file << "Flight " << currReq << ": " << requests.at(0) << ", " << requests.at(1) << " (Cost)" << endl;
                for (int i = 0; i < optimizedRoutes.getSize(); i++) {
                    file << "  Itinerary " << i + 1 << ": " << endl;
                    file << optimizedRoutes.at(i);
                    file << "    " << "Totals for Itinerary " << i + 1 << ":  Time: "
                         << getTotalTime(optimizedRoutes.at(i))
                         << "  Cost:  " << getTotalCost(optimizedRoutes.at(i)) << endl;
                }
            }
        }
}

DSVector<DSStack<OriginCity>> FlightPlanner::backtrack(const DSString begin, const DSString end, DSLinkedList<OriginCity>& adjList){
    //find all possible paths from beginning to start, this is pretty much the psuedo code
    DSStack<OriginCity> stack;
    OriginCity start(adjList.find(begin));
    OriginCity dest(adjList.find(end));
    stack.push(start);
    DSVector<DSStack<OriginCity>> paths;
    adjList.resetIteratorFront();
    while(!stack.isEmpty()){
        if(stack.peek() == dest){ //if the stack top is the destination
            //store the path and pop the top of stack
            paths.push_back(stack);
            stack.pop();
        }
        else{
            //for connection in stack.top, is the connection null
            if(adjList.find(stack.peek()).destinations.getCurr() == nullptr){
                adjList.find(stack.peek()).destinations.resetIteratorFront();
                stack.pop();
            }
             //is the connection on the stack?
             else {
                if (onStack(stack, adjList.find(stack.peek()).destinations.getCurr()->data)) {
                    //move iterator and continue
                    adjList.find(stack.peek()).destinations.getNext();
                    //continue
                } else {
                    //push connection, move iterator
                    OriginCity temp(stack.peek());
                    stack.push(adjList.find(adjList.find(stack.peek()).destinations.getCurr()->data));
                    adjList.find(temp).destinations.getNext();
                    //continue
                }
            }
        }
    }
    return paths;
}

DSVector<DSLinkedList<Flight>> FlightPlanner::routing(DSVector<DSStack<OriginCity>>& paths, DSString& condition){
    if(!paths.isEmpty()) {
        DSVector<DSLinkedList<Flight>> routes;
        //loop through possible paths found (ex. Dallas->Austin->Houston and Dallas->Houston)
        for (int i = 0; i < paths.getSize(); i++) {
            DSLinkedList<OriginCity> path = paths.at(i).getList();
            DSLinkedList<Flight> tempRoute;
            path.resetIteratorFront();

            while (path.hasNext()) {
                OriginCity startCity = path.getCurr()->data;
                path.getNext();
                City endCity(path.getCurr()->data.getOrigin(), 0, 0,"trash");// temp city object to find the end city in the start city's destinations
                int size = startCity.destinations.find(
                        endCity).getAirline().getSize(); //store the size of the airlines vector(same as cost and time vectors)
                //set the first flight as the min temporarily
                Flight min(startCity.getOrigin(), endCity.getEndCity(),
                           startCity.destinations.find(endCity).getAirline().at(0),
                           startCity.destinations.find(endCity).getCost().at(0),
                           startCity.destinations.find(endCity).getTime().at(0));
                for (int j = 0; j < size; j++) {
                    if (condition == "T") {
                        //if the current city is lower in time than the min, then set it as new min
                        if (startCity.destinations.find(endCity).getTime().at(j) < min.getTime()) {
                            Flight temp(startCity.getOrigin(), endCity.getEndCity(),
                                        startCity.destinations.find(endCity).getAirline().at(j),
                                        startCity.destinations.find(endCity).getCost().at(j),
                                        startCity.destinations.find(endCity).getTime().at(j));
                            min = temp;
                        }
                    }
                    else{
                        //if the current city is lower in cost than the min, then set it as new cost
                        if (startCity.destinations.find(endCity).getCost().at(j) < min.getCost()) {
                            Flight temp(startCity.getOrigin(), endCity.getEndCity(),
                                        startCity.destinations.find(endCity).getAirline().at(j),
                                        startCity.destinations.find(endCity).getCost().at(j),
                                        startCity.destinations.find(endCity).getTime().at(j));
                            min = temp;
                        }
                    }
                }
                //only add the routes which are the lowest in time or cost (depending on condition)
                //partially optimizing before the actual optimization step
                tempRoute.push_back(min);
            }
            routes.push_back(tempRoute);
        }
        return routes;
    }
}

DSVector<DSLinkedList<Flight>> FlightPlanner::optimize(DSVector<DSLinkedList<Flight>> routes, DSString& condition){
    DSVector<DSLinkedList<Flight>> bestRoutes; //lowest time/cost to highest
    int count = 0;
    while (count < 3) {
        DSLinkedList<Flight> min = routes.at(0); //set first route of flights as the min
        int minIndex = 0;
        for (int i = 0; i < routes.getSize(); i++) {
            if (condition.c_str() == "T") {
                //if current route is lower in time than the min, then set it as new min
                if (getTotalTime(routes.at(i)) < getTotalTime(min)) {
                    min = routes.at(i);
                    minIndex = i;
                }
            } else {
                //if current route is lower in cost than the min, then set it as new min
                if (getTotalCost(routes.at(i)) < getTotalCost(min)) {
                    min = routes.at(i);
                    minIndex = i;
                }
            }
        }
        bestRoutes.push_back(min);
        if(routes.getSize() > 1){ //do not want to remove index if its size is 1
            routes.removeAtIndex(minIndex);
        }
        else if(routes.getSize() == 1){
            break;
        }
        count++;
    }
    return bestRoutes;
}

DSVector<DSLinkedList<Flight>> FlightPlanner::calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList){
    DSVector<DSStack<OriginCity>> paths = backtrack(goals.at(0), goals.at(1), adjList);
    DSVector<DSLinkedList<Flight>> routes = routing(paths, goals.at(2));
    DSVector<DSLinkedList<Flight>> optimized = optimize(routes, goals.at(2));

    return optimized;
}

//of a list of flights, calculate the total time, including the penalty for layovers and airline changes
int FlightPlanner::getTotalTime(DSLinkedList<Flight>& route){
    route.resetIteratorFront();
    int time = 0;
    while(route.getCurr() != nullptr){
        DSString tempAirline = route.getCurr()->data.getAirline();
        time += route.getCurr()->data.getTime();
        route.getNext();
        if(route.getCurr() == nullptr)break; //this seems redundant ik
        //if two connecting fligts don't have the same airline
        if(tempAirline != route.getCurr()->data.getAirline()){
            time += 27;
        }

    }
    time += (route.getSize()-1) * 43;
    route.resetIteratorFront(); //not sure if needed
    return time;
}

int FlightPlanner::getTotalCost(DSLinkedList<Flight>& route){
    route.resetIteratorFront();
    int cost = 0;
    while(route.getCurr() != nullptr){
        cost += route.getCurr()->data.getCost();
        route.getNext();

    }
    cost += (route.getSize() - 1) * 23;
    route.resetIteratorFront();
    return cost;
}

//check whether item is on the stack
bool FlightPlanner::onStack (DSStack<OriginCity> stack, const City& element){
    DSStack<OriginCity> tempStack;
    while(!stack.isEmpty()) {
        tempStack.push(stack.peek());
        stack.pop();
        if (tempStack.peek() == element) {
            return true;
        }
    }
    return false;
}