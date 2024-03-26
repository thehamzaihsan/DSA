#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
    }
    Node();
};

class Stack
{
public:
    Node *head;
    Stack()
    {
        head = NULL;
    }
    void push(int data);
    void pop();
    void display();
};

void Stack::push(int data)
{
    if (head == NULL)
    {
        Node *newHead = new Node(data);
        newHead->next = NULL;
        head = newHead;
    }
    else
    {
        Node *newHead = new Node(data);
        newHead->next = head;
        head = newHead;
    }
}

void Stack::pop()
{
    if (head == NULL)
    {
        cout << "UNDERFLOW";
    }
    else
    {

        Node *tempNode = head;
        head = tempNode->next;
        delete tempNode;
    }
}

void Stack::display()
{
    Node *tempPointer = head;
    while (tempPointer != NULL)
    {
        cout << tempPointer->data << " ";
        tempPointer = tempPointer->next;
    }
    cout << endl;
}
