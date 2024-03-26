#include <iostream>
using namespace std;

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
    Node *Front= NULL;
    Node *Rear = NULL;

    void Enqueue(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next_link = NULL;
        if (Front== NULL)
        {
            Front= temp;
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


    void Dequeue()
    {
        Node *tempNode = Front;
        Front = tempNode->next_link;
        delete tempNode;
    }
    
};


int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Traverse();
    q.Dequeue();
    q.Traverse();
}