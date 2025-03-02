#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "QueueInterface.h"
#include "LinkedList.cpp"

template<class ItemType>
class ListQueue : public QueueInterface<ItemType> {
private:
    LinkedList<ItemType>* listPtr;
    int size;
public:
    ListQueue();
    ~ListQueue();
    bool isEmpty() const;
    void enqueue(const ItemType& newEntry);
    void dequeue();
    int getSize() const;
    ItemType peekFront() const;
};

template<class ItemType>
ListQueue<ItemType>::ListQueue() {
    listPtr = new LinkedList<ItemType>();
    size = 0;
}

template<class ItemType>
ListQueue<ItemType>::~ListQueue() {
    delete listPtr;
}

template<class ItemType>
int ListQueue<ItemType>::getSize() const {
    return size;
}

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const {
    return listPtr->isEmpty();
}

template<class ItemType>
void ListQueue<ItemType>::enqueue(const ItemType& newEntry) {
    listPtr->insert(listPtr->getLength() + 1, newEntry);
    size++;
}

template<class ItemType>
void ListQueue<ItemType>::dequeue() {
    listPtr->remove(1);
    size--;
}

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const {
    if (!isEmpty())
        return listPtr->getEntry(1);
    return nullptr;
}

#endif //LISTQUEUE_H
