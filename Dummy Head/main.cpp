#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        this->data = data;
        this->next = NULL;
    }
};
class HList
{
public:
    Node *HEAD;

public:
    HList()
    {
        HEAD = NULL;
    }
    bool emptyList()
    {
        return HEAD->next == NULL;
    }
    void InsertAfter(int oldV, int newV)
    {
        Node *Ptr = HEAD->next;
        while (Ptr != NULL && Ptr->data != oldV)
        {
            Ptr = Ptr->next;
        }
        if (Ptr != NULL)
        {
            Node *newNode = new Node(newV);
            newNode->next = Ptr->next;
            Ptr->next = newNode;
        }
    }
    void InsertBegin(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = HEAD->next;
        HEAD->next = newNode;
    }
    void InsertEnd(int value)
    {
        Node *newNode = new Node(value);
        Node *Ptr = HEAD;
        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = newNode;
    }
    void deleteNode(int val)
    {
        Node *Ptr = HEAD;
        while (Ptr->next != NULL && Ptr->next->data != val)
        {
            Ptr = Ptr->next;
        }
        if (Ptr->next != NULL)
        {
            Node *temp = Ptr->next;
            Ptr->next = Ptr->next->next;
            delete temp;
        }
    }
    void deleteBegin()
    {
        if (HEAD->next != NULL)
        {
            Node *temp = HEAD->next;
            HEAD->next = HEAD->next->next;
            delete temp;
        }
    }
    void deleteEnd()
    {
        Node *Ptr = HEAD;
        while (Ptr->next->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Node *temp = Ptr->next;
        Ptr->next = NULL;
        delete temp;
    }
    void traverse()
    {
        Node *Ptr = HEAD->next;
        while (Ptr != NULL)
        {
            cout << Ptr->data << " ";
            Ptr = Ptr->next;
        }
        cout << endl;
    }
};
int main()
{
    HList list;
    list.InsertEnd(8);
    list.InsertEnd(10);
    list.InsertEnd(9);
    list.InsertEnd(11);
    list.traverse();
}