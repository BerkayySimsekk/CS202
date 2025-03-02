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
    void displayPostOrder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    int getHeight();
    void insertKeyForConstructor(int key);
    void deleteKeyForConstructor(int key);

private:
    bool searchKey(int key);
    bool search(TreeNode* node, int key);
    TreeNode* insert(TreeNode* root, int value);
    void inorder(TreeNode* node, bool& first);
    void postorder(TreeNode* node, bool& first);
    TreeNode* deleteNode(TreeNode* node, int key);
    TreeNode* findLowestCommonAncestor(TreeNode* node, int A, int B);
    void inorderToArray(TreeNode* node, int arr[], int &index);
    int getHeight(TreeNode* node);

    TreeNode* root;
    int levelOfKey;
    int numberOfNodes;
    int* keysOfNodes;
    bool defaultConstructorIsUsed;
};

#endif //BST_H
