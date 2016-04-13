#include "btNode.h"
#include <iostream>


void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

// write definition for bst_insert here


void bst_insert(btNode*& bst_root, int insInt)
{
    //std::cout << insInt ;
    bool stop = false;
    if(bst_root == 0)
    {
        btNode* newNode = new btNode;
        newNode->data = insInt;
        newNode->left = 0;
        newNode->right = 0;
        bst_root = newNode;
    }

    btNode* curr = bst_root;
    while(stop == false)
    {
        if(insInt < curr->data)
        {
            if(curr->left == 0)
            {
                btNode* newNode = new btNode;
                newNode->data = insInt;
                newNode->left = 0;
                newNode->right = 0;
                curr->left = newNode;
                stop = true;
            }
            else
            {
                curr = curr->left;
            }
        }
        else if(insInt > curr->data)
        {
            if(curr->right == 0)
            {
                btNode* newNode = new btNode;
                newNode->data = insInt;
                newNode->left = 0;
                newNode->right = 0;
                curr->right = newNode;
                stop = true;
            }
            else
            {
                curr = curr->right;
            }
        }
        else
        {
            curr->data = insInt;
            stop = true;
        }
    }
}


//write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int remInt)
{
    if(bst_root == 0)
    {
        return false;
    }
    if(bst_root->data == remInt)
    {
        if(bst_root->right == 0 && bst_root->left == 0)
        {
            delete bst_root;
            bst_root = 0;
        }
        else if (bst_root->right == 0 && bst_root->left != 0)
        {
            btNode* temp = bst_root->left;
            delete bst_root;
            bst_root = temp;
        }
        else if (bst_root->right != 0 && bst_root->left == 0)
        {
            btNode* temp = bst_root->right;
            delete bst_root;
            bst_root = temp;
        }
        else
        {
            bst_remove_max(bst_root->left, bst_root);
        }
        return true;
    }
    return remInt < bst_root->data ?
    bst_remove(bst_root->left, remInt) : bst_remove(bst_root->right, remInt);
    return false;
}
// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, btNode*& deleted)
{
    if(bst_root->right == 0)
    {
        deleted->data = bst_root->data;
        btNode* temp = bst_root->left;
        delete bst_root;
        bst_root = temp;
    }
    else
    {
        bst_remove_max(bst_root->right, deleted);
    }
    
}
