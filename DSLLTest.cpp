//
// Created by leila on 3/25/2022.
//
#include "catch.hpp"
#include "DSString.h"
#include "DSLinkedList.h"

TEST_CASE("DSLINKEDLIST TESTS", "[list]"){
    DSLinkedList<DSString> list1;
    list1.push_back("Dallas");
    list1.push_back("Austin");
    list1.push_back("Seattle");
    list1.push_back("Chicago");
    list1.push_back("Denver");

    DSLinkedList<DSString> list2;
    list2.push_front("Dog");
    list2.push_front("Cat");
    list2.push_front("Snake");
    list2.push_front("Bird");
    list2.push_front("Fish");


    SECTION("PEEK"){
        REQUIRE((list1.peek_back() == "Denver"));
        REQUIRE((list1.peek_front() == "Dallas"));
        list1.push_front("Boston");
        list1.push_back("Miami");
        REQUIRE((list1.peek_front() == "Boston"));
        REQUIRE((list1.peek_back() == "Miami"));

        REQUIRE((list2.peek_back() == "Dog"));
        REQUIRE((list2.peek_front() == "Fish"));
        list2.push_front("Lizard");
        list2.push_back("Rat");
        REQUIRE((list2.peek_front() == "Lizard"));
        REQUIRE((list2.peek_back() == "Rat"));
    }

    SECTION("POP"){
        list1.pop_back();
        list1.pop_front();
        REQUIRE((list1.peek_back() == "Chicago"));
        REQUIRE((list1.peek_front() == "Austin"));
        list1.pop_back();
        list1.pop_front();
        REQUIRE((list1.peek_back() == "Seattle"));
        REQUIRE((list1.peek_front() == "Seattle"));

        list2.pop_back();
        list2.pop_front();
        REQUIRE((list2.peek_back() == "Cat"));
        REQUIRE((list2.peek_front() == "Bird"));
        list2.pop_back();
        list2.pop_front();
        REQUIRE((list2.peek_back() == "Snake"));
        REQUIRE((list2.peek_front() == "Snake"));
    }

    SECTION("GETSIZE"){
        REQUIRE((list1.getSize() && list2.getSize() == 5));
        list1.pop_back();
        list2.push_back("Ferret");
        REQUIRE((list1.getSize() == 4));
        REQUIRE((list2.getSize() == 6));
    }

    DSLinkedList<DSLinkedList<DSString>> listOflists;
    listOflists.push_back(list1);
    listOflists.push_back(list2);
    SECTION("Same Functions on LinkedList of LinkedLists"){
        REQUIRE((listOflists.getSize() == 2));
        REQUIRE((listOflists.peek_back().peek_front() == "Fish"));
        REQUIRE((listOflists.peek_back().peek_back() == "Dog"));
        REQUIRE((listOflists.peek_front().peek_front() == "Dallas"));
        REQUIRE((listOflists.peek_front().peek_back() == "Denver"));
        listOflists.pop_back();
        REQUIRE((listOflists.getSize() == 1));
        REQUIRE((listOflists.peek_front().peek_front() == "Dallas"));
    }

}