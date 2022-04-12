#include "State.h"
//#include "City.h"

int main(int argc, char* argv[]) {
	State state;
	

	state.createRoadSystem();
	
	City accessibleCities[state.getCitiesNumber()];
	state.deleteState();
}