#include "Queue.h"

Queue::Queue() {
	head = new Node();
	tail = head;
}

int Queue::isEmpty() {
	return head == tail;
}

void Queue::enQueue(int item) {
	Node* newNode = new Node(item);

	tail->insertAfter(newNode);
	tail = newNode;
}

int Queue::deQueue() {
	if (isEmpty()) return -1;

	Node* temp = head->deleteAfter();
	if (temp == nullptr) {
		tail = head;
		return -1;
	}
	int item = temp->getData();

	if (tail == temp) tail = head;
	delete temp;
	return item;
}