Notes on Programming Assignment 3


1. Create a Console Application on Microsoft Visual Studio

	ARE ALREADY THERE WHEN CREATING CONSOLE APPLICATION:
	-stdafx.cpp
	-stdafx.h
	-targetver.h

2. Add StopWatch.h as one of the header files

3. Add Sort.cpp as source file and SelectionSort.h, HeapSort.h, and MergeSort.h for header files

4. Optional: Create a numbers.txt file
	Note: numbers.txt is the file downloaded from eCampus (however, my implementation reads integers only)
	See step 5 for more details

5. Random Number inputs (comment and uncomment wisely to choose how to get data)
	a. numbers.txt file
		a. Manually change the first number (see step 7)
		b. Manually change the second number for number of inserts into the array
		c. The rest of the numbers can be changed with ANY random numbers
	b. number generator coded in Sort.cpp
		a. numberInsert can be freely changed (MAX NUMBER TO INSERT IS 173323)

6. Unsorted random numbers are already populated into the array. Select the type of input to test the following sorting algorithms in step 7
	1 for Sorted (ascending order)
	2 for Reverse Sorted (descending order)
	3 for Random (keep the array as is)

7. Using step 6's input type, select type of sorting algorithm to sort the input
	1 for Selection Sort
	2 for Heap Sort
	3 for Merge Sort
