#include <iostream>
#include <cstdlib>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
};

class CircularDoublyList
{
private:
    ListNode *head;

public:
    CircularDoublyList()
    {
        head = NULL;
    }
    void insert_beg(int value)
    {
        ListNode *newNode = new ListNode;
        newNode->val = value;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            ListNode *last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last->next = newNode;
            head = newNode;
        }
    }
    void insert_end(int value)
    {
        if (head == NULL)
        {
            insert_beg(value);
        }
        else
        {
            ListNode *newNode = new ListNode;
            newNode->val = value;
            ListNode *last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }
    void insert_middle(int value)
    {
        if (head == NULL)
        {
            insert_beg(value);
        }
        else
        {
            ListNode *newNode = new ListNode;
            newNode->val = value;
            ListNode *slow = head;
            ListNode *fast = head->next;
            while (fast != head && fast->next != head)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *after = slow->next;
            slow->next = newNode;
            newNode->prev = slow;
            newNode->next = after;
            after->prev = newNode;
        }
    }
    void delete_node(int value)
    {
        if (head == NULL)
            return;
        ListNode *current = head;
        while (current->val != value && current->next != head)
        {
            current = current->next;
        }
        if (current->val == value)
        {
            if (current == head)
            {
                if (head->next == head)
                {
                    delete head;
                    head = NULL;
                }
                else
                {
                    ListNode *last = head->prev;
                    head = head->next;
                    last->next = head;
                    head->prev = last;
                    delete current;
                }
            }
            else
            {
                ListNode *prev = current->prev;
                ListNode *next = current->next;
                prev->next = next;
                next->prev = prev;
                delete current;
            }
        }
    }
    void display()
    {
        if (head == NULL)
            return;
        ListNode *current = head;
        do
        {
            cout << current->val << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    void exchange_position(int pos1, int pos2)
    {
        if (head == NULL || pos1 == pos2)
            return;
        ListNode *node1 = head;
        ListNode *node2 = head;
        for (int i = 1; i < pos1 && node1 != nullptr; ++i)
            node1 = node1->next;
        for (int i = 1; i < pos2 && node2 != nullptr; ++i)
            node2 = node2->next;
        if (node1 == nullptr || node2 == nullptr)
            return;
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
// int main()
// {
//     CircularDoublyList list;
//     srand(time(0));
//     for (int i = 0; i < 10; ++i)
//     {
//         int value = rand() % 11;
//         int position = rand() % 3;
//         switch (position)
//         {
//         case 0:
//             list.insert_beg(value);
//             break;
//         case 1:
//             list.insert_middle(value);
//             break;
//         case 2:
//             list.insert_end(value);
//             break;
//         }
//     }
//     cout << "List after random insertions: ";
//     list.display();
//     int value_to_delete = rand() % 11;
//     cout << "Deleting ListNode with value " << value_to_delete << endl;
//     list.delete_node(value_to_delete);
//     cout << "List after deletion: ";
//     list.display();
// }

int main()
{
    CircularDoublyList list;
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        int value = rand() % 11;
        list.insert_end(value);
    }
    cout << "List before position exchange: ";
    list.display();
    for (int i = 1; i < 10; ++i)
    {
        list.exchange_position(i, i + 1);
    }
    cout << "List after position exchange: ";
    list.display();
    return 0;
}