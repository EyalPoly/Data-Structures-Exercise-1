#pragma once

#include "City.h"
#include <iostream>
#include <vector>

class State {
public:
	// This class is a linked list of cities
	class HighWay {
		City* head;
		City* tail;
	public:
		// Empty ctor
		HighWay() { head = tail = nullptr; }
		// Create new empty HighWay of citie's roads
		void makeEmpty() { head = tail = nullptr; }
		// Check is the highway list is empty
		bool isEmpty() { return head == nullptr; }
		// Return the head of the list
		City* getHead() { return head; }
		// Create new city and insert it to the end of the list
		void insertToTail(int cityNumber);
		// Delete the HighWay list
		void deleteHighWay();
		friend class State;
	};
private:
	int citiesNumber;
	int roadsNumber;
	HighWay* roadSystem;
public:
	// Ctor
	State(std::vector<int> citiesAndRoadsNumber): citiesNumber(citiesAndRoadsNumber[0]), roadsNumber(citiesAndRoadsNumber[1]) {}
	// Return the roadSystem array
	HighWay* getRoadSystem() const { return roadSystem; }
	// Initialize the highway lists, inserting the heads
	void initializeHighWays();
	// Create the RoadSystem array of HighWays
	void createRoadSystem(std::vector<int> const roads);
	// Delete the roadSystem array
	void deleteState();
	// Print the state structure for testing
	void print() const;
};

