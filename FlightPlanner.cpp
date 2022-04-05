//
// Created by leila on 3/31/2022.
//

#include "FlightPlanner.h"

void FlightPlanner::makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList, const DSString& filename){
    ofstream file;
    file.open(filename.c_str());
    if(!file.is_open()){
        cout << "Failed to open file" << endl;
    }
    else {
        for (int i = 0; i < req.getSize(); i++) {
            cout << "REQUEST #" << i + 1 << endl;
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
            if (requests.at(2) == "T") { //maybe change vector at function to not const
                file << "Flight " << currReq << ": " << requests.at(0) << ", " << requests.at(1) << " (TIME)" << endl;
                for (int i = 0; i < optimizedRoutes.getSize(); i++) {
                    file << "  Itinerary " << i + 1 << ": " << endl;
                    file << optimizedRoutes.at(i);
                    file << "    " << "Totals for Itinerary " << i + 1 << ":  Time: "
                         << getTotalTime(optimizedRoutes.at(i))
                         << "  Cost:  " << getTotalCost(optimizedRoutes.at(i)) << endl;
                }
            } else {
                file << "Flight " << currReq << ": " << requests.at(0) << ", " << requests.at(1) << " (COST)" << endl;
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
                    //continue;
                } else {
                    //push connection, move iterator
                    OriginCity temp(stack.peek());
                    stack.push(adjList.find(adjList.find(stack.peek()).destinations.getCurr()->data));
                    adjList.find(temp).destinations.getNext();
                    //continue;
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
            //1st iteration the path is Dallas->Austin->Houston
            DSLinkedList<OriginCity> path = paths.at(i).getList();
            DSLinkedList<Flight> tempRoute;
            path.resetIteratorFront();

            while (path.hasNext()) {
                OriginCity startCity = path.getCurr()->data;
                path.getNext();
                City endCity(path.getCurr()->data.getOrigin(), 0, 0,
                             "trash");// temp city object to find the end city in the start city's destinations
                int size = startCity.destinations.find(
                        endCity).getAirline().getSize(); //store the size of the airlines vector(same as cost and time vectors)
                Flight min(startCity.getOrigin(), endCity.getEndCity(),
                           startCity.destinations.find(endCity).getAirline().at(0),
                           startCity.destinations.find(endCity).getCost().at(0),
                           startCity.destinations.find(endCity).getTime().at(0));
                for (int j = 0; j < size; j++) {
                    if (condition == "T") {
                        if (startCity.destinations.find(endCity).getTime().at(j) < min.getTime()) {
                            Flight temp(startCity.getOrigin(), endCity.getEndCity(),
                                        startCity.destinations.find(endCity).getAirline().at(j),
                                        startCity.destinations.find(endCity).getCost().at(j),
                                        startCity.destinations.find(endCity).getTime().at(j));
                            min = temp;
                        }
                    }
                    else{
                        if (startCity.destinations.find(endCity).getCost().at(j) < min.getCost()) {
                            Flight temp(startCity.getOrigin(), endCity.getEndCity(),
                                        startCity.destinations.find(endCity).getAirline().at(j),
                                        startCity.destinations.find(endCity).getCost().at(j),
                                        startCity.destinations.find(endCity).getTime().at(j));
                            min = temp;
                        }
                    }
                }
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
        DSLinkedList<Flight> min = routes.at(0);
        int minIndex = 0;
        for (int i = 0; i < routes.getSize(); i++) {
            if (condition.c_str() == "T") {
                if (getTotalTime(routes.at(i)) < getTotalTime(min)) {
                    min = routes.at(i);
                    minIndex = i;
                }
            } else {
                if (getTotalCost(routes.at(i)) < getTotalCost(min)) {
                    min = routes.at(i);
                    minIndex = i;
                }
            }
        }
        bestRoutes.push_back(min);
        if(routes.getSize() > 1){
            routes.removeAtIndex(minIndex);
        }
        /*else if(routes.getSize() == 1){
            break;
        }*/
        count++;
    }
    return bestRoutes;
}

DSVector<DSLinkedList<Flight>> FlightPlanner::calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList){
    DSVector<DSStack<OriginCity>> paths = backtrack(goals.at(0), goals.at(1), adjList);
    DSVector<DSLinkedList<Flight>> routes = routing(paths, goals.at(2));
    DSVector<DSLinkedList<Flight>> optimized = optimize(routes, goals.at(2));

    cout << "Routes" << endl;
    routes.at(0).display();
    cout << "---------------" << endl;
    routes.at(1).display();
    cout << "best route" << endl;
    optimized.at(0).display();
    optimized.at(1).display();

    return optimized;
}

//of a list of flights, calculate the total time, including the penality for layovers and airline changes
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

bool FlightPlanner::onStack (DSStack<OriginCity> stack, const City& element){ //get rid of & for second param
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