//
// Created by leila on 2/14/2022.
//
#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("DSVector class", "[vector]"){
    DSVector<DSString> test;
    test.push_back("Avocado");
    test.push_back("DSString");
    test.push_back("The moon");
    test.push_back("doggo");
    test.push_back("tissue");
    test.push_back("sharpie");
    test.push_back("Halloween");
    test.push_back("this is a sentence");
    test.push_back("random");
    test.push_back("google");
    test.push_back("past capacity");


    SECTION("MODIFIERS AND ACCESSORS") {
        //push_back is tested by the vector existing I guess
        REQUIRE((test.at(3) == "INSERTED"));
        REQUIRE((test.at(7) == "INSERTED2"));
        REQUIRE((test.at(9) == "INSERTED3"));
        test.removeAtIndex(3);
        test.removeAtIndex(6); // 6 instead of 7 to consider the offset
        test.removeAtIndex(7);
        REQUIRE((test[3] != "INSERTED"));
        REQUIRE((test[7] != "INSERTED2"));
        REQUIRE((test[9] != "INSERTED3"));
        REQUIRE((test.find("tissue") == 4));
        REQUIRE((test.find("doggo") == 3));
        REQUIRE((test.find("google") == 9));
        test.sort();
        REQUIRE((test.at(10) == "tissue")); //should be last element now
        REQUIRE((test.at(9) == "this is a sentence"));
        REQUIRE((test.at(8) == "The moon"));
    }

    SECTION("ACCESSORS"){
        REQUIRE((test.begin() == "Avocado"));
        REQUIRE((test.end() == "past capacity"));
        //this only way I could think to test hasNext and getNext
        cout << "Testing next functions" << endl << test.begin() << endl;
        while(test.hasNext()){
            cout << test.getNext() << endl;
        }
        DSVector<DSString> temp;
        REQUIRE((temp.isEmpty()));
    }

    SECTION("GETTERS AND PRINT FUNCTIONS"){
        REQUIRE((test.getSize() == 11));
        REQUIRE((test.getCapacity() == 20)); //size went over capacity once, so initial capacity of 10 should be doubled to 20
        //Not sure if or how these need testing
        cout << endl << "Printing elements per line" << endl;
        test.displayNewLine();
        cout << endl << "Printing elements seperated by comma" << endl;
        test.displayComma();
    }
}