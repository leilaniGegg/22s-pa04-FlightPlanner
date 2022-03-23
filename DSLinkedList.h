//
// Created by leila on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

#include "Node.h"

template <typename T>
class DSLinkedList{
private:
    T* head;
    T* tail;
    int size;

public:
    DSLinkedList();
    DSLinkedList(const DSLinkedList<T>&);
    ~DSLinkedList();
    DSLinkedList& operator=(const DSLinkedList<T>& list);
    void push_back(T element);
    void push_front(T element);
    T pop_front();
    T pop_back();
    void insert(T element, int index);
};
#endif //INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

template<typename T>
DSLinkedList<T>::DSLinkedList(){
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T>&){

}

template<typename T>
DSLinkedList<T>& DSLinkedList<T>::operator=(const DSLinkedList<T>& list){

}

template <typename T>
void DSLinkedList<T>::push_back(T element){
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    newNode->prev = tail;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

template<typename T>
void DSLinkedList<T>::push_front(T element){
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }

    size++;
}