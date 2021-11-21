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
void Heap::_reHeapUp(int lastndx)
{
	if (lastndx)
	{
		int parentIndex = _findParent(lastndx);
		if (heapAry[parentIndex] > heapAry[lastndx])
		{
			_swap(parentIndex, lastndx);
			_reHeapUp(parentIndex);
		}
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex)
{
	int left = _findLeftChild(rootdex);
	int right = _findRightChild(rootdex);
	if (left == -1 && right == -1) //leaf node
	{
		return;
	}
	else if (left == -1)
	{
		if (heapAry[right] < heapAry[rootdex])
		{
			_swap(right, rootdex);
			_reHeapDown(right);
		}
	}
	else if (right == -1)
	{
		if (heapAry[left] < heapAry[rootdex])
		{
			_swap(left, rootdex);
			_reHeapDown(left);
		}
	}
	else if (heapAry[left] < heapAry[rootdex] && heapAry[left] <= heapAry[right])
	{
		_swap(left, rootdex);
		_reHeapDown(left);
	}
	else if (heapAry[right] < heapAry[rootdex] && heapAry[right] < heapAry[left])
	{
		_swap(right, rootdex);
		_reHeapDown(right);
	}
}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	if (isFull())
		return false;

	heapAry[count] = newItem;
	_reHeapUp(count);
	count++;
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
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
	_reHeapDown(0);
	return true;
}