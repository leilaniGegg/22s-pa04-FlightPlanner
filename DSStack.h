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
    DSStack(const DSStack& temp);
    ~DSStack();
    DSStack& operator=(const DSStack<T>& temp);
    void push(T element); // add elements to top of the stack/end of linked list
    void pop();           //remove the top of the stack/end of linked list
    T& peek()const;     //look at the top of the stack/end of linked list
    bool isEmpty();
    DSLinkedList<T>& getList();
    //friend ostream& operator<<(ostream& output, DSStack<T>& temp);

};
template <typename T>
DSStack<T>::DSStack(){
}

template <typename T>
DSStack<T>::~DSStack(){
}

template <typename T>
DSStack<T>& DSStack<T>::operator=(const DSStack<T>& temp){
    this->list = temp.list;
    return *this;
}

template <typename T>
DSStack<T>::DSStack(const DSStack& temp){
    this->list = temp.list;
}

template <typename T>
void DSStack<T>::push(T element){
    list.push_back(element);
}

template <typename T>
void DSStack<T>::pop(){
    list.pop_back();
}

template <typename T>
T& DSStack<T>::peek()const{
    return list.peek_back();
}

template <typename T>
bool DSStack<T>::isEmpty(){
    if(list.getSize() == 0){
        return true;
    }
    return false;
}

template <typename T>
DSLinkedList<T>& DSStack<T>::getList(){
    return list;
}

/*template <typename T>
ostream& operator<<(ostream& output, DSStack<T>& temp){
    output << temp.getList << endl;
    return output;
}*/
#endif //INC_22S_FLIGHT_PLANNER_DSSTACK_H