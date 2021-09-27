#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Queue
{
private:
	// Structure for the stack nodes
	struct QueueNode
	{
		T value;	 // Value in the node
		QueueNode *next; // Pointer to next node
	};

	QueueNode *front; // Pointer to the first node
	QueueNode *rear;  // Pointer to the last node
	int length;		  // Number of nodes in the queue

public:
	Queue()
	{
		front = rear = NULL;
		length = 0;
	}

	~Queue()
	{
		QueueNode *curr = front;

		while (curr != nullptr)
		{
			QueueNode *temp = curr->next;
			delete curr;
			curr = temp;
		}
	}

	// Queue operations
	bool isEmpty()
	{
		return length == 0;
	}
	bool push(T item)
	{
		QueueNode *newNode; // Pointer to a new node

		// Allocate a new node and store num there.
		newNode = new QueueNode;
		if (!newNode)
			return false;
		newNode->value = item;
		newNode->next = NULL;

		// Update links and counter
		if (!front) // front is NULL: empty queue
			front = newNode;
		else
			rear->next = newNode;

		rear = newNode;
		length++;

		return true;
	}

	T pop()
	{
		T val = front->value;
		length--;
		front = front->next;

		if(isEmpty())
		{
			rear = nullptr;
		}

		return val;
	}

	T peek()
	{
		return front->value;
	}
	T peekRear()
	{
		return rear->value;
	}
	int getLength()
	{
		return length;
	}
};