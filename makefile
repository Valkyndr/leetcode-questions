no := ''
override sourcename := $(no).cpp
override headername := $(no).hpp
override testname := tests/$(no).cpp

setup: tests/catch.hpp tests/setup.cpp
	g++ -std=c++11  tests/setup.cpp  -c -o catch.o -I/tests

test:  catch.o
	g++ -std=c++11 catch.o tests/$(sourcename) -I.  -o test	

solution:
	g++ -std=c++11 $(sourcename)  -o run
