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
    int size = 0;
    Node<T>* itr;

public:
    DSLinkedList();
    DSLinkedList(const DSLinkedList<T>&);
    ~DSLinkedList();
    DSLinkedList& operator=(const DSLinkedList<T>& list);
    void push_back(T element);
    void push_front(T element);
    T pop_front();
    T pop_back();
    T& peek_front()const;
    T& peek_back()const;
    void insert(T element, int index);
    int getSize()const;
    void getNext();
    void getPrev();
    Node<T>* getCurr();
    bool hasNext();
    bool hasPrev();
    Node<T>* begin();
    Node<T>* end();
    void resetIteratorFront();
    void resetIteratorBack();
};

template<typename T>
DSLinkedList<T>::DSLinkedList(){
    //size = 0;
    head = nullptr;
    tail = nullptr;
    itr = head;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T>& temp){
    if(temp.head == nullptr){
        head = nullptr;
        tail = nullptr;
        return;
    }
    else {
        head = nullptr;
        tail = nullptr;
        Node<T>* curr = temp.head;
        while (curr != nullptr) {
            Node<T> *newNode = new Node<T>;
            newNode->data = curr->data;
            newNode->prev = this->tail;
            newNode->next = nullptr;
            if (this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                this->itr = this->head;
            } else {
                this->tail->next = newNode;
                this->tail = newNode;
            }
            size++;
            curr = curr->next;
        }
    }
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
DSLinkedList<T>& DSLinkedList<T>::operator=(const DSLinkedList<T>& temp){
    if(temp.head == nullptr){
        head = nullptr;
        tail = nullptr;
        return *this;
    }
    else {
        head = nullptr;
        tail = nullptr;
        Node<T>* curr = temp.head;
        while (curr != nullptr) {
            Node<T> *newNode = new Node<T>;
            newNode->data = curr->data;
            newNode->prev = this->tail;
            newNode->next = nullptr;
            if (this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                this->itr = this->head;
            } else {
                this->tail->next = newNode;
                this->tail = newNode;
            }
            size++;
            curr = curr->next;
        }
    }
    return *this;
}

/**
 * ITERATOR FUNCTIONS
 */
template <typename T>
void DSLinkedList<T>::getNext(){
    itr = itr->next;
}

template <typename T>
void DSLinkedList<T>::getPrev(){
    itr = itr->prev;
}

template <typename T>
Node<T>* DSLinkedList<T>::getCurr(){
    return itr;
}

template <typename T>
bool DSLinkedList<T>::hasNext(){
    if(itr->next != nullptr){
        return true;
    }
    return false;
}

template <typename T>
bool DSLinkedList<T>::hasPrev(){
    if(itr->prev != nullptr){
        return true;
    }
    return false;
}

template <typename T>
Node<T>* DSLinkedList<T>::begin(){
    return head;
}

template <typename T>
Node<T>* DSLinkedList<T>::end(){
    return tail;
}

template <typename T>
void DSLinkedList<T>::resetIteratorFront(){
    itr = head;
}

template <typename T>
void DSLinkedList<T>::resetIteratorBack(){
    itr = tail;
}


/**
 * MODIFIERS AND ACCESORS
 */
template <typename T>
void DSLinkedList<T>::push_back(T element){
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->prev = tail;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        itr = head;
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
        itr = head;
    } else {
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

template <typename T>
T DSLinkedList<T>::pop_front(){
    if(size == 0){
        cout << "LinkedList is empty" << endl;
        return;
    }
    else{
        Node<T>* front = new Node<T>;
        T removedValue = head->data;
        head = head->next;
        delete front;
        size--;
        return removedValue;
    }

}

template <typename T>
T DSLinkedList<T>::pop_back(){
    if(size == 0){
        cout << "LinkedList is empty" << endl;
        return;
    }
    else{
        Node<T>* back = new Node<T>;
        T removedValue = tail->data;
        tail = tail->prev;
        delete back;
        size--;
        return removedValue;
    }
}

template <typename T>
T& DSLinkedList<T>::peek_front()const{
    return head->data;
}

template <typename T>
T& DSLinkedList<T>::peek_back()const{
    return tail->data;
}
template <typename T>
int DSLinkedList<T>::getSize()const{
    return size;
}

#endif //INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

