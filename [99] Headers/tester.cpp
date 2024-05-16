#include <iostream>
using namespace std;
// #include "./doubly-circular-list.h"
// #include "./circular-list.h"
#include "BST.h"

int main()
{
   // BinarySearchTree tree;
   // int choice;
   // do
   // {
   //    cout << "1. Insert\n2. Count Leaf Nodes\n3. Count Nodes\n4. Count Non-Leaf Nodes\n5. Find Maximum\n6. Find Minimum\n7. Exit\n";
   //    cout << "Enter your choice: ";
   //    cin >> choice;
   //    switch (choice)
   //    {
   //    case 1:
   //       int data;
   //       cout << "Enter data: ";
   //       cin >> data;
   //       tree.Insert(data);
   //       break;
   //    case 2:
   //       cout << "Leaf Nodes: " << tree.countLeafNodesRecursive(tree.root) << endl;
   //       break;
   //    case 3:
   //       cout << "Nodes: " << tree.sizeRecursive(tree.root) << endl;
   //       break;
   //    case 4:
   //       cout << "Non-Leaf Nodes: " << tree.countNonLeafNodesRecursive(tree.root) << endl;
   //       break;
   //    case 5:
   //       if (tree.root == nullptr)
   //       {
   //          cout << "Tree is empty\n";
   //       }
   //       else
   //       {
   //          cout << "Maximum: " << tree.Max(tree.root->right)->val << endl;
   //       }
   //       break;
   //    case 6:
   //       if (tree.root == nullptr)
   //       {
   //          cout << "Tree is empty\n";
   //       }
   //       else
   //       {
   //          // cout << "Minimum: " << tree.Min(tree.root)->data << endl;
   //       }
   //       break;
   //    case 7:
   //       cout << "Exiting...";
   //       break;
   //    default:
   //       cout << "Invalid choice\n";
   //       break;
   //    }
   // } while (choice != 7);
   BinarySearchTree tree; 
   tree.Insert(10);
   tree.Insert(5);
   tree.Insert(15);
   tree.Insert(3);
   tree.Insert(7);
   tree.Insert(12);
   tree.Insert(18);
   tree.Insert(1);
   tree.Insert(4);
   tree.Insert(6);
   tree.Insert(8);
   tree.Insert(11);
   tree.Insert(13);

   tree.InOrderTraverse(tree.root);
   cout << endl;
   tree.PostOrderTraverse(tree.root);
   cout << endl;
   tree.PreOrderTraverse(tree.root);
   cout << endl;
   // tree.InOrderTraverse(tree.root);
}