#include "PackageDelivery.h"

#include <fstream>
#include <iostream>

PackageDelivery::PackageDelivery(const string droneFile, const string packageFile) {
    ifstream inputFilePackage(packageFile);

    double number;
    int count = 1;
    Package* package;

    while(inputFilePackage >> number) {
        if(count == 1)
            packageHeap.heapSetSize(0);
        else if(count == 2) {
            package = new Package();
            package->setID(number);
        }
        else if(count == 3)
            package->setX(number);
        else if(count == 4)
            package->setY(number);
        else if(count == 5)
            package->setWeight(number);
        else if(count == 6) {
            package->setPriority(number);
            packageHeap.heapInsertPackage(package);
            count = 1;
        }

        count++;
    }

    inputFilePackage.close();

    ifstream inputFileDrone(droneFile);

    count = 1;
    Drone* drone;

    while(inputFileDrone >> number) {
        if(count == 1) {
            droneHeap.heapSetSize(0);
        }
        else if(count == 2) {
            drone = new Drone();
            drone->setID(number);
        }
        else if(count == 3)
            drone->setBatteryLife(number);
        else if(count == 4) {
            drone->setSpeed(number);
            droneHeap.heapInsertDrone(drone);
            count = 1;
        }

        count++;
    }

    inputFileDrone.close();
}