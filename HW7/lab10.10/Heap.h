/* *~*~*
Heap template
Written By: A. Student
Changed by:
IDE:
*~**/

#ifndef HEAP_H_
#define HEAP_H_

template <class ItemType>
class Heap
{
private:
	ItemType *heapAry;
	int heapSize;
	int count;

	// function pointer compare : 0 means equal, 1 means left > right, -1 means left < right
	void _reHeapUp(int lastndx, int compare(ItemType &, ItemType &));
	void _reHeapDown(int rootndx, int compare(ItemType &, ItemType &));
	int _findParent(int index) { return (index <= 0) ? (-1) : (index - 1) / 2; }
	int _findLeftChild(int index) { return (2 * index + 1 >= count) ? (-1) : (2 * index + 1); }
	int _findRightChild(int index) { return (2 * index + 2 >= count) ? (-1) : (2 * index + 2); }
	void _swap(int index1, int index2);

public:
	Heap()
	{
		count = 0;
		heapSize = 128;
		heapAry = new ItemType[heapSize];
	}
	Heap(int n)
	{
		count = 0;
		heapSize = n;
		heapAry = new ItemType[heapSize];
	}
	~Heap() { delete[] heapAry; }

	int getCount() const { return count; }
	int getSize() const { return heapSize; }
	bool isEmpty() const { return count == 0; }
	bool isFull() const { return count == heapSize; }
	bool insertHeap(ItemType &itemIn, int compare(ItemType &, ItemType &));
	bool deleteHeap(ItemType &itemOut, int compare(ItemType &, ItemType &));
};

template <class ItemType>
void Heap<ItemType>::_swap(int index1, int index2)
{
	ItemType temp = heapAry[index1];
	heapAry[index1] = heapAry[index2];
	heapAry[index2] = temp;
}

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
template <class ItemType>
void Heap<ItemType>::_reHeapUp(int lastndx, int compare(ItemType &, ItemType &))
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
template <class ItemType>
void Heap<ItemType>::_reHeapDown(int rootdex, int compare(ItemType &, ItemType &))
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
template <class ItemType>
bool Heap<ItemType>::insertHeap(ItemType &newItem, int compare(ItemType &, ItemType &))
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
template <class ItemType>
bool Heap<ItemType>::deleteHeap(ItemType &returnItem, int compare(ItemType &, ItemType &))
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

#endif