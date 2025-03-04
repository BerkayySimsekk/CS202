/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description : This file contains the implementations of the methods that can be seen in the header file of binary search tree. The "cmath" C++ library header
* is only used for the power function (pow(x,y)).
*/

#include "BST.h"

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

//default constructor
BST::BST() {
    root = nullptr;
    levelOfKey = 1;

    cout << "BST with size 0 created." << endl;
}

//if the keys and the size are given for the constructor, BST is created using those values
BST::BST(int keys[], int size) {
    root = nullptr;
    levelOfKey = 1;

    for(int i = 0; i < size; i++)
        insertKeyForConstructor(keys[i]);

    cout << "BST with size " << size << " created." << endl;
}

//there are two different cases for the destructor depending on which constructor type is used
BST::~BST() {
    destroyTree(root);
}

void BST::destroyTree(BSTNode* ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->leftChildPtr);
        destroyTree(ptr->rightChildPtr);
        delete ptr;
    }
}

//helper method to find the height of the tree
int BST::getHeight(BSTNode* node) {
    if (node == nullptr) {
        return -1;
    }
    return max(getHeight(node->leftChildPtr), getHeight(node->rightChildPtr)) + 1;
}

//helper method to turn the BST into an array, used in destructor
void BST::inorderToArray(BSTNode* node, int arr[], int &index) {
    if (node == nullptr)
        return;

    inorderToArray(node->leftChildPtr, arr, index);
    arr[index++] = node->item;
    inorderToArray(node->rightChildPtr, arr, index);
}

//helper method to insert items
BSTNode* BST::insert(BSTNode* root, int value) {
    if(root == nullptr)
        return new BSTNode(value, nullptr, nullptr);

    if(value < root->item)
        root->leftChildPtr = insert(root->leftChildPtr, value);
    else
        root->rightChildPtr = insert(root->rightChildPtr, value);

    return root;
}

//helper method to check whether a key exists in the BST
bool BST::search(BSTNode* node, int key) {
    if(node == nullptr)
        return false;

    if(node->item == key)
        return true;
    else if (key < node->item) {
        levelOfKey++;
        return search(node->leftChildPtr, key);
    }
    else {
        levelOfKey++;
        return search(node->rightChildPtr, key);
    }
}

//helper method to find the node with the minimum value, used in deletion
BSTNode* findMin(BSTNode* node) {
    while (node->leftChildPtr != nullptr) {
        node = node->leftChildPtr;
    }
    return node;
}


//helper method to delete an item from the BST
BSTNode* BST::deleteNode(BSTNode* node, int key) {
    if (node == nullptr)
        return node;

    if (key < node->item) {
        node->leftChildPtr = deleteNode(node->leftChildPtr, key);
    } else if (key > node->item) {
        node->rightChildPtr = deleteNode(node->rightChildPtr, key);
    } else {
        if (node->leftChildPtr == nullptr) {
            BSTNode* temp = node->rightChildPtr;
            delete node;
            return temp;
        } else if (node->rightChildPtr == nullptr) {
            BSTNode* temp = node->leftChildPtr;
            delete node;
            return temp;
        }

        BSTNode* temp = findMin(node->rightChildPtr);  // Find inorder successor
        node->item = temp->item;  // Replace node with successor value
        node->rightChildPtr = deleteNode(node->rightChildPtr, temp->item); // Delete successor
    }
    return node;
}

//helper method for inorder traversal
void BST::inorder(BSTNode* node, bool& first) {
    if (node == nullptr)
        return;

    inorder(node->leftChildPtr, first);
    if(!first)
        cout << ", ";
    cout << node->item;
    first = false;
    inorder(node->rightChildPtr, first);
}

//helper method for postorder traversal
void BST::postorder(BSTNode* node, bool& first) {
    if (node == nullptr)
        return;

    postorder(node->leftChildPtr, first);
    postorder(node->rightChildPtr, first);
    if(!first)
        cout << ", ";
    cout << node->item;
    first = false;
}

//helper method to find the path from root to a leaf node which has the maximum sum of the keys included in the path
void BST::findMaxSumPath(BSTNode* node, int currentSum, int &maxSum, LinkedList<int>& currentPath, LinkedList<int>& maxPathList){
    if (node == nullptr)
        return;

    currentPath.insert(currentPath.getLength() + 1, node->item);
    currentSum += node->item;

    if (node->leftChildPtr == nullptr && node->rightChildPtr == nullptr) {
        if (currentSum > maxSum) {
            maxSum = currentSum;

            maxPathList.clear();
            for (int i = 1; i <= currentPath.getLength(); i++) {
                int val = currentPath.getEntry(i);
                maxPathList.insert(maxPathList.getLength() + 1, val);
            }
        }
    } else {
        findMaxSumPath(node->leftChildPtr,  currentSum, maxSum, currentPath, maxPathList);
        findMaxSumPath(node->rightChildPtr, currentSum, maxSum, currentPath, maxPathList);
    }

    currentPath.remove(currentPath.getLength());
}

//a private method to search if the given key exists in the BST
bool BST::searchKey(int key) {
    return search(root, key);
}

//a private method to find the lowest common ancestor of the given keys
BSTNode* BST:: findLowestCommonAncestor(BSTNode* node, int A, int B) {
    if (node == nullptr)
        return nullptr;

    if (node->item == A || node->item == B)
        return node;

    if (A < node->item && B < node->item)
        return findLowestCommonAncestor(node->leftChildPtr, A, B);

    if (A > node->item && B > node->item)
        return findLowestCommonAncestor(node->rightChildPtr, A, B);

    return node;
}

//a public method to insert the key to BST in the constructor, it should be used if there should not be any printing operations
void BST::insertKeyForConstructor(int key) {
    if(!searchKey(key))
        root = insert(root, key);

}

//a public method to delete the given key from the BST in the constructor, it should be used if there should not be any printing operations
void BST::deleteKeyForConstructor(int key) {
    if(searchKey(key))
        root = deleteNode(root, key);

}

//a public method to get the height of the tree
int BST::getHeight() {
    return getHeight(root) + 1;
}

//a public method for inserting the key to BST if the given key does not already exist
void BST::insertKey(int key) {
    if(searchKey(key))
        cout << "Key " << key << " is not added! It already exists in the BST." << endl;
    else {
        root = insert(root, key);
        cout << "Key " << key << " is added!" << endl;
    }
}

//a public method to delete the given key if it exists
void BST::deleteKey(int key) {
    if(!searchKey(key))
        cout << "Key " << key << " is not deleted. It does not exist in the BST." << endl;
    else {
        root = deleteNode(root, key);
        cout << "Key " << key << " is deleted." << endl;
    }
}

//a public method to find the level of the given key in the BST
void BST::keyLevel(int key) {
    levelOfKey = 1;
    if(!searchKey(key))
        cout << "Key does not exists." << endl;
    else
        cout << "The level of key " << key << " is: " << levelOfKey << endl;
}

//a public method to display the inorder traversal of the BST
void BST::displayInorder() {
    cout << "Inorder display is: ";
    bool first = true;
    inorder(root, first);
    cout << endl;
}

//a public method to display the postorder traversal of the BST
void BST::displayPostorder() {
    cout << "Postorder display is: ";
    bool first = true;
    postorder(root, first);
    cout << endl;
}

//a public method that finds the maximum level at which the tree is a full binary tree
void BST::findFullBTLevel() {
    ListQueue<BSTNode*> q;
    q.enqueue(root);
    int level = 1;
    int maxFullLevel = -1;
    bool isDone = false;

    while (!q.isEmpty() && !isDone) {
        int size = q.getSize();
        bool isFull = true;

        if (size != pow(2, level - 1))
            isDone = true;

        for (int i = 0; i < size && !isDone; i++) {
            BSTNode* node = q.peekFront();
            q.dequeue();

            int childCount = (node->leftChildPtr ? 1 : 0) + (node->rightChildPtr ? 1 : 0);

            if (childCount == 1) {
                isFull = false;
            }

            if (node->leftChildPtr) q.enqueue(node->leftChildPtr);
            if (node->rightChildPtr) q.enqueue(node->rightChildPtr);
        }

        if(isFull && !isDone){
            maxFullLevel = level;
        }

        if(!isDone)
            level++;
    }

    if(maxFullLevel != -1)
        cout << "Full binary tree level is: " << maxFullLevel << endl;
    else
        cout << "The tree is empty." << endl;
}

//public method to find the lowest common ancestor of the given keys A and B, it also checks if the give keys exist in the BST
void BST::lowestCommonAncestor(int A, int B) {
    bool bothKeysExists = searchKey(A) && searchKey(B);

    if(bothKeysExists) {
        BSTNode* lowestCommonAncestor = findLowestCommonAncestor(root, A, B);
        cout << "Lowest common ancestor of " << A << " and " << B << " is: " << lowestCommonAncestor->item << endl;
    }
    else
        cout << "Key does not exist." << endl;
}

//a public method to find the path from root a leaf node which has the maximum sum of the keys included in the path
void BST::maximumSumPath() {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }

    int maxSum = INT_MIN;
    LinkedList<int> currentPath;
    LinkedList<int> maxPathList;

    findMaxSumPath(root, 0, maxSum, currentPath, maxPathList);

    cout << "Maximum sum path is: ";
    for (int i = 1; i <= maxPathList.getLength(); i++) {
        if(i == maxPathList.getLength())
            cout << maxPathList.getEntry(i);
        else
            cout << maxPathList.getEntry(i) << ", ";
    }
    cout << endl;
}

//a public method to find the level of the tree which has the maximum number of nodes and displays its keys from left to right
void BST::maximumWidth() {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }

    ListQueue<BSTNode*> q;
    q.enqueue(root);
    int level = 1;
    int maxWidth = 0;

    LinkedList<int> maxWidthNodes;

    while (!q.isEmpty()) {
        int size = q.getSize();

        LinkedList<int> currentLevelNodes;

        for (int i = 0; i < size; i++) {
            BSTNode* node = q.peekFront();
            q.dequeue();

            currentLevelNodes.insert(currentLevelNodes.getLength() + 1, node->item);

            if (node->leftChildPtr) q.enqueue(node->leftChildPtr);
            if (node->rightChildPtr) q.enqueue(node->rightChildPtr);
        }

        if (size > maxWidth) {
            maxWidth = size;

            maxWidthNodes.clear();
            for (int i = 1; i <= currentLevelNodes.getLength(); i++) {
                int dataValue = currentLevelNodes.getEntry(i);
                maxWidthNodes.insert(maxWidthNodes.getLength() + 1, dataValue);
            }
        }

        level++;
    }

    cout << "Maximum width level is: ";
    for (int i = 1; i <= maxWidthNodes.getLength(); i++) {
        if(i == maxWidthNodes.getLength())
            cout << maxWidthNodes.getEntry(i);
        else
            cout << maxWidthNodes.getEntry(i) << ", ";
    }
    cout << endl;
}




