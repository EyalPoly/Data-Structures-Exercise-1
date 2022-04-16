#include "State.h"
#include "Input.h"

void State::createRoadSystem(std::vector<int> const roads) {
	initializeHighWays();
	for (int i = 0; i < roads.size(); i = i + 2) {
		roadSystem[roads[i] - 1].insertToTail(roads[i + 1]);
	}
}

void State::initializeHighWays() {
	roadSystem = new HighWay[citiesNumber];
	for (int i = 0; i < citiesNumber; i++) {
		roadSystem[i].insertToTail(i + 1);
	}
}

void State::HighWay::insertToTail(int cityNumber) {
	City* newCity = new City(cityNumber);
	if (isEmpty()) {
		head = tail = newCity;
	}
	else {
		tail->insertAfterDynamicList(newCity);
		tail = newCity;
	}
}

void State::deleteState() {
	for (int cityNumber = 0; cityNumber < citiesNumber; cityNumber++) {
		roadSystem[cityNumber].deleteHighWay();
	}
	delete [] roadSystem;
}

void State::HighWay::deleteHighWay() {
	while (head->nextPointer != nullptr) {
		head->deleteAfterDynamicList();
	}
	delete head;
}

void State::print() const {
	std::cout << "Number of cities: " << citiesNumber << std::endl;
	std::cout << "Road System:";
	for (int highway = 0; highway < citiesNumber; highway++) {
		std::cout << "\nHighWay Number: " << roadSystem[highway].head->cityNumber;
		City* curr = roadSystem[highway].head->nextPointer;
		while (curr != nullptr) {
			std::cout << " -> " << curr->cityNumber;
			curr = curr->nextPointer;
		}
	}
}