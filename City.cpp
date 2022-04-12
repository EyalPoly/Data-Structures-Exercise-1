#include "City.h"

void City::insertAfter(City* newCity) {
	newCity->next = next;
	next = newCity;
}

void City::deleteAfter() {
	City* toDelete = next;
	if (toDelete != nullptr) {
		next = toDelete->next;
		delete toDelete;
	}
}
