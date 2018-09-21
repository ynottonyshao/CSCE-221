#pragma once
#ifndef NODE
#define NODE

template <class Type>
class node {
public:
	Type element;
	node<Type>* next; // next node

	node<Type>() {}

	node<Type>(Type e, node<Type>* n = nullptr) : element(e), next(n) {}

	node<Type>(Type e) : element(e) {}

	virtual ~node<Type>() {}
};

#endif