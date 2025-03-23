/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the interfaces of the functions for the package class.
*/

#ifndef PACKAGE_H
#define PACKAGE_H

class Package {
public:
    Package();
    Package(int packageID, int packageXCoordinate, int packageYCoordinate, int packagePriority, int packageWeight);
    int getID() const;
    double getX() const;
    double getY() const;
    int getPriority() const;
    double getWeight() const;
    void setID(int packageID);
    void setX(double packageXCoordinate);
    void setY(double packageYCoordinate);
    void setPriority(int packagePriority);
    void setWeight(double packageWeight);
    bool compareForHeap(Package* package) const;

private:
    int ID;
    double x;
    double y;
    int priority;
    double weight;
};

#endif //PACKAGE_H
