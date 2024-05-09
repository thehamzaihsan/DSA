#include <iostream>
using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

bool isBST(BinaryTreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->left != nullptr)
    {
        if (root->left->val > root->val)
        {
            return false;
        }
    }
    if (root->right != nullptr)
    {
        if (root->right->val < root->val)
        {
            return false;
        }
    }
    return isBST(root->left) && isBST(root->right);
}

int main()
{
    // write tester for above function.
    BinaryTreeNode *root = new BinaryTreeNode;
    root->val = 10;
    root->left = new BinaryTreeNode;
    root->left->val = 5;
    root->right = new BinaryTreeNode;
    root->right->val = 15;
    root->left->left = new BinaryTreeNode;
    root->left->left->val = 2;
    root->left->right = new BinaryTreeNode;
    root->left->right->val = 0;
    root->right->left = new BinaryTreeNode;
    root->right->left->val = 12;
    root->right->right = new BinaryTreeNode;
    root->right->right->val = 20;
    cout << isBST(root);
    return 0;
}