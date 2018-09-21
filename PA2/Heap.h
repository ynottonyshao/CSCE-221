#pragma once
#ifndef HEAP_H
#define HEAP_H

#include <exception>
using namespace std;

template <class Type>
void swap(Type &v1, Type &v2)
{
	Type v3 = v1;
	v1 = v2;
	v2 = v3;
}

template <class Type>
class Heap
{
private:
	Type *heap;
	int n;
	int capacity;

	int leftChild(int i)
	{
		return 2 * i + 1;
	}

	int rightChild(int i)
	{
		return 2 * i + 2;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	bool exists(int i)
	{
		return i >= 0 && i < n;
	}

	void upheap(int i)
	{
		while (i > 0 && heap[i] < heap[parent(i)]) // while not the root
		{
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
	}

	void downheap(int i)
	{
		while (exists(leftChild(i))) // while the current node has at least one child
		{
			int minChild = leftChild(i);
			if (exists(rightChild(i)) && heap[rightChild(i)] < heap[minChild])
			{
				minChild = rightChild(i);
			}

			if (heap[i] > heap[minChild])
			{
				swap(heap[i], heap[minChild]);
				i = minChild;
			}
			else
			{
				break;
			}
		}
	}

public:
	Heap(Type *data, int num) // bottom up heap construction
	{
		int i;

		n = num;
		capacity = num;
		heap = new Type[num];

		for (i = 0; i < num; i++)
		{
			heap[i] = data[i];
		}

		for (i = parent(num - 1); i >= 0; i--)
		{
			downheap(i);
		}
	}

	Heap(int sz) : capacity(sz)
	{
		n = 0;
		heap = new Type[capacity];
	}

	~Heap(void)
	{
		delete[] heap;
	}

	bool isEmpty(void)
	{
		return n == 0;
	}

	int size(void)
	{
		return n;
	}

	void insertElement(Type val) throw (exception)
	{
		if (n >= capacity)
		{
			throw exception("Heap is full");
		}

		heap[n] = val;
		n++;
		upheap(n - 1);
	}

	Type minElement(void) throw (exception)
	{
		if (isEmpty())
		{
			throw exception("Heap is empty");
		}
		return heap[0];
	}

	Type removeMin(void) throw (exception)
	{
		if (isEmpty())
		{
			throw exception("Heap is empty");
		}
		Type rvalue = heap[0];
		heap[0] = heap[n - 1];
		n--;
		downheap(0);

		return rvalue;
	}
};

#endif