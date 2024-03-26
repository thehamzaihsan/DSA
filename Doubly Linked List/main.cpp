#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data_t)
    {
        data = data_t;
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
    void InsertNode(int data)
    {
        Node *new_node = new Node(data);
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
            cout << Ptr->data << " ";
            Ptr = Ptr->next;
            if (Ptr == NULL)
            {

                break;
            }
        }
        cout << endl;
    }
    void InsertAtSecond(int data)
    {
        Node *new_Node = new Node(data);
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
    void InsertHead(int Data)
    {
        Node *new_node = new Node(Data);
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
            if (Ptr->data == key)
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
    void InsertSpecific(int key, int data)
    {
        Node *Ptr = head;
        while (true)
        {
            if (Ptr->data == key)
            {
                if (Ptr->next == NULL)
                {
                    InsertNode(data);
                }
                else
                {
                    Node *new_Node = new Node(data);
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
    int Max()
    {
        Node *Ptr = head;
        int max = Ptr->data;
        while (true)
        {
            if (Ptr->data > max)
            {
                max = Ptr->data;
            }
            Ptr = Ptr->next;
            if (Ptr == NULL)
            {
                break;
            }
        }
        return max;
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
    // Create an instance of the DoublyLinkedList class
    Double_list myList;

    // Prompt the user to test each function
    int choice;
    do
    {
        cout << "Choose an option:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete the first node\n";
        cout << "3. Delete a specific node\n";
        cout << "4. Insert a node after a specific node\n";
        cout << "5. Find the maximum value\n";
        cout << "6. Count the number of nodes\n";
        cout << "7. Display the list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the data to insert: ";
            cin >> data;
            myList.InsertNode(data);
            break;
        }
        case 2:
        {
            myList.deleteFirstNode();
            break;
        }
        case 3:
        {
            int key;
            cout << "Enter the key to delete: ";
            cin >> key;
            myList.deleteSpecific(key);
            break;
        }
        case 4:
        {
            int key, data;
            cout << "Enter the key to insert after: ";
            cin >> key;
            cout << "Enter the data to insert: ";
            cin >> data;
            myList.InsertSpecific(key, data);
            break;
        }
        case 5:
        {
            int max = myList.Max();
            cout << "Maximum value: " << max << endl;
            break;
        }
        case 6:
        {
            int count = myList.NodeCount();
            cout << "Number of nodes: " << count << endl;
            break;
        }
        case 7:
        {
            myList.displayList();
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}