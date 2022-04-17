#include "Stack.h"

void Stack::makeEmpty() {
	stack.clear();
	size = 0;
}

void Stack::push(ItemType item) {
	stack.push_back(item);
	size++;
}

ItemType Stack::pop() {
	ItemType item = stack[size - 1];
	size--;
	stack.pop_back();
	return item;
}