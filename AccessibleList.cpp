#include "AccessibleList.h"
#include "Input.h"
#include <iostream>

AccessibleList::AccessibleList(int citiesNumber): arrSize(citiesNumber) {
	// Running on all the items in freeList and setting the nextIndex to be the next item
	// The last one is -1
	arr.reserve(arrSize);
	for (int i = 0; i < arrSize - 1; i++) {
		arr.push_back(City(0, i + 1));
	}
	arr.push_back(City(0, -1));
}

void AccessibleList::insertCity(int cityNumber) {
	int newLocation;

	if (headFree == -1) {
		std::cout << "Error! Array is out of memory!";
		return;
	}
	if (tailList == -1) {
		headList = tailList = 0;
	}
	else {
		arr[tailList].setNextIndex(headFree);
		tailList = headFree;
	}
	newLocation = headFree;
	headFree = arr[headFree].getNextIndex();
	arr[newLocation].setCityNumber(cityNumber);
	arr[newLocation].setNextIndex(-1);
}

void AccessibleList::print(int focalCity, bool isRec) {
	City curr;
	int index = headList;

	std::cout << "Cities accessible from source city " << focalCity;
	if (isRec) {
		std::cout << " (recursive algorithm): ";
	}
	else {
		std::cout << " (iterative algorithm): ";
	}
	while (index != -1) {
		curr = arr[index];
		std::cout << curr.getCityNumber() << " ";
		index = curr.getNextIndex();
	}
}
