//
// Created by leila on 3/28/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_FILEMANAGER_H
#define INC_22S_FLIGHT_PLANNER_FILEMANAGER_H

#include "OriginCity.h"
#include "DSString.h"
#include "City.h"

class FileManager{
public:
    void readFlightData(const DSString& filename, DSLinkedList<OriginCity>& adjList); //basically make adjacency list
    void readRequestedFlights(const DSString& filename, DSVector<DSVector<DSString>>& requests);
};

void FileManager::readFlightData(const DSString& filename, DSLinkedList<OriginCity>& adjList){
    ifstream file;
    file.open(filename.c_str());
    if(!file.is_open()){
        cout << "Failed to open file." << endl;
    }
    else{
        char line[500];
        file.getline(line, 500); // trash the first line
        while(file.getline(line, 500)) {
            if(*line != NULL) {
                DSString newLine(line);
                /// format = {[origin] , [end], [cost], [time], [airline]}
                DSVector<DSString> temp = newLine.parseLine(" ");
                /**
                 * These are the flight information from the input file
                 * temp.at(0) = origin city
                 * temp.at(1) = end city
                 * temp.at(2) = cost
                 * temp.at(3) = time
                 * temp.at(4) = airline
                 */
                ///If the first city listed is already in adjacent list, add its ending city to destination list
                if(adjList.exists(temp.at(0))) {
                    City dest(temp.at(1), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    if(adjList.find(temp.at(0)).destinations.exists(dest)){
                        adjList.find(temp.at(0)).destinations.find(dest).getAirline().push_back(temp.at(4));
                        adjList.find(temp.at(0)).destinations.find(dest).getTime().push_back(atoi(temp.at(3).c_str())); //not sure about these two lines
                        adjList.find(temp.at(0)).destinations.find(dest).getCost().push_back(atoi(temp.at(2).c_str()));
                    }
                    else {
                        adjList.find(temp.at(0)).destinations.push_back(dest);
                    }
                    adjList.find(temp.at(0)).destinations.resetIteratorFront();
                }
                ///if not, then add city to adjacency list and add its ending city to destination list
                else{
                    OriginCity origin(temp.at(0)); //create origin city since its not already in adjlist
                    adjList.push_back(origin);
                    City dest(temp.at(1), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    if(adjList.find(temp.at(0)).destinations.exists(dest)){
                        adjList.find(temp.at(0)).destinations.find(dest).getAirline().push_back(temp.at(4));
                        adjList.find(temp.at(0)).destinations.find(dest).getTime().push_back(atoi(temp.at(3).c_str()));
                        adjList.find(temp.at(0)).destinations.find(dest).getCost().push_back(atoi(temp.at(2).c_str()));

                    }
                    else {
                        adjList.find(origin).destinations.push_back(dest);
                    }
                    adjList.find(temp.at(0)).destinations.resetIteratorFront();
                }
                ///if the end city is in the adjlist as an origin city
                if(adjList.exists(temp.at(1))){
                    City dest(temp.at(0), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    if(adjList.find(temp.at(1)).destinations.exists(dest)){
                        adjList.find(temp.at(1)).destinations.find(dest).getAirline().push_back(temp.at(4));
                        adjList.find(temp.at(1)).destinations.find(dest).getTime().push_back(atoi(temp.at(3).c_str()));
                        adjList.find(temp.at(1)).destinations.find(dest).getCost().push_back(atoi(temp.at(2).c_str()));
                    }
                    else {
                        adjList.find(temp.at(1)).destinations.push_back(dest);
                    }
                    adjList.find(temp.at(1)).destinations.resetIteratorFront();
                }
                else{
                    OriginCity origin(temp.at(1));
                    adjList.push_back(origin);
                    City dest(temp.at(0), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    if(adjList.find(temp.at(1)).destinations.exists(dest)){
                        adjList.find(temp.at(1)).destinations.find(dest).getAirline().push_back(temp.at(4));
                        adjList.find(temp.at(1)).destinations.find(dest).getTime().push_back(atoi(temp.at(3).c_str()));
                        adjList.find(temp.at(1)).destinations.find(dest).getCost().push_back(atoi(temp.at(2).c_str()));
                    }
                    else {
                        adjList.find(origin).destinations.push_back(dest);
                    }
                    adjList.find(temp.at(1)).destinations.resetIteratorFront();
                }
            }
        }
    }
    file.close();
}

void FileManager::readRequestedFlights(const DSString& filename, DSVector<DSVector<DSString>>& requests){
    ifstream file;
    file.open(filename.c_str());
    if(!file.is_open()){
        cout << "Failed to open file." << endl;
    }
    else {
        char line[500];
        file.getline(line, 500); // trash the first line
        while (file.getline(line, 500)) {
            if (*line != NULL) {
                DSVector<DSString> entries = DSString(line).parseLine(" "); //not sure if this syntax works
                requests.push_back(entries);
            }
        }
    }
    file.close();

}
#endif //INC_22S_FLIGHT_PLANNER_FILEMANAGER_H
