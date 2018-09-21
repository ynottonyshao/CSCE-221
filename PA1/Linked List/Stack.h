#pragma once
#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

#include <exception>
#include "Node.h"

using namespace std;

template <class Type>
class AbstractStack
{
	private:
		int length; // length of stack
		node<Type>* head; // top of stack

	public:

		AbstractStack(int a);

		~AbstractStack();

		bool isEmpty() {
			return length == 0;
		}

		int size() {
			return length;
		}

		Type& top();

		Type pop();

		void push(Type e);
};

template <class Type>
AbstractStack<Type>::AbstractStack(int a){
	head = nullptr;
	length = 0;
}

template <class Type>
AbstractStack<Type>::~AbstractStack() {
	node<Type>* temp = this->head;
	while (temp != nullptr) {
		node<Type>* current = temp->next;
		delete temp;
		temp = current;
	}
	head = nullptr;
}

//return the top of the stack
template <class Type>
Type& AbstractStack<Type>::top() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty.");
	}
	else {
		return head->element;
	}
}

// pop the stack
template <class Type>
Type AbstractStack<Type>::pop() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty.");
	}
	else {
		node<Type>* temp = head;
		head = head->next;
		Type head_value = temp->element;
		delete temp;
		length--;
		return head_value;
	}
}

//push object onto the stack
template <class Type>
void AbstractStack<Type>::push(Type e) {
	if (head == nullptr) {
		head = new node<Type>(e, nullptr);
	}
	else {
		node<Type>* temp = new node<Type>(e, head);
		head = temp;
		// delete temp;
	}
	length++;
}

#endif