#include <iostream>
using namespace std;

class Node
{
    public:
    Node *next;
    Node *prev;
    int val;
};

class DoublyCircular
{
public:
    Node *head = new Node;
    DoublyCircular()
    {
        
        head->next = head;
        head->prev = head;
        head->val = 0;
    }
    void Insert(int x)
    {
        Node *ptr = new Node;
        ptr->val = x;
        ptr->next = head;
        head->prev = ptr;
        if (head->next == head)
        {
            head->next = ptr;
            ptr->prev = head;
        }
        else
        {
            Node *loop = new Node;
            loop = head;
            while (loop->next != head)
            {
                loop = loop->next;
            }
            loop->next = ptr;
            ptr->prev = loop;
        }
    }

    void Traverse()
    {
        Node *loop = head->next;
        while (true)
        {
            cout << loop->val << " ";
            loop = loop->next;
            if (loop == head)
            {
                break;
            }
        }
    }
    
};