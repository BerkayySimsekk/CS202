/**
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 4
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "ListInterface.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();
    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    void insert(int newPosition, const ItemType& newEntry);
    void remove(int position);
    void clear();
    ItemType& getEntry(int position) const;
};

//default constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList() {
    headPtr = nullptr;
    itemCount = 0;
}

//a helper method to get the entry at the given position, used in "getEntry" function
template< class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
    Node<ItemType>* curPtr = headPtr;
    for( int i = 1; i < position; i++)
        curPtr = curPtr->getNext();
    return curPtr ;
}

//a public method to check whether the linked is empty or not
template< class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    return itemCount == 0;
}

//a public method to get the length of the linked list
template< class ItemType>
int LinkedList<ItemType>::getLength() const{
    return itemCount;
}

//a public method to get the item at the given position
template< class ItemType>
ItemType& LinkedList<ItemType>::getEntry(int position) const {
    Node<ItemType>* nodePtr = getNodeAt(position);
    return nodePtr->getItem();
}

//a public method to insert an item to the given position in linked list if the position is valid
template< class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    if(newPosition >= 1 && newPosition <= itemCount + 1) {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        if (newPosition == 1) {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else {
            Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
}

//a public method to remove an item from the linked list found at the given position if it is valid
template<class ItemType>
void LinkedList<ItemType>::remove(int position) {
    if(position >= 1 && position <= itemCount)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1) {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else {
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    }
}

//a public method to remove all the items in the linked list
template< class ItemType>
void LinkedList<ItemType>::clear() {
    while (!isEmpty())
        remove(1);
}

//destructor
template< class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

#endif // LINKEDLIST_H

