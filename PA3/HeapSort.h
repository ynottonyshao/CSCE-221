#pragma once
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <exception>
#include <iostream>

using namespace std;

void heapify(int arr[], int i, int n) {
	int max = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	if (left < n && arr[left] > arr[max]) {
		max = left;
	}
	if (right < n && arr[right] > arr[max]) {
		max = right;
	}
	if (max != i) {
		int temp = 0;
		temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
		heapify(arr, max, n);
	}
}

void heapSort(int arr[], int n) {
	for (int i = (n / 2) - 1; i >= 0; --i) {
		heapify(arr, i, n);
	}
	for (int i = n - 1; i >= 0; i--) {
		int temp = 0;
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr, 0, i);
	}
}

#endif