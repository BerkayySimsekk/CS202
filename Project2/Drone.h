/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the interfaces of the functions for the drone class.
*/

#ifndef DRONE_H
#define DRONE_H

class Drone {
public:
    Drone();
    Drone(int droneID, double droneBatteryLife, double droneSpeed);
    int getID() const;
    double getBatteryLife() const;
    double getSpeed() const;
    double getX() const;
    double getY() const;
    void setX(double droneXCoordinate);
    void setY(double droneYCoordinate);
    void setSpeed(double droneSpeed);
    void setID(int droneID);
    void setBatteryLife(double droneBatteryLife);
    bool compareForHeap(Drone* drone) const;

private:
    int ID;
    double batteryLife;
    double speed;
    double x;
    double y;
};

#endif //DRONE_H
