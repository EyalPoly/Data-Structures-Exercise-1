#pragma once

#include "State.h"
#include <vector>

class City;

class AccessibleList {
	std::vector<City> arr;
	int headList = -1;
	int headFree = 0;
	int tailList = -1;
	int arrSize;
public:
	//Ctor
	AccessibleList(int citiesNumber) ;
	// Insert new city to the list
	void insertCity(int cityNumber);
	// Prints the accessible list
	void print(int focalCity, bool isRec);
};

