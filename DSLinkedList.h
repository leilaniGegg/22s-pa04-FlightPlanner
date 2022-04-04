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
    void pop_front();
    void pop_back();
    T& peek_front()const;
    T& peek_back()const;
    void insert(T element, int index);
    T& find(const T& element);
    bool exists(const T& element);
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
    void display();
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
    this->itr = nullptr;
    Node<T>* temp = this->head;
    Node<T>* next;
    while(temp != nullptr ){
        next = temp->next;
        delete temp;
        temp = next;
    }
    size = 0;
}

template<typename T>
DSLinkedList<T>& DSLinkedList<T>::operator=(const DSLinkedList<T>& temp){
    if(temp.head == nullptr){
        head = nullptr;
        tail = nullptr;
        return *this;
    }
    else {
        this->head = nullptr;         //comment these out
        this->tail = nullptr;
        size = temp.getSize();
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

    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
        itr = head;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }
    size++;
}

template<typename T>
void DSLinkedList<T>::push_front(T element){
    Node<T>* newNode = new Node<T>();
    newNode->data = element;
    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
        itr = head;
    } else {
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }
    size++;
}

template <typename T>
void DSLinkedList<T>::pop_front(){
    if(size == 0){
        cout << "LinkedList is empty" << endl;
    }
    else if(size == 1){
        Node<T>* front = front;
        head = nullptr;
        tail = nullptr;
        delete front;
        size--;
    }
    else{
        Node<T>* front = head;
        head = front->next;
        head->prev = nullptr;
        delete front;
        size--;
    }
}

template <typename T>
void DSLinkedList<T>::pop_back(){
    if(size == 0){
        cout << "LinkedList is empty" << endl;
    }
    else if(size == 1){
        Node<T>* back = tail;
        head = nullptr;
        tail = nullptr;
        delete back;
        size--;
    }
    else{
        Node<T>* back = tail;
        tail = back->prev;
        tail->next = nullptr;
        delete back;
        size--;
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
T& DSLinkedList<T>::find(const T& element){
    this->resetIteratorFront();
    while(this->getCurr() != nullptr){
        if(this->getCurr()->data == element){
            return this->getCurr()->data;
        }
        this->getNext();
    }
}

template <typename T>
bool DSLinkedList<T>::exists(const T& element){
    if(this->getSize() == 0){
        return false;
    }
    this->resetIteratorFront();
    while(this->getCurr() != nullptr){
        if(this->getCurr()->data == element){
            return true;
        }
        this->getNext();
    }
    return false;
}

template <typename T>
int DSLinkedList<T>::getSize()const{
    return size;
}

template <typename T>
void DSLinkedList<T>::display(){
    this->resetIteratorFront();
    while(this->getCurr() != nullptr){
        cout << this->getCurr()->data << endl;
        this->getNext();
    }
    this->resetIteratorFront();
}

#endif //INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

