/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file contains the pure virtual functions of queue that must be overridden in the derived classes; in this case, "ListQueue.cpp" file.
*/

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template< class ItemType>
class QueueInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual void enqueue( const ItemType& newEntry) = 0;
    virtual void dequeue() = 0;
    virtual int getSize() const = 0;
    virtual ItemType peekFront() const = 0;
    virtual ~QueueInterface() {}
};

#endif //QUEUEINTERFACE_H
