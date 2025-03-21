#ifndef DRONE_H
#define DRONE_H

class Drone {
public:
    Drone();
    Drone(int droneID, double droneBatteryLife, double droneSpeed);
    int getID() const;
    double getBatteryLife() const;
    double getSpeed() const;
    int getX() const;
    int getY() const;
    void setX(int droneXCoordinate);
    void setY(int droneYCoordinate);
    void setSpeed(double droneSpeed);
    void setID(int droneID);
    void setBatteryLife(double droneBatteryLife);

private:
    int ID;
    double batteryLife;
    double speed;
    int x;
    int y;
};

#endif //DRONE_H
