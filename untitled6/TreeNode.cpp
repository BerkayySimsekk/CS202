/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description :
*/

#include "TreeNode.h"

TreeNode::TreeNode() {
    item = 0;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

TreeNode::TreeNode(const int& item, TreeNode* leftChildPtr, TreeNode* rightChildPtr) {
    this->item = item;
    this->leftChildPtr = leftChildPtr;
    this->rightChildPtr = rightChildPtr;
}






