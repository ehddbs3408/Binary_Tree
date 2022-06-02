#include "bt.h"

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode* nd = new BTreeNode; //make binary tree
    nd->left = NULL; //initialize
    nd->right = NULL; //initialize
    return nd; //return pointer
}

void DeleteBTreeNode(BTreeNode* bt) {
    delete bt;
}

int GetData(BTreeNode* bt) {
    return bt->data;
}

void SetData(BTreeNode* bt, int data) {
    bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    if (main->left != NULL)
    {
        delete main->left;
    }
    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    if (main->right != NULL)
    {
        delete main->right;
    }
    main->right = sub;
}