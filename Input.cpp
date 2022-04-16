#include "Input.h"
#include <iostream>
#include <string.h>
#include <sstream>

bool getInput(std::vector<int>& citiesAndRoadsNumber, std::vector<int>& roads, int& focalCity) {
	bool isValidInput = true;

	citiesAndRoadsNumber = getCitiesAndRoadsNumber(isValidInput);
	if (isValidInput) {
		roads = getRoads(citiesAndRoadsNumber, isValidInput);
		if (isValidInput) {
			focalCity = getFocalCity(citiesAndRoadsNumber, isValidInput);
		}
	}
	return isValidInput;
}

std::vector<int> getCitiesAndRoadsNumber(bool& isValidInput) {
	int inputNumber;
	std::string inputString;
	std::stringstream ss;
	std::vector<int> result;

	// Get the line input from the user
	std::getline(std::cin, inputString);
	// Insert it to the string stream
	ss << inputString;
	while (!ss.eof() && isValidInput) {
		// Insert an integer from the string stream to an int variable
		// The stream advance to next integer
		ss >> inputNumber;
		// Save the integer into a vector
		result.push_back(inputNumber);
		//If the integer is negative
		if (inputNumber < 0) {
			printInvalidInput(isValidInput);
		}
	}
	// If the user entered more then two integers
	if (result.size() > 2 && isValidInput) {
		printInvalidInput(isValidInput);
	}
	return result;
}

void printInvalidInput(bool& isValidInput) {
	std::cout << "Invalid input!";
	isValidInput = false;
}

std::vector<int> getRoads(std::vector<int> citiesAndRoadsNumber, bool& isValidInput) {
	int inputNumber;
	std::string inputString;
	std::stringstream ss;
	std::vector<int> roads;

	// Get the line input from the user
	std::getline(std::cin, inputString);
	// Insert it to the string stream
	ss << inputString;
	while (!ss.eof() && !inputString.empty()) {
		// Insert an integer from the string stream to an int variable
		// The stream advance to next integer
		ss >> inputNumber;
		// Save the integer into a vector
		roads.push_back(inputNumber);
		//If the integer is negative or it's higher then the number of cities
		if (inputNumber < 0 || inputNumber > citiesAndRoadsNumber[0]) {
			printInvalidInput(isValidInput);
		}
	}
	// If the user didn't enter the exact number of roads
	if (roads.size() != citiesAndRoadsNumber[1] * 2 && isValidInput) {
		printInvalidInput(isValidInput);
	}
	return roads;
}

int getFocalCity(std::vector<int> citiesAndRoadsNumber, bool& isValidInput) {
	int focalCity = 0;
	std::string inputString;
	std::stringstream ss;

	// Get the line input from the user
	std::getline(std::cin, inputString);
	// Insert it to the string stream
	ss << inputString;
	//
	// If no focal city has been entered or there are no roads
	if (ss.eof()) {
		printInvalidInput(isValidInput);
	}
	// Insert an integer from the string stream to an int variable
	ss >> focalCity;
	// If there is more then one focal city
	// Or if the integer is negative or it's higher then the number of cities
	if (!ss.eof() || focalCity < 0 || focalCity > citiesAndRoadsNumber[0]) {
		printInvalidInput(isValidInput);
	}
	return focalCity;
}