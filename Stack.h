#pragma once
#include "ItemType.h"
#include <vector>

class Stack {
	std::vector<ItemType> stack;
	int size = 0;

public:
	bool isEmpty() { return size == 0; }
	void makeEmpty();
	void push(ItemType item);
	ItemType pop();
};

