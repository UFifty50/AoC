CXXFLAGS = -Wall -Wextra -std=c++20 -g -O0
CXX = g++


.PHONY: all

all: day-1 day-2 day-3 day-4

day-1: day-1/day1.cpp
	cd day-1 && $(CXX) $(CXXFLAGS) -o day1 day1.cpp

day-2: day-2/day2.cpp
	cd day-2 && $(CXX) $(CXXFLAGS) -o day2 day2.cpp

day-3: day-3/day3.cpp
	cd day-3 && $(CXX) $(CXXFLAGS) -o day3 day3.cpp

day-4: day-4/day4.cpp
	cd day-4 && $(CXX) $(CXXFLAGS) -o day4 day4.cpp
