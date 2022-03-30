//
// Created by leila on 3/28/2022.
//

#include "City.h"
City::City(const DSString& endCity, int cost, int time, const DSString& airline){
    this->endCity = endCity;
    this->airline = airline;
    this->cost = cost;
    this->time = time;
}
City::~City(){
}

City::City(const City& temp){
    this->endCity = temp.endCity;
    this->airline = temp.airline;
    this->cost = temp.cost;
    this->time = temp.time;
}

City& City::operator=(const City& temp){
    this->endCity = temp.endCity;
    this->airline = temp.airline;
    this->cost = temp.cost;
    this->time = temp.time;
    return *this;
}

bool City::operator==(City& temp){
    if(this->endCity == temp.getEndCity() && this->airline == temp.getAirline() &&
       this->cost == temp.getCost() && this->time == temp.getTime()){
        return true;
    }
    return false;
}
DSString City::getEndCity(){
    return endCity;
}
DSString City::getAirline(){
    return airline;
}
int City::getCost()const{
    return cost;
}
int City::getTime()const{
    return time;
}