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
            cout << tempPointer->data << " ";
            tempPointer = tempPointer->next_link;
        }
        cout << endl;
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
        Node *tempNode = new Node;
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
    }
    void InsertArbitrary(int key, int data)
    {
        Node *temp = new Node;
        temp->data = data;
        Node *ptr = Head;
        while (true)
        {
            if (ptr->data == key)
            {
                temp->next_link = ptr->next_link;
                ptr->next_link = temp;
                break;
            }
            else
            {
                ptr = ptr->next_link;
            }
        }
    }
};

bool Search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Found" << endl;
            return true;
        }
        temp = temp->next_link;
    }
    cout << "Not Found" << endl;
    return false;
}

int main()
{

    LinkedList myList;
    myList.InsertNodeEnd(8);
    myList.InsertNodeEnd(10);
    myList.InsertNodeEnd(11);
    myList.InsertNodeEnd(12);
    myList.InsertNodeEnd(13);
    myList.Traverse();
    myList.InsertArbitrary(10, 9);
    myList.Traverse();
}
