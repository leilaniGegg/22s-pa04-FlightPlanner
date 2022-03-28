//
// Created by leila on 3/22/2022.
//

#include "Flight.h"

Flight::Flight(){
    startCity = "baka";
    endCity = "chan";
    airline = "nani";
    cost = 69;
    time = 420;
}

Flight::Flight(DSString s, DSString e, DSString a, int c, int t){
    startCity = s;
    endCity = e;
    airline = a;
    cost = c;
    time = t;
}

Flight::~Flight(){

}

Flight::Flight(const Flight& temp){
    this->startCity = temp.startCity;
    this->endCity = temp.endCity;
    this->airline = temp.airline;
    this->cost = temp.cost;
    this->time = temp.time;
}

Flight& Flight::operator=(const Flight& temp){
    this->startCity = temp.startCity;
    this->endCity = temp.endCity;
    this->airline = temp.airline;
    this->cost = temp.cost;
    this->time = temp.time;
    return *this;
}

DSString& Flight::getStart(){
    return startCity;
}

DSString& Flight::getEnd(){
    return endCity;
}
DSString& Flight::getAirline(){
    return airline;
}

int Flight::getCost(){
    return cost;
}

int Flight::getTime(){
    return time;
}

ostream& operator<<(ostream& output, const Flight& temp){
    output << "Starting City: " << temp.startCity << endl;
    output << "Ending City: " << temp.endCity << endl;
    output << "Airline: " << temp.airline << endl;
    output << "Cost: $" << temp.cost << endl;
    output << "Time: " << temp.time << endl;
    return output;
}
