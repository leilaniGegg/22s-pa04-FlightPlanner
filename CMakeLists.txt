cmake_minimum_required(VERSION 3.15)
project(22s_flight_planner)

set(CMAKE_CXX_STANDARD 14)

configure_file(data/sample01-flight-data.txt data/sample01-flight-data.txt COPYONLY)
configure_file(data/sample01-req-flights.txt data/sample01-req-flights.txt COPYONLY)

add_executable(22s_flight_planner main.cpp catch_setup.cpp sample_tests.cpp DSString.h DSString.cpp DSLinkedList.h Flight.cpp Flight.h DSStack.h DSLLTest.cpp OriginCity.cpp OriginCity.h City.cpp City.h FileManager.h FlightPlanner.cpp FlightPlanner.h DSStackTest.cpp)
