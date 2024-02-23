#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next_link;
};

class LinkedList
{
public:
    Node *Head = NULL;
    Node *Tail = NULL;

    void InsertNodeEnd(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next_link = NULL;
        if (Head == NULL)
        {
            Head = temp;
            Tail = temp;
        }
        else
        {
            Tail->next_link = temp;
            Tail = temp;
        }
    }

    void Traverse()
    {
        Node *tempPointer = Head;
        while (tempPointer != NULL)
        {
            cout << tempPointer->data << endl;
            tempPointer = tempPointer->next_link;
        }
    }

    void InsertNodeStart(int data)
    {
        Node *newHead = new Node;
        newHead->data = data;
        newHead->next_link = Head;
        Head = newHead;
    }

    void DeleteHeadNode()
    {
        Node *tempNode = Headuuuuuuuujj;
        Head = tempNode->next_link;
        delete tempNode;
    }
    void DeleteNodeEnd()
    {
        Node *newTail = Head;
        while (true)
        {
            // finding the actual new tail
            if (newTail->next_link == Tail)
            {
                Node *oldTail = Tail;
                Tail = newTail;
                Tail->next_link = NULL;
                delete oldTail;
                break;
            }
            else
            {
                newTail = newTail->next_link;
            }
        }
    }
    void DeleteNodeNumber(int data)
    {
        Node *ptr = Head;
        while(){
    
        }       
    }

};

int main()
{
    LinkedList myList;
    myList.InsertNodeEnd(8);
    myList.InsertNodeEnd(10);
    myList.InsertNodeEnd(11);
    myList.InsertNodeStart(7);
    myList.DeleteNodeNumber(2);
    myList.Traverse();
}
