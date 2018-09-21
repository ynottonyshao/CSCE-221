#pragma once
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <exception>
#include <iostream>

using namespace std;

void merge(int arr[], int left, int middle, int right) {
	int i, j, k;
	int num1 = middle - left + 1;
	int num2 = right - middle;

	int leftArray[num1], rightArray[num2];

	for (i = 0; i < num1; i++) {
		leftArray[i] = arr[left + i];
	}
	for (j = 0; j < num2; j++) {
		rightArray[j] = arr[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < num1 && j < num2) {
		if (leftArray[i] <= rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < num1) {
		arr[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < num2) {
		arr[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

#endif