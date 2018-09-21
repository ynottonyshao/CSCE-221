// Sort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <array>
#include <random>
// #include <algorithm>

#include "StopWatch.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

using namespace std;

int main()
{
	try {
		/*ifstream inFile;
		inFile.open("numbers.txt");

		if (!inFile) {
			cout << "Unable to open file numbers.txt" << endl;
			exit(1);
		}*/

		int choice;
		int choice2;
		// int numberInsert;
		int numberInsert = 100000;	// MAX is 173323 using Windows Command Prompt
		// inFile >> choice;
		// inFile >> numberInsert;

		bool validType = false;
		bool validSort = false;

		do {
			cout << "Enter 1, 2, or 3 for type of input array of numbers." << endl;
			cout << "1. Sorted (increasing order)" << endl;
			cout << "2. Reverse sorted (decreasing order)" << endl;
			cout << "3. Random" << endl;
			cout << "The choice chosen is ";
			cin >> choice2;
			cout << endl;
			if (choice2 >= 0 && choice2 <= 3) {
				validType = true;
			}
			else {
				cout << "That is an incorrect option." << endl;
			}
		} while (!validType);

		do {
			cout << "Enter 1, 2, or 3 to select a Sorting Algorithm" << endl;
			cout << "1. Selection Sort" << endl;
			cout << "2. Heap Sort" << endl;
			cout << "3. Merge Sort" << endl;
			cout << "The choice chosen is ";
			cin >> choice;
			cout << endl;
			if (choice >= 0 && choice <= 3) {
				validSort = true;
			}
			else {
				cout << "That is an incorrect option." << endl;
			}
		} while (!validSort);

		// Random input
		srand(time(NULL));
		int inputArr[numberInsert];
		for (int i = 0; i < numberInsert; i++) {
			long input = (rand() * rand()) % 10000001;
			inputArr[i] = input;
		}

		// Sorted input
		if (choice2 == 1) {
			cout << "Sorting the numbers in ascending order for input." << endl;
			cout << "Time depends on size of array. PLEASE WAIT..." << endl;
			// sort(inputArr, inputArr + numberInsert);
			int temp = 0;
			for (int i = 0; i < numberInsert; i++) {
				for (int j = i + 1; j < numberInsert; j++) {
					if (inputArr[i] > inputArr[j]) {
						temp = inputArr[i];
						inputArr[i] = inputArr[j];
						inputArr[j] = temp;
					}
				}
			}
		}

		// Reverse input
		else if (choice2 == 2) {
			cout << "Sorting the numbers in ascending order for input." << endl;
			cout << "Time depends on size of array. PLEASE WAIT..." << endl;
			/*sort(inputArr, inputArr + numberInsert);
			int temp;
			for (int i = 0; i < numberInsert / 2; ++i) {
				temp = inputArr[numberInsert - i - 1];
				inputArr[numberInsert - i - 1] = inputArr[i];
				inputArr[i] = temp;
			}*/
			int temp = 0;
			for (int i = 0; i < numberInsert; i++) {
				for (int j = i + 1; j < numberInsert; j++) {
					if (inputArr[i] < inputArr[j]) {
						temp = inputArr[i];
						inputArr[i] = inputArr[j];
						inputArr[j] = temp;
					}
				}
			}
		}

		// Copy array for sorting, keeping the original "random" numbers array possibly used for later
		int arr[numberInsert];
		for (int i = 0; i < numberInsert; i++) {
			arr[i] = inputArr[i];
		}

		CStopWatch watch; // BEGIN TIME

		// Begin Sorting
		cout << "Begin Sorting Algorithms" << endl;
		if (choice == 1) {
			cout << "Selection Sort" << endl;
			selectionSort(arr, numberInsert);
		}
		else if (choice == 2) {
			cout << "Heap Sort" << endl;
			heapSort(arr, numberInsert);
		}
		else if (choice == 3) {
			cout << "Merge Sort" << endl;
			mergeSort(arr, 0, numberInsert);
		}

		cout << watch.GetElapsedSeconds() << endl;	// END TIME

		/*cout << "Would you like to see the contents of the array after using the sorting algorithms? (Y/N)" << endl;
		string yn;
		cin >> yn;
		cout << endl;
		if (yn == "yes" || yn == "y") {
			for (int i = 0; i < numberInsert; i++) {
				cout << inputArr[i] << endl;
			}
		}*/
		// inFile.close();
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Oops... unknown error :(" << endl;
	}

	// system("pause");
}