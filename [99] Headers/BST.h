#include <iostream>
#include <stack>
#include "node.h"
using namespace std;

template <typename T>
class BinarySearchTree
{
public:
    BinaryTreeNode<T> *root = nullptr;
    void Insert(T data);
    void Delete();
    BinarySearchTree()
    {
        root = nullptr;
    }
    BinaryTreeNode<T> *Search(BinaryTreeNode<T> *root, T key);
    void Traverse(BinaryTreeNode<T> *root);
    void InsertRec(BinaryTreeNode<T> *root, T data)
    {
        if (root == nullptr)
        {
            BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>;
            newNode->val = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            root = newNode;
        }
        else
        {
            if (data < root->val)
            {
                InsertRec(root->left, data);
            }
            else
            {
                InsertRec(root->right, data);
            }
        }
    }
    BinaryTreeNode<T> *SearchIter(T key)
    {
        BinaryTreeNode<T> *temp = root;
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
        return nullptr;
    }
    ~BinarySearchTree()
    {
        int count = 0;
        BinaryTreeNode<T> *left = root->left;
        BinaryTreeNode<T> *right = root->right;
        delete root;
        count++;
        while (left != nullptr)
        {
            BinaryTreeNode<T> *temp = left;
            left = left->left;
            delete temp;
            count++;
        }
        while (right != nullptr)
        {
            BinaryTreeNode<T> *temp = right;
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
    void PreOrderTraverse(BinaryTreeNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->val << " ";
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
    void PostOrderTraverse(BinaryTreeNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        cout << root->val << " ";
    }
    void InOrderTraverse(BinaryTreeNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        InOrderTraverse(root->left);
        cout << root->val << " ";
        InOrderTraverse(root->right);
    }

    int countLeafNodesRecursive(BinaryTreeNode<T> *root)
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
    int countNonLeafNodesRecursive(BinaryTreeNode<T> *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return 0;
        }
        return 1 + countNonLeafNodesRecursive(root->left) + countNonLeafNodesRecursive(root->right);
    }
    int sizeRecursive(BinaryTreeNode<T> *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
    }
    BinaryTreeNode<T> *Max(BinaryTreeNode<T> *temp)
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
    BinaryTreeNode<T> *Min(BinaryTreeNode<T> *temp)
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

    void Delete(T key)
    {
        BinaryTreeNode<T> *temp = root;
        BinaryTreeNode<T> *DeleteNode = Search(root, key);
        cout << "DeleteNode: " << DeleteNode->val << endl;
        if (DeleteNode->left == nullptr && DeleteNode->right == nullptr)
        {
            delete DeleteNode;
        }
        else if (DeleteNode->left == nullptr)
        {
            BinaryTreeNode<T> *tempN = DeleteNode;
            DeleteNode = DeleteNode->right;
            delete tempN;
        }
        else if (DeleteNode->right == nullptr)
        {
            BinaryTreeNode<T> *tempN = DeleteNode;
            DeleteNode = DeleteNode->left;
            delete tempN;
        }
        else if (DeleteNode->left != nullptr && DeleteNode->right != nullptr)
        {
            BinaryTreeNode<T> *tempN = Min(DeleteNode->right);
            // cout << "tempN: " << tempN->val << endl;
            DeleteNode->val = tempN->val;
            tempN->val = 0;
            delete tempN;
        }
    }
    int height(BinaryTreeNode<T> *root)
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

    void levelOrder(BinaryTreeNode<T> *root)
    {

        int height_tree = height(root);

        for (int i = 0; i < height_tree; i++)
        {
            print_height(root, i);
        }
    }

    void print_height(BinaryTreeNode<T> *root, int level)
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
    
    BinaryTreeNode<T> *constructExpressionTree(const std::string &postfix)
    {
        std::stack<BinaryTreeNode<T> *> stack;

        for (char ch : postfix)
        {
            if (std::isalnum(ch))
            { // Check if the character is an operand
                BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>;
                newNode->val = ch;
                stack.push(newNode);
            }
            else
            { // The character is an operator
                BinaryTreeNode<T> *rightNode = stack.top();
                stack.pop();
                BinaryTreeNode<T> *leftNode = stack.top();
                stack.pop();
                BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>;
                newNode->val = ch;
                newNode->left = leftNode;
                newNode->right = rightNode;
                stack.push(newNode);
            }
        }

        // The last element in the stack is the root of the expression tree
        return stack.top();
    }
>
};

template <typename T>
void BinarySearchTree<T>::Insert(T data)
{
    BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>;
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        BinaryTreeNode<T> *temp = root;
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

template <typename T>
void BinarySearchTree<T>::Traverse(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    Traverse(root->left);
    Traverse(root->right);
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::Search(BinaryTreeNode<T> *root, T key)
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
