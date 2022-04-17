#pragma once
#include "State.h"
#include "ColorCities.h"
#include "AccessibleList.h"
#include "Stack.h"
#include "Queue.h"
#include "ItemType.h"

void getToTownRec(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList);
void getToTownIterative(State::HighWay roadSystem[], int cityNumber, ColorCities& colorCities, AccessibleList& accessList);

enum Line {
	START = 1,
	AFTER = 2,
	AFTER_SEC = 3,
};