#include "Utils.h"

void getToTownRec(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList) {
	// If the city has already been added to the acceesible list
	if (colorCities.getArr()[cityNumber - 1] == 1) {
		return;
	}
	colorCities.turnToBlack(cityNumber);
	accessList.insertCity(cityNumber);
	City* nextCity = roadSystem[cityNumber - 1].getHead()->getNextPointer();
	while (nextCity != nullptr) {
		getToTownRec(roadSystem, nextCity->getCityNumber(), colorCities, accessList);
		nextCity = nextCity->getNextPointer();
	}
}