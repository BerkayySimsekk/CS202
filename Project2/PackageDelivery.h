/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the interfaces of the functions for the package delivery class.
*/

#ifndef PACKAGEDELIVERY_H
#define PACKAGEDELIVERY_H

#include <string>
#include "Heap.h"
#include "Package.h"
#include "Drone.h"
#include "Task.h"

using namespace std;

class PackageDelivery {
public:
    PackageDelivery(const string droneFile, const string packageFile);
    void simulation();

private:
    Heap<Package*> packageHeap;
    Heap<Drone*> droneHeap;
    Heap<Task*> taskHeap;
};

#endif //PACKAGEDELIVERY_H
