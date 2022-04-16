#pragma once
class City {
	int cityNumber = 0; // Default
	City* nextPointer = nullptr; // Default
	int nextIndex = -1; // Default
public:
	// Empty ctor
	City() {};
	// Ctor with city number
	City(int _cityNumber) : cityNumber(_cityNumber) {}
	// Ctor with next index
	City(int _cityNumber, int _nextIndex) : cityNumber(_cityNumber), nextIndex(_nextIndex) {}
	// Insert newCity after current city 
	void insertAfterDynamicList(City* newCity);
	// Delete the city after the current city
	void deleteAfterDynamicList();
	// Changing the next Index
	void setNextIndex(int index) { nextIndex = index; }
	// changing the city number
	void setCityNumber(int number) { cityNumber = number; }
	// Return next index
	int getNextIndex() { return nextIndex; }
	// Return the cuty number
	int getCityNumber() { return cityNumber; }
	// Return the next pointer
	City* getNextPointer() { return nextPointer; }
	friend class State;
};

