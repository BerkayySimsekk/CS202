/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 4
*/

#include "CyberAttackContainment.h"
#include "ListQueue.h"

#include <fstream>
#include <iostream>

CyberAttackContainment::CyberAttackContainment(const string inputFile) {
    ifstream inputFileNetwork(inputFile);

    string nodeInfo;
    int countForNodeInformation = 1;
    int countForNode = 0;
    size = 1;
    NetworkNode* networkNode;

    //the stream extraction operator is used to ignore the whitespace characters, this part reads the size and information regarding the network nodes
    while (countForNode < size && inputFileNetwork >> nodeInfo) {
        if (countForNodeInformation == 1) {
            size = stoi(nodeInfo);
            networkNodes = new NetworkNode*[size];
        }
        else if (countForNodeInformation == 2) {
            networkNode = new NetworkNode();
            networkNode->setName(nodeInfo);
        } else if (countForNodeInformation == 3) {
            networkNode->setStatus(nodeInfo);
            networkNode->setIndex(countForNode);
            networkNodes[countForNode] = networkNode;
            countForNode++;
            countForNodeInformation = 1;
        }

        countForNodeInformation++;
    }

    countForNodeInformation = 1;
    int countForNumberOfConnections = 0;
    bool isDone = false;
    string firstName;
    string secondName;
    double timeLatency;

    network = new double*[size];

    //the latency between the network nodes are initially set to zero
    for (int i = 0; i < size; i++) {
        network[i] = new double[size];
        for (int j = 0; j < size; j++)
            network[i][j] = -1;
    }

    //the stream extraction operator is used again; however, the latency between the network nodes are read this time
    while (inputFileNetwork >> nodeInfo) {
        if (countForNodeInformation == 1)
            firstName = nodeInfo;
        else if (countForNodeInformation == 2)
            secondName = nodeInfo;
        else if (countForNodeInformation == 3) {
            timeLatency = stod(nodeInfo);
            countForNodeInformation = 0;

            for (int i = 0; i < size && !isDone; i++)
                if (networkNodes[i]->getName() == firstName)
                    for (int j = 0; j < size && !isDone; j++)
                        if (networkNodes[j]->getName() == secondName) {
                            network[i][j] = timeLatency;
                            network[j][i] = timeLatency;
                            isDone = true;
                        }

            isDone = false;
            countForNumberOfConnections++;
        }

        countForNodeInformation++;
    }

    cout << countForNode << " nodes and " << countForNumberOfConnections << " connections are loaded." << endl;
}

CyberAttackContainment::~CyberAttackContainment() {
    for (int i = 0; i < size; i++)
        delete networkNodes[i];
    delete[] networkNodes;

    for (int i = 0; i < size; i++)
        delete[] network[i];
    delete[] network;
}

//the logic used here is the following: the time it takes for the malware nodes to reach all the normal nodes is measured for each of the normal nodes, the time
//it takes for these normal nodes to get infected is updated, the time it takes for the dispatcher nodes to reach all the normal nodes is measured for each of
//the normal nodes, the times for the normal nodes to get infected and secured are compared to determine the status of these nodes
void CyberAttackContainment::nodeStatuses() {
    ListQueue<NetworkNode*> q;
    int timeTook = 1;

    //beginning of the breadth-first search algorithm to measure how long it takes for the malware nodes to reach the normal nodes
    for (int i = 0; i < size; i++)
        if (networkNodes[i]->getStatus() == "malware") {
            q.enqueue(networkNodes[i]);
            networkNodes[i]->setIsVisited(true);
        }
    while (!q.isEmpty()) {
        int layerSize = q.getSize();

        for (int i = 0; i < layerSize; i++) {
            NetworkNode* u = q.peekFront();
            q.dequeue();

            for (int v = 0; v < size; v++)
                if (network[u->getIndex()][v] != -1 && !networkNodes[v]->getIsVisited()) {
                    networkNodes[v]->setIsVisited(true);
                    q.enqueue(networkNodes[v]);

                    if (networkNodes[v]->getStatus() == "normal") {
                        networkNodes[v]->setTimeTookToGetInfected(timeTook);
                        networkNodes[v]->setStatus("malware");
                    }
                }
        }

        timeTook++;
    }

    const double INFINITY = 1e18;
    NetworkNode** vertexSet = new NetworkNode*[size];
    double* latency = new double[size];

    //beginning of the multi-source Dijkstra's algorithm to find how long it takes for the dispatcher nodes to reach the normal nodes
    for (int i = 0; i < size; i++)
        vertexSet[i] = nullptr;
    for (int v = 0; v < size; v++) {
        if (networkNodes[v]->getStatus() == "dispatcher")
            latency[v] = 0;
        else
            latency[v] = INFINITY;
    }
    for (int v = 1; v < size; v++) {
        double smallestLatency = INFINITY;
        int minVertexIndex = -1;

        for (int i = 0; i < size; i++)
            if (vertexSet[i] == nullptr && latency[i] < smallestLatency) {
                minVertexIndex = i;
                smallestLatency = latency[i];
            }

        if (minVertexIndex == -1)
            break;

        vertexSet[minVertexIndex] = networkNodes[minVertexIndex];

        for (int j = 0; j < size; j++)
            if (network[minVertexIndex][j] != -1 && vertexSet[j] == nullptr && latency[j] > latency[minVertexIndex] + network[minVertexIndex][j])
                latency[j] = latency[minVertexIndex] + network[minVertexIndex][j];
    }

    //beginning of the printing process
    cout << "Node states are:" << endl;
    for (int i = 0; i < size; i++) {
        if (latency[i] <= networkNodes[i]->getTimeTookToGetInfected() && networkNodes[i]->getStatus() == "malware") {
            networkNodes[i]->setTimeTookToGetInfected(-1);
            networkNodes[i]->setStatus("dispatcher");
        }

        if (networkNodes[i]->getStatus() == "dispatcher")
            cout << networkNodes[i]->getName() << " secured" << endl;

        if (networkNodes[i]->getStatus() == "malware")
            cout << networkNodes[i]->getName() << " infected" << endl;
    }

    delete[] latency;
    delete[] vertexSet;
}

//the logic used here is the following: if a dispatcher node and a malware node have a connection between them, it is removed; then, a slightly modified BFS
//algorithm is used to find the connected zones after the necessary connections are removed
void CyberAttackContainment::computeConnectedZones() {
    //beginning of the process that removes the connection between different types of nodes
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (network[i][j] != -1 && networkNodes[i]->getStatus() != networkNodes[j]->getStatus())
                network[i][j] = -1;

    ListQueue<NetworkNode*> q;
    bool enterLoop = false;

    for (int i = 0; i < size; i++)
        networkNodes[i]->setIsVisited(false);

    //beginning of the slightly modified BFS algorithm, the modification made here is that instead of starting from a single point and traversing all of the
    //graph, all the nodes in the graph are considered as a possible starting point
    cout << "Connected zones are:" << endl;
    for (int i = 0; i < size; i++) {
        if (!networkNodes[i]->getIsVisited()) {
            q.enqueue(networkNodes[i]);
            networkNodes[i]->setIsVisited(true);
            enterLoop = true;
            cout << networkNodes[i]->getName() << " ";
        }

        while (!q.isEmpty() && enterLoop) {
            NetworkNode* u = q.peekFront();
            q.dequeue();

            for (int v = 0; v < size; v++)
                if (network[u->getIndex()][v] != -1 && !networkNodes[v]->getIsVisited()) {
                    networkNodes[v]->setIsVisited(true);
                    q.enqueue(networkNodes[v]);
                    cout << networkNodes[v]->getName() << " ";
                }
        }

        if (networkNodes[i]->getStatus() == "malware" && enterLoop)
            cout << "infected" << endl;
        if (networkNodes[i]->getStatus() == "dispatcher" && enterLoop)
            cout << "secured" << endl;

        enterLoop = false;
    }
}
