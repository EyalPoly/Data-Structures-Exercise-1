#pragma once
#include <vector>

// Get the input from the user
bool getInput(std::vector<int>& citiesAndRoadsNumber, std::vector<int>& roads, int& focalCity);
// Get from user the cities and roads number
std::vector<int> getCitiesAndRoadsNumber(bool& isValidInput);
// Print an invalid message to the screen and change to false the isValidInput boolean 
void printInvalidInput(bool& isValidInput);
// Get to roads in the state from the user
std::vector<int> getRoads(std::vector<int> citiesAndRoadsNumber, bool& isValidInput);
// Get the focal city from the user
int getFocalCity(std::vector<int> citiesAndRoadsNumber, bool& isValidInput);