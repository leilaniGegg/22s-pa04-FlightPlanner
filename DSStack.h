//
// Created by leila on 3/25/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSSTACK_H
#define INC_22S_FLIGHT_PLANNER_DSSTACK_H

#include "DSLinkedList.h"

template <typename T>
class DSStack{
private:
    DSLinkedList<T> list;

public:
    DSStack();
    ~DSStack();
    T& push(T element); // add elements to top of the stack/end of linked list
    T& pop();           //remove the top of the stack/end of linked list
    T& peek()const;     //look at the top of the stack/end of linked list
};
template <typename T>
DSStack<T>::DSStack(){
    list = new DSLinkedList<T>;
}

template <typename T>
DSStack<T>::~DSStack(){
    delete list;
}

template <typename T>
T& DSStack<T>::push(T element){
    list.push_back(element);
}

template <typename T>
T& DSStack<T>::pop(){
    return list.pop_back();
}

template <typename T>
T& DSStack<T>::peek()const{
    return list.peek_back();
}
#endif //INC_22S_FLIGHT_PLANNER_DSSTACK_H