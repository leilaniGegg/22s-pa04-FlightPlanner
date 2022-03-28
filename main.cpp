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

using namespace std;

int main(int argc, char** argv) {
    //if(argc == 1) {
        //runCatchTests();
    //}
    //else {
        Flight A;
        Flight B("Dallas", "Austin", "American", 34, 5);
        Flight C("ugly", "idiot", "cat", 50, 13);
        DSLinkedList<Flight> test;
        test.push_back(A);
        test.push_back(B);
        test.push_back(C);

        DSStack<DSString> testStack;
        testStack.push("Cloud");
        testStack.push("Sun");
        testStack.push("Rain");
        cout << testStack.peek() << endl;
        testStack.pop();
        cout << testStack.peek() << endl;

   //}
    return 0;
}


//from input file, make the adjaceny list