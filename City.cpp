//
// Created by leila on 3/28/2022.
//

#include "City.h"

City::City(){

}
City::City(const DSString& endCity, int cost, int time, const DSString& airline){
    this->endCity = endCity;
    //this->airline = airline;
    airlines.push_back(airline);
    //this->cost = cost;
    costs.push_back(cost);
    //this->time = time;
    times.push_back(time);
}
City::~City(){
}

City::City(const City& temp){
    this->endCity = temp.endCity;
    this->airlines = temp.airlines;
    this->costs = temp.costs;
    this->times = temp.times;
}

City& City::operator=(const City& temp){
    this->endCity = temp.endCity;
    this->airlines = temp.airlines;
    this->costs = temp.costs;
    this->times = temp.times;
    return *this;
}

bool City::operator==(const City& temp){
    /*if(this->endCity == temp.getEndCity() && this->airline == temp.getAirline() &&
       this->cost == temp.getCost() && this->time == temp.getTime()){
        return true;
    }*/
    if(this->endCity == temp.getEndCity()){
        return true;
    }
    return false;
}

/*bool City::operator==(const DSString& temp){
    if(this->endCity == temp){
        return true;
    }
    return false;
}*/

DSString City::getEndCity()const{
    return endCity;
}
DSVector<DSString>& City::getAirline(){
    return airlines;
}
DSVector<int>& City::getCost(){
    return costs;
}
DSVector<int>& City::getTime(){
    return times;
}

ostream& operator<<(ostream& output, const City& temp){
    cout << temp.endCity << ", ";
    return output;
}