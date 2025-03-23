/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains the implementations of the methods that can be seen in the header file.
* The "fstream" C++ library header is used to read the text files that includes information for the drones and
* packages
*/

#include "PackageDelivery.h"

#include <fstream>
#include <iostream>

//Inside the loops to read the text files for the drones and packages the white spaces and the end of lines are automatically
//disregarded. Hence, the double values can be directly read by keeping a count and resetting it at the final count.
PackageDelivery::PackageDelivery(const string droneFile, const string packageFile) {
    ifstream inputFilePackage(packageFile);

    double number;
    int count = 1;
    Package *package;

    //First loop to read the text file for packages
    while (inputFilePackage >> number) {
        if (count == 1)
            packageHeap.heapSetSize(0);
        else if (count == 2) {
            package = new Package();
            package->setID(number);
        } else if (count == 3)
            package->setX(number);
        else if (count == 4)
            package->setY(number);
        else if (count == 5)
            package->setWeight(number);
        else if (count == 6) {
            package->setPriority(number);
            packageHeap.heapInsert(package);
            count = 1;
        }

        count++;
    }

    inputFilePackage.close();

    ifstream inputFileDrone(droneFile);

    count = 1;
    Drone *drone;

    //Second loop to read the text file for drones
    while (inputFileDrone >> number) {
        if (count == 1) {
            droneHeap.heapSetSize(0);
        } else if (count == 2) {
            drone = new Drone();
            drone->setID(number);
        } else if (count == 3)
            drone->setBatteryLife(number);
        else if (count == 4) {
            drone->setSpeed(number);
            droneHeap.heapInsert(drone);
            count = 1;
        }

        count++;
    }

    inputFileDrone.close();
}

void PackageDelivery::simulation() {
    bool isGameOver = false;
    Task *currentTask = nullptr;
    bool shouldEnterCooldown = false;
    int tick = 0;

    while (!isGameOver) {
        //Check whether we should enter cooldown or not, entering cooldown increases the tick by 5 and starts the cooldown process.
        if (currentTask != nullptr && shouldEnterCooldown) {
            cout << "Drone " << currentTask->getDrone()->getID() << " Package " << currentTask->getPackage()->getID() << " at tick " << tick << " cool down" << endl;

            tick += COOLDOWN_PERIOD;
            currentTask->startCooldown();
            shouldEnterCooldown = false;
        }

        //Check if we should assign a drone and a package to the task if we don't have currently a task. We check if the drone can
        //perform its job here since when the "isEnteringCooldown" method is called, its speed is updated accordingly.
        if (currentTask == nullptr && droneHeap.heapGetSize() > 0 && packageHeap.heapGetSize() > 0) {
            Drone* availableDrone = droneHeap.heapGetRoot();
            Package* availablePackage = packageHeap.heapGetRoot();
            droneHeap.heapDelete();
            packageHeap.heapDelete();

            Task* task = new Task();
            task->setDrone(availableDrone);
            task->setPackage(availablePackage);
            currentTask = task;
            shouldEnterCooldown = currentTask->isEnteringCooldown();
            taskHeap.heapInsert(task);
        }

        //Entering here would mean that the size of the heap for packages is 0. Hence, we should exit the loop. Checking whether
        //the heap for task is empty or not is just a safeguard.
        if (currentTask == nullptr) {
            if (taskHeap.heapGetSize() > 0) {
                currentTask = taskHeap.heapGetRoot();
            } else {
                isGameOver = true;
            }
        }

        //Entering here would mean, we definitely have a currently assigned task and the drone can perform its job. Hence,
        //we should set the necessary values for the drone, insert the drone back to the heap for drones, and increase the
        //tick by one.
        if (!isGameOver && !shouldEnterCooldown) {
            currentTask->getDrone()->setX(currentTask->getPackage()->getX());
            currentTask->getDrone()->setY(currentTask->getPackage()->getY());
            currentTask->getDrone()->setBatteryLife(currentTask->getDrone()->getBatteryLife() - currentTask->getCompletionTime());

            droneHeap.heapInsert(currentTask->getDrone());

            cout << "Drone " << currentTask->getDrone()->getID() << " Package " << currentTask->getPackage()->getID() << " at tick " << tick << " (delivery time: " << currentTask->getCompletionTime() << ", battery life: " << currentTask->getDrone()->getBatteryLife() << ")" << endl;

            taskHeap.heapDelete();
            currentTask = nullptr;

            tick++;
        }
        else
            shouldEnterCooldown = true;
    }
}