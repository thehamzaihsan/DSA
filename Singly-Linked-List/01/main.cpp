// Task 3: Write a code snippet to create two nodes with data elements and link them with each other. (Do not use head pointer here)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next_link;
};

int main()
{
    Node *nodeAlpha = new Node;
    nodeAlpha->data = 1;
    nodeAlpha->next_link = NULL;
    Node *nodeBeta = new Node;
    nodeBeta->data = 2;
    nodeBeta->next_link = NULL;
    nodeAlpha->next_link = nodeBeta;
    return 0;
}
