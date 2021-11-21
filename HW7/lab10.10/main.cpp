/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence

  Written By: A. Student
  Changed By:
  IDE:
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "Customer.h"
#include "Heap.h"

using namespace std;

Heap<Customer> heap;
int compare(Customer& c1, Customer& c2);

int main()
{
	string inputFileName;
	cout << "Input file name: ";
	getline(cin, inputFileName);

	ifstream inFile(inputFileName);
	if (!inFile)
	{
		cout << "Error opening the input file: \"" << inputFileName << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	cout << " ==== =======   =============" << endl;
	cout << " Year Mileage   Name" << endl;
	cout << " ==== =======   =============" << endl;

	int arrivalItr = 0;
	int servedItr = 0;
	//while not at eof
	while (!inFile.eof())
	{
		string type;
		inFile >> type;

		if (type == "A") // arrival
		{
			int yearsAsCustomer;
			int mileage;
			inFile >> yearsAsCustomer >> mileage;

			string name;
			getline(inFile, name);
			arrivalItr++;

			Customer customer(yearsAsCustomer, mileage, arrivalItr, name);
			heap.insertHeap(customer, compare);
		}
		else if(type == "S") // serve next customer
		{
			Customer myCustomer;
			heap.deleteHeap(myCustomer, compare);
			servedItr++;
			cout << "   " << myCustomer.getYear() << "  " << myCustomer.getMileage() << "    " << myCustomer.getName() << endl;
		}
	}

	cout << " ==== =======   =============" << endl;
	cout << "Served overbooked customers: " << servedItr << "\n" << endl;

	cout << " ==== =======   =============" << endl;
	cout << " Year Mileage   Name" << endl;
	cout << " ==== =======   =============" << endl;

	while(!heap.isEmpty())
	{
		Customer myCustomer;
		heap.deleteHeap(myCustomer, compare);
		cout << "   " << myCustomer.getYear() << "  " << myCustomer.getMileage() << "    " << myCustomer.getName() << endl;
	}

	cout << " ==== =======   =============" << endl;
	cout << "Rejected overbooked customers: " << arrivalItr - servedItr << endl;

	inFile.close();

	return 0;
}

int compare(Customer& c1, Customer& c2)
{
	if (c1.getPriority() > c2.getPriority())
		return -1;
	else if (c1.getPriority() < c2.getPriority())
		return 1;
	else
		return 0;
}