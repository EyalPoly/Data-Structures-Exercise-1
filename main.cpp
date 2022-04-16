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
		AccessibleList accessList(citiesAndRoadsNumber[0]);
		ColorCities colorCities(citiesAndRoadsNumber[0]);
		getToTownRec(state.getRoadSystem(), focalCity, colorCities, accessList);
		accessList.print(focalCity, isRec = true);
		//accessList.print(isRec = false);
		state.deleteState();
	}
}