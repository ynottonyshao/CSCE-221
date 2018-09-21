// DoublingArrayStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StopWatch.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	srand((unsigned int)time(NULL));
	// srand(time(NULL));
	CStopWatch watch;

	AbstractStack<int> arr(100);
	for (int x = 0; x < 1000; ++x) {
		for (int y = 0; y < 10000; ++y) {
			try {
				int input = rand() % 10; // integers 0-9
				arr.push(input);
			}
			catch (int a) {
				// if (a == 2) {cout << "Error: Stack overflow." << endl;}
			}
		}
		// cout << "Time: " << watch.GetElapsedSeconds() << " s" << endl;
		cout << watch.GetElapsedSeconds() << endl;
	}

	// cout << "Elapsed time: " << watch.GetElapsedSeconds() << " seconds" << endl;

	system("pause");
}