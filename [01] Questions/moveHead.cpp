#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
};

//function to display the linked list
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *moveHead(Node* head , int data){
    if (head == nullptr || head->val == data) 
        return head;
    
    Node *temp = head;
    Node *oldHead = head;
    Node *newHead = nullptr;
    Node *oldTail = nullptr; 

    while(temp!=nullptr){
        if(temp->next != nullptr && temp->next->val == data){
            oldTail = temp;
            newHead = temp->next;
        }
        if(temp->next == nullptr){
            oldTail = temp;
        }
        temp = temp->next;
    }
    newHead ->prev->next = nullptr;
    newHead -> prev = nullptr;
    oldTail -> next = oldHead;
    oldHead -> prev = oldTail;
    return newHead;
}



int main(){
    //create a doubly linked list 
    //11-3-8-2-1

    Node* head = new Node();
    head->val = 11;
    head->next = new Node();
    head->next->val = 3;
    head->next->prev = head;
    head->next->next = new Node();
    head->next->next->val = 8;
    head->next->next->prev = head->next;
    head->next->next->next = new Node();
    head->next->next->next->val = 2;
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node();
    head->next->next->next->next->val = 1;
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = NULL;
    display(head);
    Node *mhead = moveHead(head , 8);
    // cout << mhead -> val;
    display(mhead);
}