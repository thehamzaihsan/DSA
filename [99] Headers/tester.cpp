#include <iostream>
using namespace std;
// #include "./doubly-circular-list.h"
// #include "./circular-list.h"
#include "BST.h"

int main()
{
   
   BinarySearchTree tree;
   int choice;
   do
   {
      cout << "1. Insert\n2. Count Leaf Nodes\n3. Count Nodes\n4. Count Non-Leaf Nodes\n5. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         int data;
         cout << "Enter data: ";
         cin >> data;
         tree.Insert(data);
         break;
      case 2:
         cout << "Leaf Nodes: " << tree.countLeafNodesRecursive(tree.root) << endl;
         break;
      case 3:
         cout << "Nodes: " << tree.sizeRecursive(tree.root) << endl;
         break;
      case 4:
         cout << "Non-Leaf Nodes: " << tree.countNonLeafNodesRecursive(tree.root) << endl;
         break;
      case 5:
         cout << "Exiting...";
         break;
      default:
         cout << "Invalid choice\n";
         break;
      }
   } while (choice != 5);
  
}