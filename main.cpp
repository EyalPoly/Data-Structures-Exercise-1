#include "State.h"
#include "AccessibleList.h"
#include "ColorCities.h"
#include "Input.h"

void getToTownRec(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList);

int main(int argc, char* argv[]) {
	std::vector<int> citiesAndRoadsNumber;
	std::vector<int> roads;
	int focalCity;
	bool isRec;
	
	//If input input is valid
	if (getInput(citiesAndRoadsNumber, roads, focalCity)) {
		State state(citiesAndRoadsNumber);
		state.createRoadSystem(roads);
		AccessibleList accessList(citiesAndRoadsNumber[0]);
		ColorCities colorCities(citiesAndRoadsNumber[0]);
		getToTownRec(state.getRoadSystem(), focalCity, colorCities, accessList);
		accessList.print(focalCity, isRec = true);
		//accessList.print(isRec = false);
		state.deleteState();
	}
}

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