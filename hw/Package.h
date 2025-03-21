#ifndef PACKAGE_H
#define PACKAGE_H

class Package {
public:
    Package();
    Package(int packageID, int packageXCoordinate, int packageYCoordinate, int packagePriority, double packageWeight);
    int getID() const;
    int getX() const;
    int getY() const;
    int getPriority() const;
    double getWeight() const;
    void setID(int packageID);
    void setX(int packageXCoordinate);
    void setY(int packageYCoordinate);
    void setPriority(int packagePriority);
    void setWeight(double packageWeight);

private:
    int ID;
    int x;
    int y;
    int priority;
    double weight;
};

#endif //PACKAGE_H
