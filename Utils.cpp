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

void getToTownIterative(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList) {
	Stack s;
	Queue q;
	City* currCity;
	q.enQueue(cityNumber);
	ItemType curr = ItemType(roadSystem, cityNumber, colorCities, accessList, nullptr, nullptr, q, Line::START);
	int returnFromRecursion = 0;
	//s.push(curr);	

	do {
		if (returnFromRecursion) {
			curr = s.pop();
		}
		if (curr.line == Line::START) {
			if (curr.queue.isEmpty()) {
				//curr.line = Line::AFTER_SEC;
				//s.push(curr);
				returnFromRecursion = 1;
			}
			else {
				curr.line = Line::AFTER;
				s.push(curr);
				returnFromRecursion = 1;
			}
		}
		else if (curr.line == Line::AFTER) {
			curr.line = Line::START;
			//s.push(curr);

			Queue newQ;
			int head = curr.queue.deQueue();
			if (head != -1) {
				s.push(curr);
				currCity = curr.roadSystem[head - 1].getHead()->getNextPointer();

				while (currCity != nullptr) {
					if (colorCities.getArr()[currCity->getCityNumber() - 1] == 0)
						newQ.enQueue(currCity->getCityNumber());
					currCity = currCity->getNextPointer();
				}

				if (colorCities.getArr()[head - 1] == 0) {
					colorCities.turnToBlack(head);
					accessList.insertCity(head);
				}
			}

			curr.queue = newQ;
			s.push(curr);
			returnFromRecursion = 1;
		}
		//else if (curr.line == Line::AFTER_SEC) {
		//	int head = curr.queue.deQueue();
		//	currCity = curr.roadSystem[head - 1].getHead();

		//	while (currCity != nullptr) {
		//		if (colorCities.getArr()[currCity->getCityNumber() - 1] == 0) {
		//			colorCities.turnToBlack(head);
		//			accessList.insertCity(head);
		//		}
		//		currCity = currCity->getNextPointer();
		//	}
		//}
	} while (!s.isEmpty());

}

//void getToTownIterative(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList) {
//	Stack s;
//	City* currCity = roadSystem[cityNumber - 1].getHead();
//	City* nextCity = currCity->getNextPointer();
//	City* nextCityNew = roadSystem[cityNumber - 1].getHead();
//	ItemType curr = ItemType(roadSystem, cityNumber, colorCities, accessList, currCity, currCity, Line::START);
//	int returnFromRecursion = 0;
//	//s.push(curr);	
//
//	do {
//		if (returnFromRecursion) {
//			curr = s.pop();
//			//currCity = curr.currCity;
//			//nextCity = curr.nextCity;
//		}
//
//		if (curr.line == Line::START) {
//			if (colorCities.getArr()[curr.cityNumber - 1] == 1) {
//				returnFromRecursion = 1;
//			}
//			else {
//				colorCities.turnToBlack(curr.cityNumber);
//				accessList.insertCity(curr.cityNumber);
//
//				curr.line = Line::AFTER;
//				s.push(curr);
//				returnFromRecursion = 0;
//			}
//		}
//		else if (curr.line == Line::AFTER) {
//			//City* nextCity = curr.roadSystem[curr.cityNumber - 1].getHead()->getNextPointer();
//			////ItemType next = ItemType(curr.roadSystem, nextCity->getCityNumber(), colorCities, accessList, Line::AFTER);
//			//curr.line = Line::START;
//
//			//while (nextCity != nullptr) {
//			//	curr.cityNumber = nextCity->getCityNumber();
//			//	s.push(curr);
//			//	nextCity = nextCity->getNextPointer();
//			//}
//
//
//
//
//				//City* nextCity = currCity->getNextPointer();
//				//City* nextCity = roadSystem[curr.cityNumber - 1].getHead()->getNextPointer();
//				//ItemType next = ItemType(curr.roadSystem, nextCity->getCityNumber(), colorCities, accessList, Line::AFTER);
//			curr.line = Line::START;
//
//			s.push(curr);
//			if (curr.nextCity != nullptr) {
//				curr.nextCity = curr.nextCity->getNextPointer();
//				//curr.currCity = curr.nextCity;
//				//curr.cityNumber = curr.currCity->getCityNumber();
//				//curr.nextCity = roadSystem[curr.cityNumber - 1].getHead()->getNextPointer();
//				//nextCityNew = nextCityNew->getNextPointer();
//				//curr.currCity = roadSystem[curr.cityNumber - 1].getHead();
//				// nextCity = nextCity->getNextPointer();
//				returnFromRecursion = 0;
//			}
//			//else {
//			//	//curr.currCity = currCity->getNextPointer();
//			//	curr.line = Line::AFTER;
//
//
//
//			//	returnFromRecursion = 1;
//			//}
//			//curr.cityNumber = nextCity->getCityNumber();
//
//			//returnFromRecursion = 0;
//		}
//	}
//	while (!s.isEmpty());
//	
//}


//void getToTownIterative(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList) {
//	Stack s;
//	City* currCity = roadSystem[cityNumber - 1].getHead();
//	ItemType curr = ItemType(roadSystem, cityNumber, colorCities, accessList, nullptr, nullptr, Line::START);
//	int returnFromRecursion = 0;
//
//	//colorCities.turnToBlack(cityNumber);
//	//accessList.insertCity(cityNumber);
//
//	//City* nextCity = roadSystem[cityNumber - 1].getHead()->getNextPointer();
//
//	//while (nextCity != nullptr) {
//	//	if (colorCities.getArr()[nextCity->getCityNumber() - 1] == 0) {
//	//		getToTownRec(roadSystem, nextCity->getCityNumber(), colorCities, accessList);
//	//	}
//
//	//	nextCity = nextCity->getNextPointer();
//	//}
//
//	do {
//		if (returnFromRecursion) {
//			curr = s.pop();
//		}
//
//		if (curr.line == Line::START) {
//			colorCities.turnToBlack(cityNumber);
//			accessList.insertCity(cityNumber);
//
//			City* nextCity = roadSystem[curr.cityNumber - 1].getHead()->getNextPointer();
//
//			if (nextCity == nullptr) {
//				returnFromRecursion = 1;
//			}
//			else {
//				curr.line = AFTER;
//				s.push(curr);
//
//				if (colorCities.getArr()[nextCity->getCityNumber() - 1] == 0) {
//					curr.cityNumber = nextCity->getCityNumber();
//				}
//			
//				curr.line = Line::START;
//
//				//nextCity = nextCity->getNextPointer();
//				returnFromRecursion = 0;
//			}
//		}
//		else if (curr.line == Line::AFTER) {
//			returnFromRecursion = 1;
//		}
//	} while (!s.isEmpty());
//
//}