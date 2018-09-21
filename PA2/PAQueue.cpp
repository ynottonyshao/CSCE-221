#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <array>

#include "stdafx.h"
#include "PriorityQueue.h"
#include "StopWatch.h"

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("numbers.txt");

	if (!inFile) {
		cout << "Unable to open file numbers.txt" << endl;
		exit(1);
	}
	int value;
	int arr[100000];

	srand((unsigned int)time(NULL));
	// srand(time(NULL));
	CStopWatch watch;	// START TIME
	
	int choice;
	int numberInsert;
	inFile >> choice;
	inFile >> numberInsert;

	int x = numberInsert / 1000;	// number of intervals
	int y = numberInsert / x;		// every x number of inserts

	PriorityQueue <int>queue(arr, numberInsert);

	if (choice == 0) {
		cout << "Unsorted Priority Queue" << endl;
		for (int i = 0; i < x; i++) {
			for (int i = 0; i < y; i++) {
				inFile >> value;
				queue.unsortedInsert(value);
			}
			cout << watch.GetElapsedSeconds() << endl;	// SHOW TIME
		}
		// queue.displayList();
		// cout << "Removing items." << endl;
		/*for (int i = 0; i < numberInsert; i++) {
			queue.removeMinUnsorted();
			cout << watch.GetElapsedSeconds() << endl;	// SHOW TIME
		}*/
		// queue.displayList();
	}
	else if (choice == 1) {
		cout << "Sorted Priority Queue" << endl;
		for (int i = 0; i < x; i++) {
			for (int i = 0; i < y; i++) {
				inFile >> value;
				queue.sortedInsert(value);
			}
			cout << watch.GetElapsedSeconds() << endl;	// SHOW TIME
		}
		// queue.displayList();
		cout << "Removing items." << endl;
		for (int i = 0; i < x; i++) {
			for (int i = 0; i < y; i++) {
				queue.removeMinSorted();
			}
			cout << watch.GetElapsedSeconds() << endl;	// SHOW TIME
		}
		// queue.displayList();
	}
	else if (choice == 2) {
		cout << "Heap Priority Queue" << endl;
		for (int i = 0; i < x; i++) {
			for (int i = 0; i < y; i++) {
				inFile >> value;
				queue.minHeapInsert(value);
			}
			cout << watch.GetElapsedSeconds() << endl;	// SHOW TIME
		}
		// queue.displayHeap();
		cout << "Removing items." << endl;
		for (int i = 0; i < x; i++) {
			for (int i = 0; i < y; i++) {
				queue.removeMin();
			}
			cout << watch.GetElapsedSeconds() << endl;	// SHOW TIME
		}
		// queue.displayHeap();
	}
	else {
		cout << "Number not valid." << endl;
		cout << "Please enter a number 0, 1, or 2." << endl;
		cout << "0. Unsorted List" << endl;
		cout << "1. Sorted List" << endl;
		cout << "2. Min Heap" << endl;
	}
	inFile.close();
	
	// system("pause");
}