#include "Drone.h"

Drone::Drone() {
    ID = -1;
    batteryLife = -1;
    speed = -1;
}

Drone::Drone(int droneID, double droneBatteryLife, double droneSpeed) {
    ID = droneID;
    batteryLife = droneBatteryLife;
    speed = droneSpeed;
}

int Drone::getX() const {
    return x;
}

int Drone::getY() const {
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

void Drone::setX(int droneXCoordinate) {
    x = droneXCoordinate;
}

void Drone::setY(int droneYCoordinate) {
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

