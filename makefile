no := ''
override no := $(no).cpp

setup: catch.hpp catch.cpp
	g++ -std=c++11  catch.cpp -c -o catch.o	

33: 33.cpp catch.o
	g++ -std=c++11 catch.o 33.cpp -o run_tests_33

solution:
	g++ -std=c++11 $(no)  -o run
