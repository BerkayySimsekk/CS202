/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file contains the interfaces of the functions for the node of binary search tree.
*/

#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode {
public:
    int item;
    BSTNode* leftChildPtr;
    BSTNode* rightChildPtr;

    BSTNode(int val, BSTNode* leftNode = nullptr, BSTNode* rightNode = nullptr)
        : item(val), leftChildPtr(leftNode), rightChildPtr(rightNode) {}
};

#endif //BSTNODE_H
