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

    void setItem(const int& item);
    int getItem() const;
    bool isLeaf() const;
    TreeNode* getLeftChildPtr() const;
    TreeNode* getRightChildPtr() const;
    void setLeftChildPtr(TreeNode* leftChildPtr);
    void setRightChildPtr(TreeNode* rightChildPtr);


private:
    int item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
};

#endif //TREENODE_H
