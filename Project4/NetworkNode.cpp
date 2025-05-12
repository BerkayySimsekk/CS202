/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 4
*/

#include "NetworkNode.h"

NetworkNode::NetworkNode() {
    status = "";
    name = "";
    isVisited = false;
    index = -1;
    timeTookToGetInfected = -1;
}

string NetworkNode::getStatus() {
    return status;
}

void NetworkNode::setStatus(const string& newStatus) {
    status = newStatus;
}

string NetworkNode::getName() {
    return name;
}

void NetworkNode::setName(const string& newName) {
    name = newName;
}

bool NetworkNode::getIsVisited() {
    return isVisited;
}

void NetworkNode::setIsVisited(const bool& newIsVisited) {
    isVisited = newIsVisited;
}

int NetworkNode:: getIndex() {
    return index;
}

void NetworkNode:: setIndex(const int& newIndex) {
    index = newIndex;
}

int NetworkNode:: getTimeTookToGetInfected() {
    return timeTookToGetInfected;
}

void NetworkNode:: setTimeTookToGetInfected(const int& newTimeTookToGetInfected) {
    timeTookToGetInfected = newTimeTookToGetInfected;
}