/*~*~*
CIS 22C
Project: Stack ADT

Written by:
IDE:
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

#include "StackADT.h"

template <typename T>
T Stack<T>::push(T item)
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

template <typename T>
T Stack<T>::pop()
{
	T val = top->value;
	length--;
	top = top->next;

	return val;
}

template <typename T>
T Stack<T>::peek()
{
	return top->value;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return length == 0;
}

template <typename T>
int Stack<T>::getLength()
{

	if (isEmpty())
	{
		return 0;
	}

	int size = 1;
	StackNode *currNode = top;

	while (currNode->next != nullptr)
	{
		size++;
		currNode = currNode->next;
	}

	return size;
}

void printInfo();

int main()
{
	printInfo();
	string filenames[] = {"numbers1.txt", "numbers2.txt", "numbers3.txt", ""};

	for (int i = 0; filenames[i] != ""; i++)
	{
		ifstream fin(filenames[i]);
		cout << "\nInput File: " << filenames[i] << endl;

		Stack<int> stack;
		int num;
		while (fin >> num)
		{
			//0 == length of stack
			//1 == top element
			//pos num == push it
			// neg number, pop the number and print it
			//EOF: print stack

			if (num == 0)
			{
				cout << "Count: " << stack.getLength() << endl;
			}
			else if (num == 1)
			{

				if (stack.isEmpty())
				{
					cout << "Top: Empty" << endl;
					continue;
				}

				cout << "Top: " << stack.peek() << endl;
			}
			else if (num > 1)
			{
				stack.push(num);
			}
			else if (num < 0)
			{
				if (stack.getLength() < -1 * num)
				{
					cout << "Error" << endl;
					continue;
				}

				cout << "Stack: ";
				for (int i = 0; i < -1 * num; i++)
				{
					cout << stack.pop() << " ";
				}

				cout << endl;
			}
		}

		if (stack.isEmpty())
		{
			cout << "Stack: Empty" << endl;
			continue;
		}

		cout << "Stack: ";
		int stackLength = stack.getLength();
		for (int i = 0; i < stackLength; i++)
		{
			cout << stack.pop() << " ";
		}

		cout << endl;
	}

	return 0;
}

/*~*~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
	cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}

/*~*~*~*~*~*~ Save the output below



*~*/