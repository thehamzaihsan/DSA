#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};
class BinaryTree
{
public:
    Node *root;
    BinaryTree(){
        root = nullptr;
    }
    Node *insert(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    
    void Traverse(Node *root)
    {
        Node *temp = root;
        if (temp != nullptr)
        {
            cout << temp->data << " ";
            Traverse(temp->left);
            Traverse(temp->right);
        }
        else{
            return;
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.root = tree.insert(1);
    tree.root->left = tree.insert(2);
    tree.root->right = tree.insert(3);
    tree.root->left->left = tree.insert(4);
    tree.root->left->right = tree.insert(5);
    tree.root->right->left = tree.insert(6);
    tree.Traverse(tree.root);
}