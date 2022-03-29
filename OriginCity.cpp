//
// Created by leila on 3/28/2022.
//

#include "OriginCity.h"

OriginCity::OriginCity(const DSString& temp){
    origin = temp;
}
DSString OriginCity::getOrigin(){
    return origin;
}