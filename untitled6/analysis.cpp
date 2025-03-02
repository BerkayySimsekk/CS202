#include "analysis.h"
#include "BST.h"

#include <iostream>
#include <ctime>

using namespace std;

analysis::analysis() {}

void analysis::timeAnalysis() const {
    srand(time(0));

    int randomNumber;
    double previousTimeTaken = 0;
    BST bst{};

    for(int i = 1; i <= 10; i++) {
        clock_t startTime = clock();
        for(int j = 0; j < 1000; j++) {
            randomNumber = rand();
            bst.insertKeyForConstructor(randomNumber);
        }
        clock_t endTime = clock();

        double timeTaken = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC + previousTimeTaken;
        previousTimeTaken = timeTaken;

        cout << "Time taken after " << i * 1000 << " insertions is " << timeTaken << " seconds." << endl;
        cout << "The height of the tree is: " << bst.getHeight() << endl;
    }
}