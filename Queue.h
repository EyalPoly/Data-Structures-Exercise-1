#pragma once
#include "Node.h"

class Queue {
	Node* head;
	Node* tail;

public:
	Queue();
	int isEmpty();
	void enQueue(int item);
	int deQueue();
};

