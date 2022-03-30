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
    void readFlightData(const DSString& filename, DSLinkedList<OriginCity>& adjList);
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
                DSVector<DSString> temp = newLine.parseLine(" ");
                temp.displayComma();
                //OriginCity origin(temp.at(0)); //create origin city with first word from each line
                if(adjList.exists(temp.at(0))) {
                    cout << temp.at(0) << "already exists in adjlist" << endl;
                    City dest(temp.at(1), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    cout << "destination city added: " <<  dest << endl;
                    adjList.find(temp.at(0)).destinations.push_back(dest);

                }
                else{
                    OriginCity origin(temp.at(0)); //create origin city since its not already in adjlist
                    adjList.push_back(origin);
                    cout << "Adding " << origin.getOrigin() << " to adjlist" << endl;
                    City dest(temp.at(1), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    cout << "destination city added: " << dest << endl;
                    adjList.find(origin).destinations.push_back(dest);
                }
                //if the end city is in the adjlist as an origin city
                if(adjList.exists(temp.at(1))){
                    cout << temp.at(1) << " (end city) already exists in adjlist" << endl;
                    City dest(temp.at(0), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    cout << "destination city added: " << dest << endl;
                    adjList.find(temp.at(1)).destinations.push_back(dest);

                }
                else{
                    OriginCity origin(temp.at(1));
                    adjList.push_back(origin);
                    cout << "Adding " << temp.at(1) << " to adjlist" << endl;
                    City dest(temp.at(0), atoi(temp.at(2).c_str()), atoi(temp.at(3).c_str()), temp.at(4));
                    cout << "destination city added: " << dest << endl;
                    adjList.find(origin).destinations.push_back(dest);

                }
            }
        }
    }
    file.close();
}
#endif //INC_22S_FLIGHT_PLANNER_FILEMANAGER_H
