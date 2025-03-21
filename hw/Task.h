#ifndef TASK_H
#define TASK_H

#include "Drone.h"
#include "Package.h"

class Task {
public:
    Task();

    Package* getPackage();
    Drone* getDrone();
    void setPackage(Package*);
    void setDrone(Drone*);

private:
    Package* assignedPackage;
    Drone* assignedDrone;
};

#endif //TASK_H
