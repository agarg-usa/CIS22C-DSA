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
		if (hashAry[i].getOccupied() < 2)
		{
			hashAry[i].setItem(itemIn);
			hashAry[i].setOccupied(2);
			hashAry[i].setNoCollisions(j);
			break;
		}
		j++;
	}

	return true;
}

/*~*~*~*
   hash delete - linear probe
   - looks for key in hash table
   - if found:
       - copies its data to itemOut
       - replaces data in the hash node with an "empty" record
       - returns true
   - if not found - returns false
*~**/

bool HashTable::remove(Student &itemOut, string key)
{
	int hashedKey = _hash(key);
	bool lookedThroughFirstElm = false;
	for (int i = hashedKey; hashAry[i].getOccupied() > 0; i = (i + 1) % hashSize)
	{
		if (lookedThroughFirstElm && i == hashedKey)
		{
			break;
		}
		if (hashAry[i].getItem().getName() == key)
		{
			itemOut = hashAry[i].getItem();
			hashAry[i].setNoCollisions(0);
			hashAry[i].setOccupied(1);
			hashAry[i].setItem(Student());
			count--;
			return true;
		}
		lookedThroughFirstElm = true;
	}

	return false;
}

/*~*~*~*
   hash search - linear probe
   if found:
      - copy data to itemOut
      - returns the number of collisions for this key
   if not found, returns -1
*~**/
int HashTable::search(Student &itemOut, string key)
{
	int hashedKey = _hash(key);

	bool lookedThroughFirstElm = false;

	for (int i = hashedKey; hashAry[i].getOccupied() > 0; i = (i + 1) % hashSize)
	{
		if (lookedThroughFirstElm && i == hashedKey)
		{
			break;
		}

		if (hashAry[i].getItem().getName() == key)
		{
			itemOut = hashAry[i].getItem();
			return hashAry[i].getNoCollisions();
		}

		lookedThroughFirstElm = true;
	}

	return -1;
}
