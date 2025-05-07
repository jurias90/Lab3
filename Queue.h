#pragma once

#include "Stack.h"

class Queue : public SinglyLinkedList {
public:
	Queue() : SinglyLinkedList() {}
	~Queue() {
		emptyQueue();
	}

	void enqueue(Currency* obj);
	Currency* dequeue();
	Currency* peekFront();
	Currency* peekRear();
	std::string stringifyQueue();
	void emptyQueue();
};

void Queue::enqueue(Currency* obj) {
	// get the new rear's index which is count
	int index = countCurrency();

	// add this object to the rear of the queue
	addCurrency(obj, index);
}

Currency* Queue::dequeue() {
	// remove the start and return the data
	return removeCurrency(0);
}

Currency* Queue::peekFront() {
	// peek the front and return data
	return getCurrency(0);
}

Currency* Queue::peekRear() {
	// get the rear's index which is count - 1
	int index = countCurrency() - 1;

	// peek the rear and return data
	return getCurrency(index);
}

std::string Queue::stringifyQueue() {
	return stringifyList();
}

void Queue::emptyQueue() {
	emptyList();
}
