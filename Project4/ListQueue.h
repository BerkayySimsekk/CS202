/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 4
*/

#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "QueueInterface.h"
#include "LinkedList.h"

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

//default constructor
template<class ItemType>
ListQueue<ItemType>::ListQueue() {
    listPtr = new LinkedList<ItemType>();
    size = 0;
}

//destructor
template<class ItemType>
ListQueue<ItemType>::~ListQueue() {
    delete listPtr;
}

//a public method to get the size of the queue
template<class ItemType>
int ListQueue<ItemType>::getSize() const {
    return size;
}

//a public method to check whether the queue is empty or not
template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const {
    return listPtr->isEmpty();
}

//a public method to add an item to the back of the queue
template<class ItemType>
void ListQueue<ItemType>::enqueue(const ItemType& newEntry) {
    listPtr->insert(listPtr->getLength() + 1, newEntry);
    size++;
}

//a public method to remove an item from the front of the queue
template<class ItemType>
void ListQueue<ItemType>::dequeue() {
    listPtr->remove(1);
    size--;
}

//a public method to get the item at the front of the queue without changing anything
template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const {
    if (!isEmpty())
        return listPtr->getEntry(1);
    return nullptr;
}

#endif //LISTQUEUE_H
