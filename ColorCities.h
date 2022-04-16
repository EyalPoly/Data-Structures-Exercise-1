#pragma once

#include <vector>

class ColorCities {
	int citiesNumber;
	std::vector<int> arr;
public:
	// Ctor, initialize the array with zeros
	ColorCities(int _citiesNumber) : citiesNumber(_citiesNumber) { arr.resize(citiesNumber); }
	// Return the vector int array
	std::vector<int> getArr() { return arr; }
	// Change the color of the city to black == Change the array on index city to 1
	void turnToBlack(int cityNumber) { arr[cityNumber - 1] = 1; };
};

