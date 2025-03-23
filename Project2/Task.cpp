/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the implementations of the methods that can be seen in the header file.
*/

#include "Task.h"
#include <cmath>

using namespace std;

Task::Task() {
    assignedPackage = nullptr;
    assignedDrone = nullptr;
    completionTime = 0;
}

Task::Task(Package* assignedPackageToTask, Drone* assignedDroneToTask) {
    assignedPackage = assignedPackageToTask;
    assignedDrone = assignedDroneToTask;
    completionTime = 0;
}

void Task::setPackage(Package* packageToSet) {
    assignedPackage = packageToSet;
}

void Task::setDrone(Drone* droneToSet) {
    assignedDrone = droneToSet;
}

Package* Task::getPackage() const {
    return assignedPackage;
}

Drone* Task::getDrone() const {
    return assignedDrone;
}

double Task::getCompletionTime() const{
    return completionTime;
}

double Task::truncateToOneDecimal(double number) {
    int temp = static_cast<int>(number * 10);
    return static_cast<double>(temp) / 10.0;
}

double Task::calculateCompletionTime() {
    double effectiveSpeed = assignedDrone->getSpeed() * (1 - WEIGHT_FACTOR * assignedPackage->getWeight() / MAX_PACKAGE_WEIGHT);
    effectiveSpeed = effectiveSpeed * (1 - BATTERY_FACTOR * (1 - assignedDrone->getBatteryLife() / MAX_BATTERY));
    effectiveSpeed = truncateToOneDecimal(effectiveSpeed);

    double distance = sqrt((assignedDrone->getX() - assignedPackage->getX()) * (assignedDrone->getX() - assignedPackage->getX()) + (assignedDrone->getY() - assignedPackage->getY()) * (assignedDrone->getY() - assignedPackage->getY()));
    distance = truncateToOneDecimal(distance);

    completionTime = distance / effectiveSpeed;
    completionTime = truncateToOneDecimal(completionTime);

    return completionTime;
}

bool Task::compareForHeap(Task* task) {
    if(assignedPackage->getPriority() > task->getPackage()->getPriority())
        return true;
    else if(assignedPackage->getPriority() < task->getPackage()->getPriority())
        return false;
    else
        return completionTime < task->getCompletionTime();
}

bool Task::isEnteringCooldown() {
    return calculateCompletionTime() > assignedDrone->getBatteryLife();
}

void Task::startCooldown() {
    assignedDrone->setX(0);
    assignedDrone->setY(0);
    assignedDrone->setBatteryLife(MAX_BATTERY);

    completionTime = calculateCompletionTime();
}


