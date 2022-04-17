#pragma once
#include "State.h"
#include "Queue.h"
#include "ColorCities.h"
#include "AccessibleList.h"

struct ItemType {
	State::HighWay *roadSystem = nullptr;
	int cityNumber = -1;
	ColorCities& colorCities;
	AccessibleList& accessList;
	City* currCity = nullptr;
	City* nextCity = nullptr;
	Queue queue = Queue();
	int line = -1;

public:
	//ItemType() {};
	~ItemType() {};
	ItemType(State::HighWay* _roadSystem, int _cityNumber, ColorCities& _colorCities, AccessibleList& _accessList, City* _currCity, City* _nextCity, Queue q, int _line) :
		roadSystem(_roadSystem), cityNumber(_cityNumber), colorCities(_colorCities), accessList(_accessList), currCity(_currCity), nextCity(_nextCity), queue(q), line(_line) {}
	ItemType& operator=(const ItemType& other) { 
		if (&other != this) {
			// delete[] roadSystem;
			roadSystem = roadSystem;
			cityNumber = other.cityNumber;
			colorCities = other.colorCities;
			accessList = other.accessList;
			queue = other.queue;
			line = other.line;
		}
		return *this;
	};
	ItemType(const ItemType& item) = default;
};

