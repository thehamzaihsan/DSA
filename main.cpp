#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* Search (Node *root , int key){
    if(root == nullptr) {
        return nullptr;
    }
    if(root->data == key){
        return root;
    }
    else{
        if(root->data > key){
            return Search(root->left, key);
        }
        else{
            return Search(root->right, key);
        }
    }
}


int main() {
   //generate BST
    Node* root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 5;
    root->right = new Node();
    root->right->data = 15;
    root->left->left = new Node();
    root->left->left->data = 3;
    root->left->right = new Node();
    root->left->right->data = 7;
    root->right->left = new Node();
    root->right->left->data = 12;
    root->right->right = new Node();
    root->right->right->data = 20;
    //search for 7
    Node* result = Search(root, 7);
    if(result != nullptr){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
}
