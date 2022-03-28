//
// Created by leila on 3/25/2022.
//
#include "catch.hpp"
#include "DSString.h"
#include "DSLinkedList.h"

TEST_CASE("DSLINKEDLIST TESTS", "[list]"){
    DSLinkedList<DSString> list;
    SECTION("PUSH_BACK and PEEK"){
        list.push_back("Dallas");
        list.push_back("Austin");
        list.push_back("Seattle");
        list.push_back("Chicago");
        list.push_back("Denver");
    }
}