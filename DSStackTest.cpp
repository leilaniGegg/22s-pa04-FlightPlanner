//
// Created by leila on 4/1/2022.
//

#include "catch.hpp"
#include "DSStack.h"
#include "DSString.h"
#include "DSLinkedList.h"

TEST_CASE("DSSTACK TESTS", "[stack]"){
    DSStack<DSString> stack;
    stack.push("Houston");
    stack.push("Dallas");
    stack.push("New York");
    stack.push("Seattle");

    SECTION("PUSH"){
        //pretty much tested from ^^^
    }
    SECTION("PEEK and POP"){
        REQUIRE((stack.peek() == "Seattle"));
        stack.pop();
        REQUIRE((stack.peek() == "New York"));
        stack.pop();
        REQUIRE((stack.peek() == "Dallas"));
        stack.pop();
        REQUIRE((stack.peek() == "Houston"));
    }
}