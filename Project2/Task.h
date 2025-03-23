/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the interfaces of the functions for the task class.
*/

#ifndef TASK_H
#define TASK_H

#include "Drone.h"
#include "Package.h"

const double MAX_PACKAGE_WEIGHT = 10;
const double WEIGHT_FACTOR = 0.2;
const double BATTERY_FACTOR = 0.3;
const int COOLDOWN_PERIOD = 5;
const double MAX_BATTERY = 300;

class Task {
public:
    Task();
    Task(Package* assignedPackageToTask, Drone* assignedDroneToTask);

    Package* getPackage() const;
    Drone* getDrone() const;
    double getCompletionTime() const;
    void setPackage(Package* packageToSet);
    void setDrone(Drone* droneToSet);
    bool compareForHeap(Task* task);
    bool isEnteringCooldown();
    void startCooldown();
    double calculateCompletionTime();
    double truncateToOneDecimal(double number);

private:
    Package* assignedPackage;
    Drone* assignedDrone;
    double completionTime;
};

#endif //TASK_H
