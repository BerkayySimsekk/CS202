/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the implementations of the functions for the improved hash table.
*/

#include "HashTableImproved.h"
#include <iostream>

//constructor which assigns every string in the hash table to "Empty" and sets the size to 0
HashTableImproved::HashTableImproved() {
    currentSize = 0;

    for (int i = 0; i < OUTER_SIZE; i++)
        for (int j = 0; j < INNER_SIZE; j++)
            hashTable[i][j] = "Empty";
}

//calculates the address of the given string by summing up the ASCII values of the characters and getting the remainder of the sum by dividing it with the
//fixed table size
int HashTableImproved::addressCalculator(string key) {
    int sumOfASCIIValues = 0;

    for (int i = 0; i < key.length(); i++)
        sumOfASCIIValues += key[i];

    return sumOfASCIIValues % OUTER_SIZE;
}

//inserts the key if the given address is "Empty"; if the given address is not available, separate chaining method is used to handle it
void HashTableImproved::insert(string key) {
    const int address = addressCalculator(key);
    bool isDone = false;

    if (currentSize < OUTER_SIZE * INNER_SIZE) {
        for (int j = 0; j < INNER_SIZE && !isDone; j++) {
            if (hashTable[address][j] == "Empty") {
                hashTable[address][j] = key;
                currentSize++;
                isDone = true;
                cout << key << " is registered as a weak spot." << endl;
            }
        }
    }
    else
        cout << "Hash table is full." << endl;
}

//removes the given string if it can be found in the table
void HashTableImproved::remove(string key) {
    const int address = addressCalculator(key);
    bool isFound = false;

    for (int j = 0; j < INNER_SIZE && !isFound; j++) {
        if (hashTable[address][j] == key) {
            hashTable[address][j] = "Empty";
            cout << key << " is deleted." << endl;
            currentSize--;
            isFound = true;
        }
    }

    if (!isFound)
        cout << key << " is not present." << endl;
}

//searches for the given string first in the assumed address that it needs to be in according to the address calculator method; if it is not present there, it
//starts searching for it according to separate chaining method
void HashTableImproved::search(string key) {
    const int address = addressCalculator(key);
    bool isFound = false;

    for (int j = 0; j < INNER_SIZE && !isFound; j++) {
        if (hashTable[address][j] == key) {
            cout << key << " is a weak spot." << endl;
            isFound = true;
        }
    }

    if (!isFound)
        cout << key << " is not a weak spot." << endl;
}


