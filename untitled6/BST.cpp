/**
* Title: Binary Search Trees
* Author : Berkay Simsek
* ID: 22303338
* Section : 2
* Homework : 1
* Description :
*/

#include "BST.h"

#include "ListQueue.cpp"

#include <iostream>
#include <cmath>

using namespace std;

//default constructor
BST::BST() {
    root = nullptr;
    levelOfKey = 1;
    numberOfNodes = 0;
    keysOfNodes = nullptr;
    defaultConstructorIsUsed = true;
}

//if the keys and the size are given for the constructor, BST is created using those values
BST::BST(int keys[], int size) {
    root = nullptr;
    levelOfKey = 1;
    numberOfNodes = size;
    keysOfNodes = new int[numberOfNodes];
    defaultConstructorIsUsed = false;

    for (int i = 0; i < numberOfNodes; i++)
        keysOfNodes[i] = keys[i];

    for(int i = 0; i < size; i++)
        insertKeyForConstructor(keys[i]);
}

BST::~BST() {
    if(keysOfNodes == nullptr) {
        int index = 0;
        keysOfNodes = new int[numberOfNodes];
        inorderToArray(root, keysOfNodes, index);
    }

    for(int i = 0; i < numberOfNodes; i++)
        deleteKeyForConstructor(keysOfNodes[i]);
}

int BST::getHeight(TreeNode* node) {
    if (node == nullptr) {
        return -1;
    }
    return max(getHeight(node->leftChildPtr), getHeight(node->rightChildPtr)) + 1;
}

void BST::inorderToArray(TreeNode* node, int arr[], int &index) {
    if (node == nullptr)
        return;

    inorderToArray(node->leftChildPtr, arr, index);
    arr[index++] = node->item;
    inorderToArray(node->rightChildPtr, arr, index);
}

//helper method to insert items
TreeNode* BST::insert(TreeNode* root, int value) {
    if(root == nullptr)
        return new TreeNode(value, nullptr, nullptr);

    if(value < root->item)
        root->leftChildPtr = insert(root->leftChildPtr, value);
    else
        root->rightChildPtr = insert(root->rightChildPtr, value);

    return root;
}

//helper method to check whether a key exists in the BST
bool BST::search(TreeNode* node, int key) {
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
TreeNode* findMin(TreeNode* node) {
    while (node->leftChildPtr != nullptr) {
        node = node->leftChildPtr;
    }
    return node;
}


//helper method to delete an item from the BST
TreeNode* BST::deleteNode(TreeNode* node, int key) {
    if (node == nullptr) return node;

    if (key < node->item) {
        node->leftChildPtr = deleteNode(node->leftChildPtr, key);
    } else if (key > node->item) {
        node->rightChildPtr = deleteNode(node->rightChildPtr, key);
    } else {
        if (node->leftChildPtr == nullptr) {
            TreeNode* temp = node->rightChildPtr;
            delete node;
            return temp;
        } else if (node->rightChildPtr == nullptr) {
            TreeNode* temp = node->leftChildPtr;
            delete node;
            return temp;
        }

        TreeNode* temp = findMin(node->rightChildPtr);  // Find inorder successor
        node->item = temp->item;  // Replace node with successor value
        node->rightChildPtr = deleteNode(node->rightChildPtr, temp->item); // Delete successor
    }
    return node;
}

//helper method for inorder traversal
void BST::inorder(TreeNode* node, bool& first) {
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
void BST::postorder(TreeNode* node, bool& first) {
    if (node == nullptr)
        return;

    postorder(node->leftChildPtr, first);
    postorder(node->rightChildPtr, first);
    if(!first)
        cout << ", ";
    cout << node->item;
    first = false;
}

//a private method to search if the given key exists in the BST
bool BST::searchKey(int key) {
    return search(root, key);
}

//a private method to find the lowest common ancestor of the given keys
TreeNode* BST:: findLowestCommonAncestor(TreeNode* node, int A, int B) {
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

//a public method to insert the key to BST in the constructor
void BST::insertKeyForConstructor(int key) {
    if(!searchKey(key)) {
        root = insert(root, key);

        if(defaultConstructorIsUsed)
            numberOfNodes++;
    }
}

void BST::deleteKeyForConstructor(int key) {
    if(searchKey(key)) {
        root = deleteNode(root, key);

        if(defaultConstructorIsUsed)
            numberOfNodes--;
    }
}

int BST::getHeight() {
    return getHeight(root) + 1;
}

void findMaxSumPath(TreeNode* node, int currentSum, int &maxSum, LinkedList<int>& currentPath, LinkedList<int>& maxPathList){
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

//a public method for inserting the key to BST if the given key does not already exist
void BST::insertKey(int key) {
    if(searchKey(key))
        cout << "Key " << key << " is not added! It already exists in the BST." << endl;
    else {
        root = insert(root, key);
        cout << "Key " << key << " is added!" << endl;

        if(defaultConstructorIsUsed)
            numberOfNodes++;
    }
}

//a public method to delete the given key if it exists
void BST::deleteKey(int key) {
    if(!searchKey(key))
        cout << "Key " << key << " is not deleted. It does not exists in the BST." << endl;
    else {
        root = deleteNode(root, key);
        cout << "Key " << key << " is deleted." << endl;

        if(defaultConstructorIsUsed)
            numberOfNodes--;
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
void BST::displayPostOrder() {
    cout << "Postorder display is: ";
    bool first = true;
    postorder(root, first);
    cout << endl;
}

//a public method that finds the maximum level at which the tree is a full binary tree
void BST::findFullBTLevel() {
    ListQueue<TreeNode*> q;
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
            TreeNode* node = q.peekFront();
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


void BST::lowestCommonAncestor(int A, int B) {
    bool bothKeysExists = searchKey(A) && searchKey(B);

    if(bothKeysExists) {
        TreeNode* lowestCommonAncestor = findLowestCommonAncestor(root, A, B);
        cout << "Lowest common ancestor of " << A << " and " << B << " is: " << lowestCommonAncestor->item << endl;
    }
    else
        cout << "Key does not exist." << endl;
}

void BST::maximumSumPath() {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }

    int maxSum = INT_MIN;  // Track the highest sum found
    LinkedList<int> currentPath;  // Path being explored
    LinkedList<int> maxPathList;  // Path with maximum sum

    // Call the recursive helper
    findMaxSumPath(root, 0, maxSum, currentPath, maxPathList);

    // Print the results
    cout << "Maximum sum path is: ";
    for (int i = 1; i <= maxPathList.getLength(); i++) {
        if(i == maxPathList.getLength())
            cout << maxPathList.getEntry(i);
        else
            cout << maxPathList.getEntry(i) << ", ";
    }
    cout << endl;
}

void BST::maximumWidth() {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }

    ListQueue<TreeNode*> q;
    q.enqueue(root);
    int level = 1;
    int maxWidth = 0;
    int maxWidthLevel = 1;

    LinkedList<int> maxWidthNodes;

    while (!q.isEmpty()) {
        int size = q.getSize();

        LinkedList<int> currentLevelNodes;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.peekFront();
            q.dequeue();

            currentLevelNodes.insert(currentLevelNodes.getLength() + 1, node->item);

            if (node->leftChildPtr) q.enqueue(node->leftChildPtr);
            if (node->rightChildPtr) q.enqueue(node->rightChildPtr);
        }

        if (size > maxWidth) {
            maxWidth = size;
            maxWidthLevel = level;

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



