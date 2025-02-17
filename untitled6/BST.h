/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description :
*/

#ifndef BST_H
#define BST_H

#include "TreeNode.h"

class BST {
public:
    BST();
    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void keyLevel(int key);
    void displayInorder();
    void displayPostOrder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();

private:
    TreeNode* root;
};

#endif //BST_H
