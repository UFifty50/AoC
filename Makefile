CXXFLAGS = -Wall -Wextra -std=c++20 -g -O0
CXX = g++


.PHONY: all

all: day-1 day-2

day-1: day-1/day1.cpp
	cd day-1 && $(CXX) $(CXXFLAGS) -o day1 day1.cpp

day-2: day-2/day2.cpp
	cd day-2 && $(CXX) $(CXXFLAGS) -o day2 day2.cpp
