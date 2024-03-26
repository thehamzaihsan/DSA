#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data_t)
    {
        data = data_t;
        next = NULL;
        prev = NULL;
    }
    Node();
};

int main()
{
    // adding two new nodes
    Node *head = new Node(15);
    Node *end = new Node(20);
    head->next = end;
    end->prev = head;

    // adding a new node in between
    Node *new_Node = new Node(17);
    Node *oldSecond = head->next;
    head->next = new_Node;
    new_Node->prev = head;
    new_Node->next = oldSecond;
    oldSecond->prev = new_Node;

    // displaying the list
    cout << head->data << " " << head->next->data << " " << head->next->next->data << endl;

    // deleting the second node
    Node *Second = head->next;
    head->next = Second->next;
    head->next->prev = head;
    delete Second;

    // displaying the list
    cout << head->data << " " << head->next->data << endl;
}
