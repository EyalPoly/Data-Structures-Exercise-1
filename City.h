#pragma once
class City {
	int cityNumber = 0;
	City* next = nullptr;
public:
	// Empty ctor
	City() {};
	// Ctor with city number
	City(int _cityNumber) : cityNumber(_cityNumber) {}
	// Insert newCity after current city 
	void insertAfter(City* newCity);
	// Delete the city after the current city
	void deleteAfter();
	friend class State;
};

