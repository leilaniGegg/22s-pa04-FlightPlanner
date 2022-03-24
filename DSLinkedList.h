//
// Created by leila on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class DSLinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
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

template<typename T>
DSLinkedList<T>::DSLinkedList(){
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T>&){

}

template <typename T>
DSLinkedList<T>::~DSLinkedList(){
    Node<T>* temp = head;
    while(temp != nullptr ) {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
    }
}

template<typename T>
DSLinkedList<T>& DSLinkedList<T>::operator=(const DSLinkedList<T>& list){

}

template <typename T>
void DSLinkedList<T>::push_back(T element){
    Node<T>* newNode = new Node<T>();
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
    Node<T>* newNode = new Node<T>();
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

template <typename T>
T DSLinkedList<T>::pop_front(){
    return head->data; // not sure if it needs *
}

template <typename T>
T DSLinkedList<T>::pop_back(){
    return tail->data;
}

#endif //INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

