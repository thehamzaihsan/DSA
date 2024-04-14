#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int val;
    Node(int val)
    {
        this->val = val;
    }
};

class CircularList
{
public:
    Node *Head = nullptr;
    void insert(int data)
    {
        Node *temp = new Node(data);
        temp->next = nullptr;
        if (Head == nullptr)
        {
            Head = temp;
            Head->next = Head;
        }
        else
        {
            Node *temp2 = Head;
            while (temp2->next != Head)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
            temp->next = Head;
        }
    }
    void Traverse()
    {
        Node *temp = Head;
        if (Head != nullptr)
        {
            do
            {
                cout << temp->val << " ";
                temp = temp->next;
            } while (temp != Head);
        }
        cout << endl;
    }
    void Delete()
    {
        Node *temp = Head;
        if (Head != nullptr)
        {
            do
            {
                temp = temp->next;
            } while (temp->next->next != Head);
        }
        Node *del = temp->next;
        if (del == Head)
        {
            Head = nullptr;
        }
        else
        {
            temp->next = temp->next->next;
            delete del;
        }
    }
};
