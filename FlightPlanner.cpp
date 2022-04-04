//
// Created by leila on 3/31/2022.
//

#include "FlightPlanner.h"

void FlightPlanner::makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList){
    //for(int i = 0; i < req.getSize(); i++){

        calculatePaths(req.at(0), adjList);
    //}
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


void FlightPlanner::calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList){
    DSVector<DSStack<OriginCity>> paths = backtrack(goals.at(0), goals.at(1), adjList);
    paths.at(0).getList().display();
    paths.at(1).getList().display();

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