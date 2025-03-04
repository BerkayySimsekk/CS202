/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file contains both of the interfaces and the implementations of the functions for the node of linked list. This style is preferred due to
*the template declarations.
*/

#ifndef NODE_H
#define NODE_H

#include <cstddef>
using namespace std;

template<class ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next;

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType& getItem();
    Node<ItemType>* getNext();
};

//default constructor
template<class ItemType>
Node<ItemType>::Node() {
    next = nullptr;
}

//constructor that only initializes the given item
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) {
    next = nullptr;
    item = anItem;
}

//constructor that initializes both of the given item and the next node that the current node points to
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) {
    item = anItem;
    next = nextNodePtr;
}

//a public method to set the item of the node
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

//a public method to set the next node that the current node points to
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}

//a public method to get the item of the node
template<class ItemType>
ItemType& Node<ItemType>::getItem() {
    return item;
}

//a public method to get the next node that the current node points to
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() {
    return next;
}

#endif // NODE_H
