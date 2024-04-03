#include <iostream>
using namespace std;
#include "linkedlist.h"

Node* findmiddle(Node *Head){
    Node *slow = Head;
    Node *fast = Head->next_link;
    while(fast != nullptr && fast->next_link !=nullptr){
        slow = slow->next_link;
        fast = fast->next_link->next_link;
    }
    return slow;
}

int main(){
    LinkedList list;
    list.InsertNodeEnd(10);
    list.Traverse();
    Node *middle = findmiddle(list.Head);
    cout << middle->data;
}