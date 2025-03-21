#ifndef PACKAGEDELIVERY_H
#define PACKAGEDELIVERY_H

#include <string>
#include "Heap.h"
#include "Package.h"
#include "Drone.h"
#include "Task.h"

using namespace std;

const double MAX_PACKAGE_WEIGHT = 10;
const double WEIGHT_FACTOR = 0.2;
const double BATTERY_FACTOR = 0.3;
const int COOLDOWN_PERIOD = 5;
const double MAX_BATTERY = 300;

class PackageDelivery {
public:
    PackageDelivery(const string droneFile, const string packageFile);
    void simulation();

    Heap<Package*> packageHeap;
    Heap<Drone*> droneHeap;
    Heap<Task*> taskHeap;
};

#endif //PACKAGEDELIVERY_H
