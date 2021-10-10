// Specification file for the Student class
// Modified by:
// IDE:

#ifndef STUDENT_H
#define STUDENT_H

// using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!

using std::string;

class Student
{
private:
/* Write your code here: gpa - a double, name - a string */
	string name;
	double gpa;

public:
    /* Write your code here: default and overloaded constructors  */
	Student()
	{
		name = "";
		gpa = -1;
	}

	Student(double gpa, string name)
	{
		this->name = name;
		this->gpa = gpa;
	}
    // Setters and getters
    /* Write your code here: a setter and a getter for each data member of the class  */

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setGpa(int gpa)
	{
		this->gpa = gpa;
	}

	double getGpa()
	{
		return gpa;
	}

};
#endif
