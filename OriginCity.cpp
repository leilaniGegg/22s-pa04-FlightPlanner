//
// Created by leila on 3/28/2022.
//

#include "OriginCity.h"

OriginCity::OriginCity(){
    destinations.resetIteratorFront();
}

OriginCity::OriginCity(const DSString& temp){
    origin = temp;
}

OriginCity::OriginCity(const City& temp){
    origin = temp.getEndCity();
}

OriginCity::~OriginCity(){
}

bool OriginCity::operator==(const OriginCity& temp){
    if(this->origin == temp.getOrigin()){
        return true;
    }
    return false;
}

bool OriginCity::operator==(const City& temp){
    if(this->origin == temp.getEndCity()){
        return true;
    }
    return false;
}

OriginCity& OriginCity::operator=(const OriginCity& temp){
    this->origin = temp.getOrigin();
    this->destinations = temp.destinations;
    return *this;
}

DSString OriginCity::getOrigin()const{
    return origin;
}

ostream& operator<<(ostream& output, OriginCity& temp){
    cout << temp.getOrigin() << ": ";
    temp.destinations.display();
    return output;
}