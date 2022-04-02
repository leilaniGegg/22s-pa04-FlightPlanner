//
// Created by leila on 3/31/2022.
//

#include "FlightPlanner.h"

void FlightPlanner::makeItinerary(const DSVector<DSVector<DSString>>& req, DSLinkedList<OriginCity>& adjList){
    for(int i = 0; i < req.getSize(); i++){
        itinerary.push_back(calculatePaths(req.at(i), adjList));
    }
}

DSLinkedList<Flight> FlightPlanner::calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList){
    cout << "in here" << endl;
    DSString start(goals.at(0));
    DSString end(goals.at(1));
    DSString condition(goals.at(2)); //T for time, or C for cost
    DSStack<DSString> stack;
    cout <<"mmade stack " << endl;
    adjList.resetIteratorFront();
    cout << "reset iterator" << endl;
    stack.push(start); //push source to stack
    cout << "pushed to stack" << endl;
    while(!stack.isEmpty()){ //while stack is not empty
        cout << "in main while" << endl;
        if(stack.peek() == end){ //if the stack top is the destination
            //store the path and pop the top of stack
            DSLinkedList<Flight> path;
            cout <<"Path: " << stack.peek() << endl;
            //return storePath()
            stack.pop();
        }
        else{
            cout << "in else" << endl;
            //might need to add code to rest itr in destinations list

            //for connection in stack.top, is the connection null
            if(adjList.find(stack.peek()).destinations.getCurr() == nullptr){
                cout << "in second if" << endl;
                adjList.find(stack.peek()).destinations.resetIteratorFront();
                cout << "HERE" << endl;
                stack.pop();
                cout << "after stack.pop" << endl;
            }
            //is the connection on the stack?
            if(onStack(stack, adjList.find(stack.peek()).destinations.getCurr()->data.getEndCity())){
                cout << "in third if" << endl;
                //move iterator and continue
                adjList.find(stack.peek()).destinations.getNext();
                continue;
            }
            else{
                //push connection, move iterator
                cout << "in last else" << endl;
                stack.push(adjList.find(stack.peek()).destinations.getCurr()->data.getEndCity());
                adjList.find(stack.peek()).destinations.getNext();
                continue;
            }
        }
        cout << "exiting second else" << endl;
    }
}

bool FlightPlanner::onStack (DSStack<DSString> stack, const DSString& element){ //get rid of & for second param
    cout << "in onStack" << endl;
    DSStack<DSString> tempStack;
    //tempStack.push(stack.pop());
    while(!stack.isEmpty()) {
        cout << "in while " << endl;
        tempStack.push(stack.peek());
        stack.pop();
        if (tempStack.peek() == element) {
            cout << "in if" << endl;
            return true;
        }
    }
    cout << "leaving onstack" << endl;
    return false;

}