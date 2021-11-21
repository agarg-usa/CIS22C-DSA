/* *~*~*
Implementation file for the Heap class: min-heap of integers
Written By: A. Student
Changed by:
IDE:
*~**/

#include "Heap.h"

void Heap::_swap(int index1, int index2)
{
	int temp = heapAry[index1];
	heapAry[index1] = heapAry[index2];
	heapAry[index2] = temp;
}

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx , int compare(int,int))
{
	if (lastndx)
	{
		int parentIndex = _findParent(lastndx);
		if (compare(heapAry[parentIndex], heapAry[lastndx]) > 0)
		{
			_swap(parentIndex, lastndx);
			_reHeapUp(parentIndex, compare);
		}
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex, int compare(int,int))
{
	int left = _findLeftChild(rootdex);
	int right = _findRightChild(rootdex);
	if (left == -1 && right == -1) //leaf node
	{
		return;
	}
	else if (left == -1)
	{
		if (compare(heapAry[right], heapAry[rootdex]) < 0)
		{
			_swap(right, rootdex);
			_reHeapDown(right, compare);
		}
	}
	else if (right == -1)
	{
		if (compare(heapAry[left], heapAry[rootdex]) < 0)
		{
			_swap(left, rootdex);
			_reHeapDown(left, compare);
		}
	}
	else if (compare(heapAry[left], heapAry[rootdex]) < 0 && compare(heapAry[left], heapAry[right]) <= 0)
	{
		_swap(left, rootdex);
		_reHeapDown(left, compare);
	}
	else if (compare(heapAry[right] , heapAry[rootdex]) < 0 && compare(heapAry[right], heapAry[left]) < 0)
	{
		_swap(right, rootdex);
		_reHeapDown(right, compare);
	}

}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem , int compare(int,int))
{
	if (isFull())
		return false;

	heapAry[count] = newItem;
	_reHeapUp(count, compare);
	count++;
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem, int compare(int,int))
{
	if (isEmpty())
		return false;
	else if (count == 1)
	{
		returnItem = heapAry[0];
		count--;
		return true;
	}

	returnItem = heapAry[0];
	heapAry[0] = heapAry[count - 1];
	count--;
	_reHeapDown(0, compare);
	return true;
}