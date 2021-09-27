#include <iostream>
#include <string>
using namespace std;

#include "QueueADT.h"

// Ann Tim Jamie Bob # 9 4.5 15 13.5
int main()
{

	Queue<string> namesQueue;
	Queue<double> unitsQueue;
	string item;
	double units;

	while (true)
	{
		cin >> item;
		if (item == "#")
		{
			break;
		}

		namesQueue.push(item);
	}

	if(namesQueue.isEmpty())
	{
		cout << "Empty Queue!" << endl;
		return 0;
	}

	cout << namesQueue.getLength() << " " << unitsQueue.getLength() << endl;

	for(int i = 0; i < namesQueue.getLength(); i++)
	{
		cin >> units;
		unitsQueue.push(units);
	}

	string firstName = namesQueue.peek();
	double lastUnits = unitsQueue.peekRear();

	while(!namesQueue.isEmpty())
	{
		cout << namesQueue.pop() << " " << unitsQueue.pop() << endl;
	}

	cout << firstName << endl;
	cout << lastUnits << endl;

	return 0;
}