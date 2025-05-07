#include "SinglyLinkedList.h"

class Stack : public SinglyLinkedList {
	Stack() : SinglyLinkedList() {}
	~Stack() {
		emptyStack();
	}

	void push(Currency* obj);
	Currency* pop();
	Currency* peek();
	std::string stringifyStack();
	void emptyStack();
};

void Stack::push(Currency* obj) {
	// get the new top's index which is count
	int index = countCurrency();

	// add this object to the end (top) of the stack
	addCurrency(obj, index);
}

Currency* Stack::pop() {
	// get the top's index which is count - 1
	int index = countCurrency() - 1;

	// remove the top and return the data
	return removeCurrency(index);
}

Currency* Stack::peek() {
	// get the top's index which is count - 1
	int index = countCurrency() - 1;

	// peek the top and return data
	return getCurrency(index);
}

std::string Stack::stringifyStack() {
	return stringifyList();
}

void Stack::emptyStack() {
	emptyList();
}