#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class CircularList
{
private:
    Node *head;

public:
    CircularList()
    {
        head = NULL;
    }
    bool emptyList()
    {
        return head == NULL;
    }
    void insert_at(int position, int value)
    {
        cin >> position;
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }
        else
        {
            if (head->data == position)
            {
                Node *Ptr = new Node(value);
                Ptr->data = value;
                Ptr->next = temp->next;
                head->next = Ptr;
            }
            else
            {
                do
                {
                    temp = temp->next;
                } while (temp->data != position && temp != head);
                if (temp->data == position)
                {
                    Node *Ptr = new Node(value);
                    Ptr->data = value;
                    Ptr->next = temp->next;
                    temp->next = Ptr;
                }
                else
                {
                    return;
                }
            }
        }
    }
    void insert_begin(int value)
    {
        Node *New_Node = new Node(value);
        New_Node->data = value;
        New_Node->next = NULL;
        if (head == NULL)
        {
            head = New_Node;
            New_Node->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = New_Node;
            New_Node->next = head;
            head = New_Node;
        }
    }
    void insert_end(int value)
    {
        Node *New_Node = new Node(value);
        New_Node->data = value;
        New_Node->next = NULL;
        if (head == NULL)
        {
            head = New_Node;
            New_Node->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = New_Node;
            New_Node->next = head;
        }
    }
    void delete_Node(int pos)
    {
        Node *temp = head;
        Node *Ptr;
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }
        else
        {
            if (head->data == pos)
            {
                do
                {
                    Ptr = temp;
                    temp = temp->next;
                } while (temp != head);
                head = head->next;
                delete temp;
                Ptr->next = head;
            }
            else
            {
                do
                {
                    Ptr = temp;
                    temp = temp->next;
                } while (temp->data != pos && temp != head);
                if (temp != head)
                {
                    Ptr->next = temp->next;
                    delete temp;
                }
                else
                {
                    cout << "Node not found";
                    return;
                }
            }
        }
    }
    void delete_begin()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Linked List is empty";
            return;
        }
        if (head->next == head)
        {
            head = NULL;
            delete temp;
            return;
        }
        else
        {
            Node *Ptr = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete Ptr;
        }
    }
    void delete_end()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Linked List is empty:" << endl;
            return;
        }
        if (head->next == head)
        {
            head = NULL;
            delete temp;
            return;
        }
        else
        {
            Node *Ptr = NULL;
            while (temp->next != head)
            {
                Ptr = temp;
                temp = temp->next;
            }
            Ptr->next = temp->next;
            delete temp;
        }
    }
    void traverse()
    {
        Node *p = head->next;
        if (head->next == head)
        {
            cout << p->data;
            return;
        }
        cout << head->data << " ";
        while (p != head)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main()
{
    CircularList list;
    list.insert_begin(2);
    list.insert_begin(5);
    list.insert_begin(7);
    list.insert_begin(8);
    list.insert_begin(10);
    list.traverse();
}