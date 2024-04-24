#include <iostream>
using namespace std;



class Stack
{
public:
    Node *head;
    Stack()
    {
        head = NULL;
    }
    void push(int data);
    int pop();
    void display();
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }
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

int Stack::pop()
{
    if (head == NULL)
    {
        cout << "UNDERFLOW";
        return 0;
    }
    else
    {

        Node *tempNode = head;
        head = tempNode->next;
        int x = tempNode->data;
        delete tempNode;
        return x;
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
