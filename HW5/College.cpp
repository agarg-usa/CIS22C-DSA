// Implementation file for the College class
// Written By: A. Student
// Changed By:
// IDE: Xcode

#include <iostream>
#include <iomanip>
#include <string>

#include "College.h"

using namespace std;

//**************************************************
// Constructor
//**************************************************
College::College()
{
	rank = -1;
	code = "";
	name = "";
	cost = -1;
}

//**************************************************
// Overloaded Constructor
//**************************************************
College::College(int rk, string cd, string nm, int ct)
{
	rank = rk;
	code = cd;
	name = nm;
	cost = ct;
}

// overloaded operators
/* Write your code here to define the following oveloaded operator:
    - the stream insertion operator ( << )
 */

ostream &operator<<(ostream &output, const College &c)
{
	output << left;
	output << " " << setw(4) << c.code << "  ";
	output << " " << setw(2) << c.rank << "  ";
	output << " " << setw(27) << c.name << "  ";
	output << right;
	output << " " << setw(7) << c.cost << " ";
	output << left << endl;

	return output;
}