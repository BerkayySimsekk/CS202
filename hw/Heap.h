#ifndef HEAP_H
#define HEAP_H

const int MAX_HEAP = 50;

template<class HeapItemType>
class Heap {
public:
    Heap();

    bool heapIsEmpty() const;
    void heapInsertPackage(const HeapItemType& newItem);
    void heapInsertDrone(const HeapItemType& newItem);
    void heapDeletePackage();
    void heapDeleteDrone();
    int heapGetSize() const;
    void heapSetSize(int heapSize);
    HeapItemType& heapGetRoot();

private:
    HeapItemType items[MAX_HEAP];
    int size;

    void heapRebuildPackage(int root);
    void heapRebuildDrone(int root);
};

template<class HeapItemType>
Heap<HeapItemType>::Heap() {
    size = 0;
}

template<class HeapItemType>
int Heap<HeapItemType>::heapGetSize() const {
    return size;
}

template<class HeapItemType>
void Heap<HeapItemType>::heapSetSize(int heapSize) {
    size = heapSize;
}


template<class HeapItemType>
bool Heap<HeapItemType>::heapIsEmpty() const {
    return size == 0;
}

template<class HeapItemType>
HeapItemType& Heap<HeapItemType>::heapGetRoot() {
    return items[0];
}

template<class HeapItemType>
void Heap<HeapItemType>::heapRebuildPackage(int root) {
    int child = 2 * root + 1;
    if (child < size) {
        int rightChild = child + 1;

        if (rightChild < size && items[rightChild]->getPriority() > items[child]->getPriority())
            child = rightChild;

        if (items[root]->getPriority() < items[child]->getPriority()) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuildPackage(child);
        }
    }
}

template<class HeapItemType>
void Heap<HeapItemType>::heapRebuildDrone(int root) {
    int child = 2 * root + 1;
    if (child < size) {
        int rightChild = child + 1;

        if (rightChild < size && items[rightChild]->getBatteryLife() > items[child]->getBatteryLife())
            child = rightChild;

        if (items[root]->getBatteryLife() < items[child]->getBatteryLife()) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuildDrone(child);
        }
    }
}

template<class HeapItemType>
void Heap<HeapItemType>::heapInsertPackage(const HeapItemType& newItem) {
    if (size < MAX_HEAP) {
        items[size] = newItem;

        int place = size;
        int parent = (place - 1) / 2;
        while (place > 0 && items[place]->getPriority() > items[parent]->getPriority()) {
            HeapItemType temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
        }
        ++size;
    }
}

template<class HeapItemType>
void Heap<HeapItemType>::heapInsertDrone(const HeapItemType& newItem) {
    if (size < MAX_HEAP) {
        items[size] = newItem;

        int place = size;
        int parent = (place - 1) / 2;
        while (place > 0 && items[place]->getBatteryLife() > items[parent]->getBatteryLife()) {
            HeapItemType temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
        }
        ++size;
    }
}

template<class HeapItemType>
void Heap<HeapItemType>::heapDeletePackage() {
    if (!heapIsEmpty()) {
        items[0] = items[--size];
        heapRebuildPackage(0);
    }
}

template<class HeapItemType>
void Heap<HeapItemType>::heapDeleteDrone() {
    if (!heapIsEmpty()) {
        items[0] = items[--size];
        heapRebuildDrone(0);
    }
}

#endif //HEAP_H
