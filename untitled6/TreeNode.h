/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description :
*/

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    TreeNode();
    TreeNode(const int& item, TreeNode* leftChildPtr, TreeNode* rightChildPtr);

    int item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
};

#endif //TREENODE_H
