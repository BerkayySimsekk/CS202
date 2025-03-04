/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file contains the implementations of the functions in the header file.
*/

#include "analysis.h"
#include "BST.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//default constructor
analysis::analysis() {}

//a public method that finds the height of the binary search tree and the time taken after every 1000 insertions to the binary search tree
void analysis::timeAnalysis() const {
    srand(time(0));

    int randomNumber;
    double previousTimeTaken = 0;
    BST bst{};

    for(int i = 1; i <= 10; i++) {
        auto startTime = high_resolution_clock::now();

        for(int j = 0; j < 1000; j++) {
            randomNumber = rand();
            bst.insertKeyForConstructor(randomNumber);
        }

        auto endTime = high_resolution_clock::now();
        duration<double> timeTaken = endTime - startTime;

        double totalTimeTaken = timeTaken.count() + previousTimeTaken;
        previousTimeTaken = totalTimeTaken;

        cout << "Time taken after " << i * 1000 << " insertions is " << totalTimeTaken << " seconds." << endl;
        cout << "The height of the tree is: " << bst.getHeight() << endl;
    }
}