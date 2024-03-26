#include <iostream>
using namespace std;

class Employee
{
public:
    int ID;
    int salary;
    int bonus;
    int yearOfJoining;
    Employee()
    {
        ID = 1;
        salary = 1;
        bonus = 1;
        yearOfJoining = 1;
    }
    Employee(int IDt, int salaryt, int bonust, int yearOfJoiningt)
    {
        this->ID = IDt;
        this->salary = salaryt;
        this->bonus = bonust;
        this->yearOfJoining = yearOfJoiningt;
    }
    void display()
    {
        cout << "ID: " << ID << " Salary: " << salary << " Bonus: " << bonus << " Year of Joining: " << yearOfJoining << endl;
    }
};

class Node
{
public:
    Employee emp;
    Node *next;
    Node *prev;
    Node(Employee emp)
    {
        this->emp = emp;
        next = NULL;
        prev = NULL;
    }
    Node();
};

class Double_list
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    Double_list()
    {
        head = NULL;
        tail = NULL;
    }
    void InsertNode(int ID, int salary, int bonus, int yearOfJoining)
    {
        Employee emp(ID, salary, bonus, yearOfJoining);
        Node *new_node = new Node(emp);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node; // Add the new node at the end of the list
            new_node->prev = tail; // Set the previous pointer of the new node
            tail = new_node;       // Update the tail pointer
        }
    }
    void InsertNode(Employee emp)
    {
        Node *new_node = new Node(emp);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    void displayList()
    {
        Node *Ptr = head;
        while (true)
        {
            Ptr->emp.display();
            Ptr = Ptr->next;
            if (Ptr == NULL)
            {
                break;
            }
        }
    }
    void InsertAtSecond(int ID, int salary, int bonus, int yearOfJoining)
    {
        Employee emp(ID, salary, bonus, yearOfJoining);
        Node *new_Node = new Node(emp);
        Node *oldSecond = head->next;
        head->next = new_Node;
        new_Node->prev = head;
        new_Node->next = oldSecond;
        oldSecond->prev = new_Node;
    }
    void DeleteAtSecond()
    {
        Node *Second = head->next;
        head->next = Second->next;
        head->next->prev = head;
        delete Second;
    }
    void InsertHead(int ID, int salary, int bonus, int yearOfJoining)
    {
        Employee emp(ID, salary, bonus, yearOfJoining);
        Node *new_node = new Node(emp);
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    void deleteLastNode()
    {
        Node *oldTail = tail;
        oldTail->prev->next = NULL;
        tail = oldTail->prev;
        delete oldTail;
    }
    void deleteFirstNode()
    {
        Node *oldHead = head;
        oldHead->next->prev = NULL;
        head = oldHead->next;
        delete oldHead;
    }
    void deleteSpecific(int key)
    {
        Node *Ptr = head;
        while (true)
        {
            if (Ptr->emp.ID == key)
            {
                if (Ptr->prev != NULL)
                {
                    Ptr->prev->next = Ptr->next;
                }
                if (Ptr->next != NULL)
                {
                    Ptr->next->prev = Ptr->prev;
                }
                delete Ptr;
                break;
            }
            Ptr = Ptr->next;
            if (Ptr == NULL)
            {
                break;
            }
        }
    }
    void InsertSpecific(int key, Employee emp)
    {
        Node *Ptr = head;
        while (true)
        {
            if (Ptr->emp.ID == key)
            {
                if (Ptr->next == NULL)
                {
                    InsertNode(emp);
                }
                else
                {
                    Node *new_Node = new Node(emp);
                    Node *old = Ptr->next;
                    Ptr->next = new_Node;
                    new_Node->prev = Ptr;
                    new_Node->next = old;
                    old->prev = new_Node;
                }

                break;
            }
            Ptr = Ptr->next;
            if (Ptr == NULL)
            {
                break;
            }
        }
    }
    int NodeCount()
    {
        Node *Ptr = head;
        int count = 0;
        while (true)
        {
            count++;
            Ptr = Ptr->next;
            if (Ptr == NULL)
            {
                break;
            }
        }
        return count;
    }
};

int main()
{
    Double_list list;
    list.InsertNode(1, 1000, 100, 2010);
    list.InsertNode(2, 2000, 200, 2011);
    list.InsertNode(3, 3000, 300, 2012);
    list.InsertNode(4, 4000, 400, 2013);
    list.InsertNode(5, 5000, 500, 2014);
    list.InsertNode(6, 6000, 600, 2015);
    list.displayList();
    return 0;
}