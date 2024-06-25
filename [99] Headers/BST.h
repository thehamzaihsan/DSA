#include <iostream>
#include <stack>
#include "node.h"

using namespace std;

template <typename T>
class BinarySearchTree
{
public:
    BinaryTreeNode<T> *root = nullptr;

    void insert(T data);
    BinaryTreeNode<T> *search(BinaryTreeNode<T> *root, T key);
    void traverse(BinaryTreeNode<T> *root);
    void insertRecursive(BinaryTreeNode<T> *root, T data);
    BinaryTreeNode<T> *searchIterative(T key);
    ~BinarySearchTree();
    bool isEmpty();
    void preOrderTraverse(BinaryTreeNode<T> *root);
    void postOrderTraverse(BinaryTreeNode<T> *root);
    void inOrderTraverse(BinaryTreeNode<T> *root);
    int countLeafNodesRecursive(BinaryTreeNode<T> *root);
    int countNonLeafNodesRecursive(BinaryTreeNode<T> *root);
    int sizeRecursive(BinaryTreeNode<T> *root);
    BinaryTreeNode<T> *findMax(BinaryTreeNode<T> *temp);
    BinaryTreeNode<T> *findMin(BinaryTreeNode<T> *temp);
    void remove(T key);
    int getHeight(BinaryTreeNode<T> *root);
    void levelOrderTraversal(BinaryTreeNode<T> *root);
    void printLevel(BinaryTreeNode<T> *root, int level);
    BinaryTreeNode<T> *constructExpressionTree(const std::string &postfix);

    void PostOrderTraversalItr(){
        stack<BinaryTreeNode<T>*> s1, s2;
        s1.push(root);
        while(!s1.empty()){
            BinaryTreeNode<T>* temp = s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
        }
        while(!s2.empty()){
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }

    
    void inOrderTraversalItr(){
        stack<BinaryTreeNode<T>*> s;
        BinaryTreeNode<T>* temp = root;
        while(temp || !s.empty()){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->val << " ";
            temp = temp->right;
        }
    }

    void preOrderTraversalItr(){
        stack<BinaryTreeNode<T>*> s;
        s.push(root);
        while(!s.empty()){
            BinaryTreeNode<T>* temp = s.top();
            s.pop();
            cout << temp->val << " ";
            if(temp->right){
                s.push(temp->right);
            }
            if(temp->left){
                s.push(temp->left);
            }
        }
    }
};

template <typename T>
void BinarySearchTree<T>::insert(T data)
{
    BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>;
    newNode->val = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

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
void BinarySearchTree<T>::insertRecursive(BinaryTreeNode<T> *root, T data)
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
            insertRecursive(root->left, data);
        }
        else
        {
            insertRecursive(root->right, data);
        }
    }
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::search(BinaryTreeNode<T> *root, T key)
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
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::searchIterative(T key)
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

template <typename T>
void BinarySearchTree<T>::traverse(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    traverse(root->left);
    traverse(root->right);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
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

template <typename T>
bool BinarySearchTree<T>::isEmpty()
{
    return root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::preOrderTraverse(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

template <typename T>
void BinarySearchTree<T>::postOrderTraverse(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->val << " ";
}

template <typename T>
void BinarySearchTree<T>::inOrderTraverse(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderTraverse(root->left);
    cout << root->val << " ";
    inOrderTraverse(root->right);
}

template <typename T>
int BinarySearchTree<T>::countLeafNodesRecursive(BinaryTreeNode<T> *root)
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

template <typename T>
int BinarySearchTree<T>::countNonLeafNodesRecursive(BinaryTreeNode<T> *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return 0;
    }
    return 1 + countNonLeafNodesRecursive(root->left) + countNonLeafNodesRecursive(root->right);
}

template <typename T>
int BinarySearchTree<T>::sizeRecursive(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::findMax(BinaryTreeNode<T> *temp)
{
    if (temp->right == nullptr)
    {
        return temp;
    }
    else
    {
        return findMax(temp->right);
    }
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::findMin(BinaryTreeNode<T> *temp)
{
    if (temp->left == nullptr)
    {
        return temp;
    }
    else
    {
        return findMin(temp->left);
    }
}

template <typename T>
void BinarySearchTree<T>::remove(T key)
{
    BinaryTreeNode<T> *temp = root;
    BinaryTreeNode<T> *deleteNode = search(root, key);
    cout << "DeleteNode: " << deleteNode->val << endl;

    if (deleteNode->left == nullptr && deleteNode->right == nullptr)
    {
        delete deleteNode;
    }
    else if (deleteNode->left == nullptr)
    {
        BinaryTreeNode<T> *tempNode = deleteNode;
        deleteNode = deleteNode->right;
        delete tempNode;
    }
    else if (deleteNode->right == nullptr)
    {
        BinaryTreeNode<T> *tempNode = deleteNode;
        deleteNode = deleteNode->left;
        delete tempNode;
    }
    else if (deleteNode->left != nullptr && deleteNode->right != nullptr)
    {
        BinaryTreeNode<T> *tempNode = findMin(deleteNode->right);
        // cout << "tempNode: " << tempNode->val << endl;
        deleteNode->val = tempNode->val;
        tempNode->val = 0;
        delete tempNode;
    }
}

template <typename T>
int BinarySearchTree<T>::getHeight(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

template <typename T>
void BinarySearchTree<T>::levelOrderTraversal(BinaryTreeNode<T> *root)
{
    int heightTree = getHeight(root);

    for (int i = 0; i < heightTree; i++)
    {
        printLevel(root, i);
    }
}

template <typename T>
void BinarySearchTree<T>::printLevel(BinaryTreeNode<T> *root, int level)
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
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

template <typename T>
BinaryTreeNode<T> *BinarySearchTree<T>::constructExpressionTree(const std::string &postfix)
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
