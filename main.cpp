/**
 * Fall 2021 PA 04 - Node Planner Template Repo.
 * Based on PA 02 Template repo
 */

#include <iostream>
#include <fstream>

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "DSLinkedList.h"
#include "DSStack.h"
#include "Flight.h"
#include "DSString.h"
#include "OriginCity.h"
#include "FileManager.h"
#include "FlightPlanner.h"
#include "City.h"

using namespace std;

int main(int argc, char** argv) {
    //if(argc == 1) {
        //runCatchTests();
    //}
    //else {
        FileManager fileIO;
        DSLinkedList<OriginCity> adjacencyList;
        fileIO.readFlightData(argv[1], adjacencyList);
        cout << endl;
        adjacencyList.display();
        DSLinkedList<Flight> itinerary;
        DSVector<DSVector<DSString>> requests;
        fileIO.readRequestedFlights(argv[2], requests);
        FlightPlanner plans;
        plans.makeItinerary(requests, adjacencyList);

   //}
    return 0;
}