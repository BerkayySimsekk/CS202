/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the implementations of the functions for the hash table.
*/

#include "HashTable.h"
#include <iostream>

//constructor which assigns every string in the hash table to "Empty" and sets the size to 0
HashTable::HashTable() {
    currentSize = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = "Empty";
}

//calculates the address of the given string by summing up the ASCII values of the characters and getting the remainder of the sum by dividing it with the
//fixed table size
int HashTable::addressCalculator(string key) {
    int sumOfASCIIValues = 0;

    for (int i = 0; i < key.length(); i++)
        sumOfASCIIValues += key[i];

    return sumOfASCIIValues % SIZE;
}

//inserts the key if the given address is "Empty" or "Deleted"; if the given address is not available, quadratic probing method is used to handle it
void HashTable::insert(string key) {
    const int address = addressCalculator(key);

    if (currentSize < SIZE) {
        if (hashTable[address] == "Empty" || hashTable[address] == "Deleted") {
            hashTable[address] = key;
            currentSize++;
            cout << key << " is registered as a weak spot." << endl;
        }
        else {
            int valueForQuadraticProbing = 1;
            bool isInserted = false;
            int newAddress;

            while (!isInserted) {
                newAddress = (address + valueForQuadraticProbing * valueForQuadraticProbing) % SIZE;

                if (hashTable[newAddress] == "Empty" || hashTable[newAddress] == "Deleted") {
                    hashTable[newAddress] = key;
                    currentSize++;
                    isInserted = true;
                    cout << key << " is registered as a weak spot." << endl;
                }
                else
                    valueForQuadraticProbing++;
            }
        }
    }
    else
        cout << "Hash table is full." << endl;
}

//removes the given string if it can be found in the table, and sets that found address to "Deleted"
void HashTable::remove(string key) {
    const int address = searchForRemoval(key);

    if (address == -1)
        cout << key << " is not present." << endl;
    else {
        hashTable[address] = "Deleted";
        currentSize--;
        cout << key << " is deleted." << endl;
    }
}

//searches for the given string first in the assumed address that it needs to be in according to the address calculator method; if it is not present there, it
//starts searching for it according to quadratic probing method
void HashTable::search(string key) {
    const int address = addressCalculator(key);
    int newAddress = address;

    if (hashTable[newAddress] == key)
        cout << key << " is a weak spot." << endl;
    else {
        int valueForQuadraticProbing = 1;
        bool isFinished = false;

        while (!isFinished) {
            newAddress = (address + valueForQuadraticProbing * valueForQuadraticProbing) % SIZE;

            if (hashTable[newAddress] == key) {
                cout << key << " is a weak spot." << endl;
                isFinished = true;
            }
            else if (hashTable[newAddress] == "Empty") {
                cout << key << " is not a weak spot." << endl;
                isFinished = true;
            }
            else
                valueForQuadraticProbing++;
        }
    }
}

//a modified version of the previous search method, that acts the same except for the fact that it does not print out any messages and it returns the
//address in which the key can be found in the table
int HashTable::searchForRemoval(string key) {
    const int address = addressCalculator(key);
    int newAddress = address;

    if (hashTable[newAddress] == key)
        return newAddress;

    int valueForQuadraticProbing = 1;

    while (true) {
        newAddress = (address + valueForQuadraticProbing * valueForQuadraticProbing) % SIZE;

        if (hashTable[newAddress] == "Empty")
            return -1;

        if (hashTable[newAddress] == key)
            return newAddress;

        valueForQuadraticProbing++;
    }
}
