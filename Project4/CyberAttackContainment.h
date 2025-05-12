/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 4
*/

#ifndef CYBERATTACKCONTAINMENT_H
#define CYBERATTACKCONTAINMENT_H

#include "NetworkNode.h"

class CyberAttackContainment {
private:
    NetworkNode** networkNodes;
    double** network;
    int size;

public:
    CyberAttackContainment(const string inputFile);
    ~CyberAttackContainment();
    void nodeStatuses();
    void computeConnectedZones();
};

#endif //CYBERATTACKCONTAINMENT_H
