#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <exception>
#include <vector>

using namespace std;

/**
* Note: in order to try to make things easier, the queue below will only have a single type of value
* in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
* make a priority queue that stored an object with both the key/value in it and a comparison operator
* that only compared the keys.
*/

struct node {
	int data;
	struct node *next;
};

template <class Type>
class PriorityQueue
{
private:
	// data here
	node *head;
	Type *pointer;
	int number;

	int heapIndex = 0;
	int heapArr[100000];

public:
	PriorityQueue() {
		head = NULL;
	}
	PriorityQueue(Type *dataArray, int n) {
		pointer = dataArray;
		number = n;
		head = NULL;
	}
	
	void unsortedInsert(int value) {
		node *temp = new node();
		temp->data = value;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
		}
		else {
			node *current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}

	void sortedInsert(int value) {
		node *temp = new node();
		temp->data = value;
		temp->next = NULL;
		
		if (head == NULL) {
			head = temp;
		}
		else {
			if (value <= head->data) {
				temp->next = head;
				head = temp;
			}
			else {
				node *current = head;
				while (current->next != NULL && current->next->data <= value) {
					current = current->next;
				}
				temp->next = current->next;
				current->next = temp;
			}
		}
	}

	void minHeapInsert(int value) {
		heapArr[heapIndex] = value;
		swapUp(heapIndex);
		heapIndex++;
	}
	void swapUp(int index) {
		int parent, temp;
		if (index != 0) {
			parent = floor((index + 1) / 2) - 1;
			if (heapArr[parent] > heapArr[index]) {
				temp = heapArr[parent];
				heapArr[parent] = heapArr[index];
				heapArr[index] = temp;
				swapUp(parent);
			}
		}
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void removeMinUnsorted() {
		int min = INT_MAX;
		while (head != NULL) {
			if (min > head->data) {
				min = head->data;
			}
			else {
				head = head->next;
			}
		}
		cout << "Item deleted is " << min << endl;
		// Incomplete
	}

	Type removeMinSorted() {
		Type temp;
		node *temporary;
		if (head == NULL) {
			cout << "Queue is empty." << endl;
		}
		else {
			temporary = head;
			// cout << "Item deleted is " << temporary->data << endl;
			head = head->next;
			free(temporary);
		}
		return temp;
	}

	void removeMin() {
		heapArr[0] = heapArr[heapIndex - 1];
		// cout << "Item deleted is " << heapArr[0] << endl;
		heapIndex--;
		if (heapIndex > 0) {
			swapDown(0);
		}
	}
	void swapDown(int index) {
		int left, right, minIndex, temp;
		left = (index * 2) + 1;
		right = (index * 2) + 2;
		if (right >= heapIndex) {
			if (left >= heapIndex) {
				return;
			}
			else {
				minIndex = left;
			}
		}
		else {
			if (heapArr[left] <= heapArr[right]) {
				minIndex = left;
			}
			else {
				minIndex = right;
			}
		}
		if (heapArr[index] > heapArr[minIndex]) {
			temp = heapArr[minIndex];
			heapArr[minIndex] = heapArr[index];
			heapArr[index] = temp;
			swapDown(minIndex);
		}
	}

	void displayList() {
		node *pointer = new node();
		if (head == NULL) {
			cout << "Queue is empty..." << endl;
		}
		else {
			cout << "The queue is: " << endl;
			pointer = head;
			cout << pointer->data << endl;
			while (pointer->next != NULL) {
				cout << pointer->next->data << endl;
				pointer = pointer->next;
			}
		}
	}
	void displayHeap() {
		for (int i = 0; i < heapIndex; i++) {
			cout << heapArr[i] << endl;
		}
	}
};

#endif