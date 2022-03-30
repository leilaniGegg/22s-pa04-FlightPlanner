//
// Created by leila on 3/28/2022.
//

#include "OriginCity.h"

OriginCity::OriginCity(const DSString& temp){
    origin = temp;
}

bool OriginCity::operator==(const OriginCity& temp){
    if(this->origin == temp.getOrigin()){
        return true;
    }
    return false;
}

OriginCity& OriginCity::operator=(const OriginCity& temp){
    this->origin = temp.getOrigin();
    return *this;
}

DSString OriginCity::getOrigin()const{
    return origin;
}