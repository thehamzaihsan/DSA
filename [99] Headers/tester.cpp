#include <iostream>
using namespace std;
// #include "./doubly-circular-list.h"
// #include "./circular-list.h"
#include "BST.h"

int main()
{
   BinarySearchTree BST;
   BST.Insert(14);
   BST.Insert(2);
   BST.Insert(1);
   BST.Insert(3);
   BST.Insert(11);
   BST.Insert(10);
   BST.Insert(7);
   BST.Insert(30);
   BST.Insert(40);
   BST.PostOrderTraverse(BST.root);
   // BST.LeafNodes(BST.root);
   // if(BST.Search(BST.root , 8) != nullptr){
   //    cout << "Found";
   // }
   // else{
   //    cout << "Not Found";
   // }
}