/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 2
* Description : This file contains both the interfaces of the functions for the drone class and the implementations of these methods due
* to the usage of templates.
*/

#ifndef HEAP_H
#define HEAP_H

const int MAX_HEAP = 50;

template<class HeapItemType>
class Heap {
public:
    Heap();

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete();
    int heapGetSize() const;
    void heapSetSize(int heapSize);
    HeapItemType& heapGetRoot();

private:
    HeapItemType items[MAX_HEAP];
    int size;

    void heapRebuild(int root);
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
void Heap<HeapItemType>::heapRebuild(int root) {
    int child = 2 * root + 1;
    if (child < size) {
        int rightChild = child + 1;

        if (rightChild < size && items[rightChild]->compareForHeap(items[child]))
            child = rightChild;

        if (items[child]->compareForHeap(items[root])) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}

template<class HeapItemType>
void Heap<HeapItemType>::heapInsert(const HeapItemType& newItem) {
    if (size < MAX_HEAP) {
        items[size] = newItem;

        int place = size;
        int parent = (place - 1) / 2;
        while (place > 0 && items[place]->compareForHeap(items[parent])) {
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
void Heap<HeapItemType>::heapDelete() {
    if (!heapIsEmpty()) {
        items[0] = items[--size];
        heapRebuild(0);
    }
}

#endif //HEAP_H
