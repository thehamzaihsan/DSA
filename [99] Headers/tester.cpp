#include <iostream>
using namespace std;
// #include "./doubly-circular-list.h"
// #include "./circular-list.h"
// #include "BST.h"
// #include "GraphMatrix.h"
#include "GraphList.h"


int main(){
   // GraphMatrix g(5, 5);
   // g.addedges({0, 1});
   // g.addedges({0, 2});
   // g.addedges({1, 2});
   // g.addedges({1, 3});
   // g.display();

   GraphList g(5);
   g.addedges({0, 1});
   g.addedges({0, 2});
   g.addedges({1, 2});
   g.addedges({1, 3});
   g.display();

   // BinarySearchTree<int> tree;
   // tree.insert(10);
   // tree.insert(5);
   // tree.insert(15);
   // tree.insert(3);
   // tree.insert(7);
   // tree.insert(12);
   // tree.insert(18);
   // tree.insert(1);
   // tree.insert(4);
   // tree.insert(6);
   // tree.postOrderTraverse(tree.root);
   // cout << endl;
   // tree.PostOrderTraversalItr();
   
   

   return 0;
}