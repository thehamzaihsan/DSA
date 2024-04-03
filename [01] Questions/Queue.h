#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next_link;
};

class Queue
{
public:
    Node *Front = NULL;
    Node *Rear = NULL;

    bool isEmpty()
    {
        if (Front == NULL && Rear == NULL)
        {
            return true;
        }
        return false;
    }

    void Enqueue(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next_link = NULL;
        if (Front == NULL)
        {
            Front = temp;
            Rear = temp;
        }
        else
        {
            Rear->next_link = temp;
            Rear = temp;
        }
    }

    void Traverse()
    {
        Node *tempPointer = Front;
        while (tempPointer != NULL)
        {
            cout << tempPointer->data << " ";
            tempPointer = tempPointer->next_link;
        }
        cout << endl;
    }

    int Dequeue()
    {
        Node *tempNode = Front;
        Front = tempNode->next_link;
        int x = tempNode -> data;
        delete tempNode;
        return x;
    }
};
