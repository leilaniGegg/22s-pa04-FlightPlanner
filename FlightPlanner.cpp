//
// Created by leila on 3/31/2022.
//

#include "FlightPlanner.h"

void FlightPlanner::makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList){
    for(int i = 0; i < req.getSize(); i++){
        itinerary.push_back(calculatePaths(req.at(i), adjList));
    }
}

DSLinkedList<Flight> FlightPlanner::calculatePaths(DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList){
    DSString start = goals.at(0);
    DSString end = goals.at(1);
    DSString condition = goals.at(2); //T for time, or C for cost
    DSStack<DSString> stack;
    adjList.resetIteratorFront();
    stack.push(start); //push source to stack
    while(!stack.isEmpty()){ //while stack is not empty
        if(stack.peek() == end){ //if the stack top is the destination
            //store the path and pop the top of stack

        }
        else{
            //might need to add code to rest itr in destintions list
            //for connection in stack.top, is the connection null
            if(adjList.find(stack.peek()).destinations.getCurr() == nullptr){
                stack.pop();
                adjList.find(stack.peek()).destinations.resetIteratorFront();
            }
            //is the connection on the stack?
            if(onStack(stack,adjList.find(stack.peek()).destinations.getCurr()->data.getEndCity())){
                adjList.find(stack.peek()).destinations.getNext();
                continue;
            }
            else{
                stack.push(adjList.find(stack.peek()).destinations.getCurr()->data.getEndCity());
            }
        }

    }

}

bool FlightPlanner::onStack (DSStack<DSString> stack, DSString element){
    DSStack<DSString> tempStack;
    tempStack.push(stack.pop());
    while(!stack.isEmpty()) {
        if (tempStack.push(stack.pop()) == element) {
            return true;
        }
    }
    return false;

}