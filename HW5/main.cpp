#include "BinarySearchTree.h" // BST ADT
#include "College.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

/* Write your code here */
void buildList(const string &filename, BinarySearchTree<College> &list);
void hDisplay(College &);
void vDisplay(College &);
void iDisplay(College &, int);
void searchManager(const BinarySearchTree<College> &list);

int main()
{
	string filename;
	BinarySearchTree<College> bst;

	cout << "What is the input file's name? ";
	cin >> filename;
	buildList(filename, bst);

	char option;
	cout << "Display Inorder [Y/N]? ";
	cin >> option;
	if (option == 'y' || option == 'Y')
	{
		cout << endl
			 << "Inorder: " << endl;
		bst.inOrder(hDisplay);
		cout << endl;
	}
	cout << "Display Indented List [Y/N]? ";
	cin >> option;
	if (option == 'y' || option == 'Y')
	{
		cout << "Indented List: " << endl;
		bst.printTree(iDisplay);
		cout << endl;
	}
	cout << "Display Leaf Nodes [Y/N]? ";
	cin >> option;
	if (option == 'y' || option == 'Y')
	{
		cout << "Leaf Nodes: " << endl;
		bst.printLeaves(hDisplay);
		cout << endl;
	}

	searchManager(bst);

	return 0;
}

void searchManager(const BinarySearchTree<College> &list)
{
	string targetCode = "";
	College aCollege;

	cout << "\n Search\n";
	cout << "=======\n";

	while (targetCode[0] != 'Q')
	{
		cout << "\nEnter a college code (or Q to stop searching) : \n";

		if(!getline(cin, targetCode))
		{
			break;
		}

		if(targetCode[0] == ' ')
		{
			targetCode = targetCode.substr(1);
		}

		string temp = "";
		for (int i = 0; i < targetCode.length(); i++)
		{
			temp += toupper(targetCode[i]);
		}
		targetCode = temp;

		if (targetCode[0] != 'Q')
		{
			College testCollege;
			testCollege.setCode(targetCode);
			if (list.search(testCollege, aCollege))
				vDisplay(aCollege);
			else
				cout << "College \"" << targetCode << "\" was not found in this list." << endl;
		}
	}
	cout << "___________________END SEARCH SECTION _____\n";
}

void buildList(const string &filename, BinarySearchTree<College> &tree)
{
	ifstream fin(filename);
	if (!fin)
	{
		cout << "Error opening the input file: \"" << filename << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(fin, line))
	{
		int rank, cost;
		string code, name;

		stringstream temp(line); // create temp with data from line
		temp >> rank;			 // read from temp
		temp >> code;
		temp.ignore();			  // to ignore space in front of name
		getline(temp, name, ';'); // stop reading name at ';'
		temp >> cost;
		// create a College object and initialize it with data from file
		College aCollege(rank, code, name, cost);
		tree.insert(aCollege);
	}

	fin.close();
}

/*
 horizontal display: all items on one line
*/
void hDisplay(College &item)
{
	cout << left;
	cout << " " << setw(4) << item.getCode() << "  ";
	cout << " " << setw(2) << item.getRank() << "  ";
	cout << " " << setw(27) << item.getName() << "  ";
	cout << right;
	cout << " " << setw(7) << item.getCost() << " ";
	cout << left << endl;
}

/*
 vertical display: one item per line
*/
void vDisplay(College &item)
{
	cout << "              Rank: " << item.getRank() << endl;
	cout << "       School Name: " << item.getName() << endl;
	cout << "Cost of Attendance: $" << item.getCost() << endl;
}

/*
 indented tree display: one item per line, including the level number
*/
void iDisplay(College &item, int level)
{
	for (int i = 1; i < level; i++)
		cout << "..";
	cout << level << "). " << item.getCode() << endl;
}
