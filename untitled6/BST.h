/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file only contains the function interfaces for the binary search tree.
*/

#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "ListQueue.cpp"

using namespace std;

class BST {
public:
    BST();
    BST(int keys[], int size);
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void keyLevel(int key);
    void displayInorder();
    void displayPostorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    int getHeight();
    void insertKeyForConstructor(int key);
    void deleteKeyForConstructor(int key);

private:
    bool searchKey(int key);
    bool search(BSTNode* node, int key);
    BSTNode* insert(BSTNode* root, int value);
    void inorder(BSTNode* node, bool& first);
    void postorder(BSTNode* node, bool& first);
    BSTNode* deleteNode(BSTNode* node, int key);
    BSTNode* findLowestCommonAncestor(BSTNode* node, int A, int B);
    void inorderToArray(BSTNode* node, int arr[], int &index);
    void findMaxSumPath(BSTNode* node, int currentSum, int &maxSum, LinkedList<int>& currentPath, LinkedList<int>& maxPathList);
    int getHeight(BSTNode* node);
    void destroyTree(BSTNode* ptr);

    BSTNode* root;
    int levelOfKey;
};

#endif //BST_H
