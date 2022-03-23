//
// Created by leila on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_NODE_H
#define INC_22S_FLIGHT_PLANNER_NODE_H
#include "DSString.h"

template <typename T>
class Node{
public:
    T data;
    Node* next;
    Node* prev;
};
#endif //INC_22S_FLIGHT_PLANNER_NODE_H