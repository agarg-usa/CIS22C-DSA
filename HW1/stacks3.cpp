#include <iostream>
using namespace std;

class Stack_int
{
private:
	// Structure for the stack nodes
	struct StackNode
	{
		int value;		 // Value in the node
		StackNode *next; // Pointer to next node
	};

	StackNode *top; // Pointer to the stack top
	int length;

public:
	Stack_int()
	{
		top = NULL;
		length = 0;
	} //Constructor
	//~Stack_int();                            // Destructor

	// Stack operations
	bool isEmpty()
	{
		return length == 0;
	}
	bool push(int);
	int pop()
	{
		int val = top->value;
		length--;
		top = top->next;

		return val;
	}
	int peek()
	{
		return top->value;
	}
	int getLength()
	{

		if(isEmpty())
		{
			return 0;
		}

		int size = 1;
		StackNode* currNode = top;

		while(currNode->next != nullptr)
		{
			size++;
			currNode = currNode->next;
		}

		return size;
	}
};

/**~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_int::push(int item)
{
	StackNode *newNode; // Pointer to a new node

	// Allocate a new node and store num there.
	newNode = new StackNode;
	if (!newNode)
		return false;
	newNode->value = item;

	// Update links and counter
	newNode->next = top;
	top = newNode;
	length++;

	return true;
}

int main()
{

	Stack_int s;
	int item;

	while(true)
	{
		cin >> item;
		if(item <= 0)
		{
			break;
		}

		s.push(item);
	}

	if(s.getLength() == 0)
	{
		cout << "Empty Stack!" << endl;
		return 0;
	}

	while(!s.isEmpty())
	{
		cout << s.pop() << endl;
	}

	return 0;
}