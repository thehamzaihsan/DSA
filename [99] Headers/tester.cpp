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
   

   return 0;
}