/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by:
  IDE:
  *~**/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

using std::string;

class Customer
{
private:
	int year;
	int mileage;
	int seq;
	string name;

public:
	Customer()
	{
		year = 0;
		mileage = 0;
		seq = 0;
		name = "";
	}
	Customer(int year, int mileage, int seq, string name)
	{
		this->year = year;
		this->mileage = mileage;
		this->seq = seq;
		this->name = name;
	}

	int getYear()
	{
		return year;
	}
	int getMileage()
	{
		return mileage;
	}
	int getSeq()
	{
		return seq;
	}
	string getName()
	{
		return name;
	}

	void setYear(int)
	{
		year = year;
	}
	void setMileage(int)
	{
		mileage = mileage;
	}
	void setSeq(int)
	{
		seq = seq;
	}
	void setName(string)
	{
		name = name;
	}

	int getPriority();
};
#endif