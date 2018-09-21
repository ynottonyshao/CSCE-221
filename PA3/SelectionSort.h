#pragma once
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <exception>
#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
	int minIndex, temp;
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

#endif