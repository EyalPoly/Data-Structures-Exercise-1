#include "State.h"

void State::createRoadSystem() {
	int fromCity, toCity;

	setCitiesNumber();
	setRoadsNumber();
	roadSystem = new HighWay [citiesNumber];
	for (int i = 0; i < roadsNumber; i++) {
		std::cin >> fromCity;
		std::cin >> toCity;
		// If the fromCity doesn't have yet a city it's connected to
		if (roadSystem[fromCity].isEmpty()) {
			roadSystem[fromCity].insertToTail(fromCity);
		}
		roadSystem[fromCity].insertToTail(toCity);
	}
}

void State::HighWay::insertToTail(int cityNumber) {
	City* newCity = new City(cityNumber);
	if (isEmpty()) {
		head = tail = newCity;
	}
	else {
		tail->insertAfter(newCity);
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
	while (head->next != nullptr) {
		head->deleteAfter();
	}
	delete head;
}

void State::print() {
	std::cout << "Number of cities: " << citiesNumber << std::endl;
	std::cout << "Road System:";
	for (int cityNumber = 1; cityNumber <= citiesNumber; cityNumber++) {
		std::cout << "\nHighWay Number: " << cityNumber;
		City* curr = roadSystem[cityNumber].head->next;
		while (curr != nullptr) {
			std::cout << " -> " << curr->cityNumber;
			curr = curr->next;
		}
	}
}