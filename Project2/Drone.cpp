/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the implementations of the methods that can be seen in the header file.
*/

#include "Drone.h"

Drone::Drone() {
    ID = -1;
    batteryLife = -1;
    speed = -1;
    x = 0;
    y = 0;
}

Drone::Drone(int droneID, double droneBatteryLife, double droneSpeed) {
    ID = droneID;
    batteryLife = droneBatteryLife;
    speed = droneSpeed;
    x = 0;
    y = 0;
}

double Drone::getX() const {
    return x;
}

double Drone::getY() const {
    return y;
}

int Drone::getID() const {
    return ID;
}

double Drone::getBatteryLife() const {
    return batteryLife;
}

double Drone::getSpeed() const {
    return speed;
}

void Drone::setX(double droneXCoordinate) {
    x = droneXCoordinate;
}

void Drone::setY(double droneYCoordinate) {
    y = droneYCoordinate;
}

void Drone::setBatteryLife(double droneBatteryLife) {
    batteryLife = droneBatteryLife;
}

void Drone::setSpeed(double droneSpeed) {
    speed = droneSpeed;
}

void Drone::setID(int droneID) {
    ID = droneID;
}

bool Drone::compareForHeap(Drone* drone) const {
    if(batteryLife > drone->batteryLife)
        return true;
    else if(batteryLife < drone->batteryLife)
        return false;
    else
        return ID < drone->ID;
}

