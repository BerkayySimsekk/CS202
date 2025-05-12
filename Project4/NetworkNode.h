/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 4
*/

#ifndef NETWORKNODE_H
#define NETWORKNODE_H

#include <string>

using namespace std;

class NetworkNode {
public:
    NetworkNode();
    string getStatus();
    void setStatus(const string& newStatus);
    string getName();
    void setName(const string& newName);
    bool getIsVisited();
    void setIsVisited(const bool& newIsVisited);
    int getIndex();
    void setIndex(const int& newIndex);
    int getTimeTookToGetInfected();
    void setTimeTookToGetInfected(const int& newTimeTookToGetInfected);

private:
    string status;
    string name;
    int index;
    int timeTookToGetInfected;
    bool isVisited;
};


#endif //NETWORKNODE_H
