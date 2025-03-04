/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file contains the pure virtual functions of linked list that must be overridden in the derived classes; in this case, "LinkedList.cpp" file.
*/

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template<class ItemType>
class ListInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual void insert(int newPosition, const ItemType& newEntry) = 0;
    virtual void remove(int position) = 0;
    virtual void clear() = 0;
    virtual ItemType& getEntry(int position) const = 0;
    virtual int getLength() const = 0;
    virtual ~ListInterface() {}
};

#endif //LISTINTERFACE_H