#pragma once

#include "City.h"
#include <iostream>

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
	// Return the number of cities
	int getCitiesNumber() { return citiesNumber; };
	// Set the cities number
	void setCitiesNumber() { std::cin >> citiesNumber; }
	// Set the roads number
	void setRoadsNumber() { std::cin >> roadsNumber; }
	// Create the RoadSystem array of HighWays
	void createRoadSystem();
	// Delete the roadSystem array
	void deleteState();
	// Print the state structure for testing
	void print();
};

