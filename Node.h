#pragma once
class Node {
	int data;
	Node* next;

public:
	Node() : next(nullptr) {};
	Node(int _data, Node* ptr = nullptr) : data(_data), next(ptr) {};
	void insertAfter(Node* newNode);
	Node* deleteAfter();
	int getData() { return data; }
};

