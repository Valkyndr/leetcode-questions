no := ''
override sourcename := $(no).h
override testname := tests/$(no).cpp

setup: catch.hpp catch.cpp
	g++ -std=c++11  catch.cpp -c -o catch.o	

test:  catch.o
	g++ -std=c++11 catch.o 33.h -o run_tests_33

solution:
	g++ -std=c++11 $(sourcename)  -o run
