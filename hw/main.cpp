#include <iostream>
#include "Heap.h"
#include "PackageDelivery.h"

using namespace std;

int main() {
    string f = "package.txt";
    string m = "drone.txt";

    PackageDelivery* p = new PackageDelivery(m, f);


    p->droneHeap.heapDeleteDrone();
    p->droneHeap.heapDeleteDrone();
    p->droneHeap.heapDeleteDrone();
    //p->packageHeap.heapDeleteDrone();
    if(!p->droneHeap.heapIsEmpty())
        cout << p->droneHeap.heapGetRoot()->getBatteryLife();



}
