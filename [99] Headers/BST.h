#include <iostream>
#include "node.h"
using namespace std;

class BinarySearchTree
{
public:
    BinaryTreeNode *root = nullptr;
    void Insert(int data);
    void Delete();
    BinarySearchTree()
    {
        root = nullptr;
    }
    BinaryTreeNode *Search(BinaryTreeNode *root, int key);
    void Traverse(BinaryTreeNode *root);
    void InsertRec(int data, BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            BinaryTreeNode *newNode = new BinaryTreeNode;
            newNode->val = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            root = newNode;
        }
        else
        {
            if (data < root->val)
            {
                InsertRec(data, root->left);
            }
            else
            {
                InsertRec(data, root->right);
            }
        }
    }
    BinaryTreeNode *SearchIter(int key)
    {
        BinaryTreeNode *temp = root;
        while (temp != nullptr)
        {
            if (temp->val == key)
            {
                return temp;
            }
            else if (temp->val > key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    ~BinarySearchTree()
    {
        int count = 0;
        BinaryTreeNode *left = root->left;
        BinaryTreeNode *right = root->right;
        delete root;
        count++;
        while (left != nullptr)
        {
            BinaryTreeNode *temp = left;
            left = left->left;
            delete temp;
            count++;
        }
        while (right != nullptr)
        {
            BinaryTreeNode *temp = right;
            right = right->right;
            delete temp;
            count++;
        }

        // cout << "deleted: " << count << endl;
    }
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
        return 1 + countNonLeafNodesRecursive(root->left) + countNonLeafNodesRecursive(root->right);
    }
    int sizeRecursive(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
    }
    BinaryTreeNode *Max(BinaryTreeNode *temp)
    {
        if (temp->right == nullptr)
        {
            return temp;
        }
        else
        {

            return Max(temp->right);
        }
    }
    BinaryTreeNode *Min(BinaryTreeNode *temp)
    {
        if (temp->left == nullptr)
        {
            return temp;
        }
        else
        {
            return Min(temp->left);
        }
    }

    void Delete(int key)
    {
        BinaryTreeNode *temp = root;
        BinaryTreeNode *DeleteNode = Search(root, key);
        cout << "DeleteNode: " << DeleteNode->val << endl;
        if (DeleteNode->left == nullptr && DeleteNode->right == nullptr)
        {
            delete DeleteNode;
        }
        else if (DeleteNode->left == nullptr)
        {
            BinaryTreeNode *tempN = DeleteNode;
            DeleteNode = DeleteNode->right;
            delete tempN;
        }
        else if (DeleteNode->right == nullptr)
        {
            BinaryTreeNode *tempN = DeleteNode;
            DeleteNode = DeleteNode->left;
            delete tempN;
        }
        else if (DeleteNode->left != nullptr && DeleteNode->right != nullptr)
        {
            BinaryTreeNode *tempN = Min(DeleteNode->right);
            // cout << "tempN: " << tempN->val << endl;
            DeleteNode->val = tempN->val;
            tempN->val = 0;
            delete tempN;
        }
    }
    int height(BinaryTreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }

    void levelOrder(BinaryTreeNode *root)
    {

        int height_tree = height(root);

        for (int i = 0; i < height_tree; i++)
        {
            print_height(root, i);
        }
    }

    void print_height(BinaryTreeNode *root, int level)
    {
        if (!root)
        {
            return;
        }
        else
        {
            if (level == 0)
            {
                cout << root->val << " ";
            }
        }
        print_height(root->left, level - 1);
        print_height(root->right, level - 1);
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
            if (newNode->val == temp->val)
            {
                cout << "Duplicate value\n";
                delete newNode;
                break;
            }
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