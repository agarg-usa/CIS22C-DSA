/* *~*~*
Implementation file for the Customer class
Written By: A. Student
Changed by:
IDE:
*~**/
#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

int Customer::getPriority()
{
	return (mileage / 1000 + year - seq)*100 + 100 - seq;
}