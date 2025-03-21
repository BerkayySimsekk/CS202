#include "Package.h"

Package::Package() {
    ID = -1;
    x = -1;
    y = -1;
    priority = -1;
    weight = -1;
}

Package::Package(int packageID, int packageXCoordinate, int packageYCoordinate, int packagePriority, double packageWeight) {
    ID = packageID;
    x = packageXCoordinate;
    y = packageYCoordinate;
    priority = packagePriority;
    weight = packageWeight;
}

int Package::getID() const {
    return ID;
}

int Package::getX() const {
    return x;
}

int Package::getY() const {
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

void Package::setX(int packageXCoordinate) {
    x = packageXCoordinate;
}

void Package::setY(int packageYCoordinate) {
    y = packageYCoordinate;
}

void Package::setPriority(int packagePriority) {
    priority = packagePriority;
}

void Package::setWeight(double packageWeight) {
    weight = packageWeight;
}


