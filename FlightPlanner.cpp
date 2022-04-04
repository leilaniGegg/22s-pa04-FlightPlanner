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
            cout << "in else" << endl;

            //for connection in stack.top, is the connection null
            if(adjList.find(stack.peek()).destinations.getCurr() == nullptr){
                cout << "in second if" << endl;
                OriginCity temp = stack.peek();
                adjList.find(stack.peek()).destinations.resetIteratorFront();
                stack.pop();

                cout << "HERE" << endl;

                cout << "after stack.pop" << endl;
            }
             //is the connection on the stack?
             else {
                if (onStack(stack, adjList.find(stack.peek()).destinations.getCurr()->data)) {
                    cout << "in third if" << endl;
                    //move iterator and continue
                    adjList.find(stack.peek()).destinations.getNext();
                    //continue;
                } else {
                    //push connection, move iterator
                    cout << "in last else" << endl;
                    OriginCity temp(stack.peek());
                    stack.push(adjList.find(adjList.find(stack.peek()).destinations.getCurr()->data));
                    adjList.find(temp).destinations.getNext();
                    //continue;
                }
            }
        }
        cout << "exiting second else" << endl;
    }
    return paths;
}


void FlightPlanner::calculatePaths(const DSVector<DSString>& goals, DSLinkedList<OriginCity>& adjList){
    DSVector<DSStack<OriginCity>> paths = backtrack(goals.at(0), goals.at(1), adjList);
    //DSVector<DSStack<Flight>> routes = routing(paths);
    //return optimize(routes, goals.at(2));
    /*cout << "in here" << endl;
    OriginCity start(*adjlist.find(goals.at(0)));
    OriginCity end(*adjlist.find(goals.at(1)));
    OriginCity condition(*adjlist.find(goals.at(2))); //T for time, or C for cost
    DSStack<OriginCity> stack;
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
    } */
}

bool FlightPlanner::onStack (DSStack<OriginCity> stack, const City& element){ //get rid of & for second param
    cout << "in onStack" << endl;
    DSStack<OriginCity> tempStack;
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