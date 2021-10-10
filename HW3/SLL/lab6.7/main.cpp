/*
 CIS 22C  // Student is a class

 This program builds and displays a sorted list
 The list is sorted in ascending order by name

 Modified by:
 IDE:

 */
#include <iostream>
#include <string>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;

    buildList(list); // insert data into the list

    list.displayList();

    return 0;
}

void buildList(StudentList &list)
{
    // Define and initialize an array of Student objects
    Student s[10] =
    {Student(2.3, "Tom"), Student(2.5, "John"), Student(3.1, "Paul"), Student(3.9, "Linda"), Student(3.6, "Bob"), Student(2.7, "Ann"), Student(4.0, "Mary"), Student(3.2, "Andy"), Student(0, "#")};

    //Insert data from array into the linked list
    for (int i = 0; s[i].getName() != "#" ; i++)
    {
        list.insertNode(s[i]);
    }
}
