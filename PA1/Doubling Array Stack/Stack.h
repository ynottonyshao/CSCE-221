#pragma once
#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <exception>

using namespace std;

template <class Type>
class AbstractStack
{
private:
	int capacity;
	Type* arrayStack;
	int indexTop;

public:

	AbstractStack(int cap) : capacity(cap) {
		arrayStack = new Type[capacity];
		indexTop = -1;
	}

	~AbstractStack() {
		delete[] arrayStack;
	}

	bool isEmpty() {
		return indexTop < 0;
	}

	int size() {
		return indexTop + 1;
	}

	Type& top();

	Type pop();

	void push(Type e);
};

//return the top of the stack
template <class Type>
Type& AbstractStack<Type>::top() {
	if (isEmpty())
		throw runtime_error("Stack is empty.");
	return arrayStack[indexTop];
}

// pop the stack
template <class Type>
Type AbstractStack<Type>::pop() {
	if (isEmpty())
		throw runtime_error("Stack is empty.");
	else {
		return arrayStack[indexTop--];
	}
}

//push object onto the stack
template <class Type>
void AbstractStack<Type>::push(Type e) {
	if (size() == capacity) {
		Type* newArrayStack = arrayStack;
		capacity = capacity * 2;
		arrayStack = new Type[capacity];

		for (int i = 0; i <= indexTop; ++i) {
			arrayStack[i] = newArrayStack[i];
		}
		delete[] newArrayStack;
	}
	else {
		indexTop = indexTop + 1;
		arrayStack[indexTop] = e;
	}
}

#endif