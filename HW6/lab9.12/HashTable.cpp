// Implementation file for the Hash class
// Written By: A. Student
// Changed by:

#include <string>

#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function
 *~**/
int HashTable::_hash(string key) const
{
	int sum = 0;
	for (int i = 0; key[i]; i++)
		sum += key[i];
	return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
*~**/

bool HashTable::insert(Student &itemIn)
{
	if (count == hashSize)
		return false;

	int hashedKey = _hash(itemIn.getName());
	count++;
	int j = 0;
	for (int i = hashedKey; true; i = (i + 1) % hashSize)
	{
		if(!hashAry[i].getOccupied())
		{
			hashAry[i].setItem(itemIn);
			hashAry[i].setOccupied(1);
			hashAry[i].setNoCollisions(j);
			break;
		}
		j++;
	}


	return true;
}

/*~*~*~*
   hash delete - linear probe
*~**/

bool HashTable::remove(Student &itemOut)
{
	return false;
}

/*~*~*~*
   hash search - linear probe
   if found:
      - copy data to itemOut
      - copy number of collisions for this key tp noCol
      - returns true
   if not found, returns false
*~**/
bool HashTable::search(Student &itemOut, int &noCol, string key)
{
	int hashedKey = _hash(key);

	for (int i = hashedKey; hashAry[i].getOccupied() > 0 || hashAry[i].getNoCollisions() > 0; i = (i + 1) % hashSize)
	{
		if (hashAry[i].getItem().getName() == key)
		{
			itemOut = hashAry[i].getItem();
			noCol = hashAry[i].getNoCollisions();
			return true;
		}
	}

	return false;
}
