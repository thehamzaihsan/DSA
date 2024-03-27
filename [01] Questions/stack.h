#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    char data;
    Node(char data)
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
    void push(char data);
    char pop();
    void display();
    char top();
    bool isEmpty();
};

void Stack::push(char data)
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

char Stack::pop()
{
    if (head == NULL)
    {
        cout << "UNDERFLOW";
        return 'n';
    }
    else
    {
        Node *tempNode = head;
        head = tempNode->next;
        char temp = tempNode->data;
        delete tempNode;
        return temp;
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

char Stack::top()
{
    if (!isEmpty())
    {
        return head->data;
    }
    else
    {
        return '$';
    }
}

bool Stack::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}