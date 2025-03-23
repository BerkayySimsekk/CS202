/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the implementations of the methods that can be seen in the header file.
*/

#include "Package.h"

Package::Package() {
    ID = -1;
    x = -1;
    y = -1;
    priority = -1;
    weight = -1;
}

Package::Package(int packageID, int packageXCoordinate, int packageYCoordinate, int packagePriority, int packageWeight) {
    ID = packageID;
    x = packageXCoordinate;
    y = packageYCoordinate;
    priority = packagePriority;
    weight = packageWeight;
}

int Package::getID() const {
    return ID;
}

double Package::getX() const {
    return x;
}

double Package::getY() const {
    return y;
}

int Package::getPriority() const {
    return priority;
}

double Package::getWeight() const {
    return weight;
}

void Package::setID(int packageID) {
    ID = packageID;
}

void Package::setX(double packageXCoordinate) {
    x = packageXCoordinate;
}

void Package::setY(double packageYCoordinate) {
    y = packageYCoordinate;
}

void Package::setPriority(int packagePriority) {
    priority = packagePriority;
}

void Package::setWeight(double packageWeight) {
    weight = packageWeight;
}

bool Package::compareForHeap(Package* package) const {
    return priority > package->priority;
}


