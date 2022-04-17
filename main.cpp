#include "State.h"
#include "AccessibleList.h"
#include "ColorCities.h"
#include "Input.h"
#include "Utils.h"

int main(int argc, char* argv[]) {
	std::vector<int> citiesAndRoadsNumber;
	std::vector<int> roads;
	int focalCity;
	bool isRec;
	
	//If input input is valid
	if (getInput(citiesAndRoadsNumber, roads, focalCity)) {
		State state(citiesAndRoadsNumber);
		state.createRoadSystem(roads);
		AccessibleList accessListRec(citiesAndRoadsNumber[0]);
		AccessibleList accessListItr(citiesAndRoadsNumber[0]);
		ColorCities colorCitiesRec(citiesAndRoadsNumber[0]);
		ColorCities colorCitiesItr(citiesAndRoadsNumber[0]);
		getToTownRec(state.getRoadSystem(), focalCity, colorCitiesRec, accessListRec);
		getToTownIterative(state.getRoadSystem(), focalCity, colorCitiesItr, accessListItr);
		accessListRec.print(focalCity, isRec = true);
		accessListItr.print(focalCity, isRec = false);
		state.deleteState();
	}
}