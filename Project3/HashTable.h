/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the interfaces of the functions for the hash table. The collisions are handled with quadratic probing method.The maximum
* items that the table can hold is 509. The included interfaces of the functions are to insert, remove, and search items. There is also an address calculator
* which sums the ASCII values of each character in the string and gets remainder by diving it with the table size which is 509.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

const int SIZE = 509;

class HashTable {
public:
   HashTable();
   void insert(string key);
   void remove(string key);
   void search(string key);

private:
   int currentSize;
   int addressCalculator(string key);
   int searchForRemoval(string key);
   string hashTable[SIZE];
};

#endif //HASHTABLE_H
