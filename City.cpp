#include "City.h"

void City::insertAfterDynamicList(City* newCity) {
	newCity->nextPointer = nextPointer;
	nextPointer = newCity;
}

void City::deleteAfterDynamicList() {
	City* toDelete = nextPointer;
	if (toDelete != nullptr) {
		nextPointer = toDelete->nextPointer;
		delete toDelete;
	}
}

