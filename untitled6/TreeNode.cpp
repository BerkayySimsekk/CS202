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

void TreeNode::setItem(const int& item) {
    this->item = item;
}

void TreeNode::setLeftChildPtr(TreeNode* leftChildPtr) {
    this->leftChildPtr = leftChildPtr;
}

void TreeNode::setRightChildPtr(TreeNode* rightChildPtr) {
    this->rightChildPtr = rightChildPtr;
}

int TreeNode::getItem() const {
    return this->item;
}

TreeNode* TreeNode::getLeftChildPtr() const {
    return this->leftChildPtr;
}

TreeNode* TreeNode::getRightChildPtr() const {
    return this->rightChildPtr;
}

bool TreeNode::isLeaf() const {
    return leftChildPtr == nullptr && rightChildPtr == nullptr;
}






