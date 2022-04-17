#include "Node.h"

void Node::insertAfter(Node* newNode) {
	newNode->next = next;
	next = newNode;
}

Node* Node::deleteAfter() {
	Node* toDelete = next;

	if (toDelete == nullptr) return nullptr;
	next = toDelete->next;
	return toDelete;
}