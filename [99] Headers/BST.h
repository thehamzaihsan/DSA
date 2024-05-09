#include <iostream>
#include "node.h"
using namespace std;

class BinarySearchTree
{
public:
    BinaryTreeNode *root = nullptr;
    void Insert(int data);
    void Delete();
    BinaryTreeNode *Search(BinaryTreeNode *root, int key);
    void Traverse(BinaryTreeNode *root);
    bool isEmpty()
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void PreOrderTraverse(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->val << " ";
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
    void PostOrderTraverse(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        cout << root->val << " ";
    }
    void InOrderTraverse(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        InOrderTraverse(root->left);
        cout << root->val << " ";
        InOrderTraverse(root->right);
    }

    int countLeafNodesRecursive(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return countLeafNodesRecursive(root->left) + countLeafNodesRecursive(root->right);
    }
    int countNonLeafNodesRecursive(BinaryTreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return 0;
        }
        return 1 + countNonLeafNodesRecursive(root->left) +  countNonLeafNodesRecursive(root->right);
    }
    int sizeRecursive(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
    }
};

void BinarySearchTree::Insert(int data)
{
    BinaryTreeNode *newNode = new BinaryTreeNode;
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        BinaryTreeNode *temp = root;
        while (temp != nullptr)
        {
            if (data < temp->val)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void BinarySearchTree::Traverse(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    Traverse(root->left);
    Traverse(root->right);
}

BinaryTreeNode *BinarySearchTree::Search(BinaryTreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == key)
    {
        return root;
    }
    else
    {
        if (root->val > key)
        {
            return Search(root->left, key);
        }
        else
        {
            return Search(root->right, key);
        }
    }
}