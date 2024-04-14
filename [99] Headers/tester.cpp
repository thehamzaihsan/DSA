#include <iostream>
using namespace std;
// #include "./doubly-circular-list.h"
#include "./circular-list.h"
void swap(int val1, int val2, Node *head)
{
    Node *ptr1 = head;
    Node *ptr2 = head;
    while (true)
    {
        if (ptr1->val != val1)
        {
            ptr1 = ptr1->next;
        }
        if (ptr2->val != val2)
        {
            ptr2 = ptr2->next;
        }
        if (ptr1->val == val1 && ptr2->val == val2)
        {
            break;
        }

        if (ptr1 == nullptr || ptr2 == nullptr)
        {
            break;
        }
    }

    Node *temp1, *temp2;
    temp1 = ptr1->next;
    temp2 = ptr1->prev;
    //NOT ADJACENT
    if (ptr1->next != ptr2 && ptr1->prev != ptr2)
    {

        ptr1->prev = ptr2->prev;
        ptr1->next = ptr2->next;
        ptr2->prev->next = ptr1;
        ptr2->next->prev = ptr1;

        ptr2->prev = temp2;
        ptr2->next = temp1;
        temp1->prev = ptr2;
        temp1 = ptr1->next;
        temp2 = ptr1->prev;
    }
    else
    //ADJACENT
    {
        ptr1->prev = ptr2;
        ptr1->next = ptr2->next;
        ptr2->next->prev = ptr1;

        ptr2->prev = temp2;
        temp2->next = ptr2;
        ptr2->next = ptr1;
    }
}

int main()
{
    CircularList List;
    List.insert(10);
    List.Delete();
    List.Traverse();
}