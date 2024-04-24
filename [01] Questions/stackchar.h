#include <iostream>
using namespace std;



class Stackc
{
public:
    Node *head;
    Stackc()
    {
        head = NULL;
    }
    void push(char data);
    char pop();
    void display();
    char top();
    bool isEmpty();
};

void Stackc::push(char data)
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

char Stackc::pop()
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

void Stackc::display()
{
    Node *tempPointer = head;
    while (tempPointer != NULL)
    {
        cout << tempPointer->data << " ";
        tempPointer = tempPointer->next;
    }
    cout << endl;
}

char Stackc::top()
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

bool Stackc::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}