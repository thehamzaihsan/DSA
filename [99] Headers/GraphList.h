#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

class GraphList
{
    public:
    vector<ListNode<int>> adj;
    int n;
    GraphList(int n){
        this->n = n;
        adj = vector<ListNode<int>>(n);
        for (int i = 0; i < adj.size(); i++)
        {
            adj[i].val = i;
        }
        
    }
    GraphList(){}

    void display(){
        for(int i = 0; i < n; i++){
            ListNode<int> *temp = &adj[i];
            cout << temp->val << ": ";
            temp=temp->next;
            while(temp != nullptr){
            cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void addedges(vector<int> location){
        ListNode<int> *newNode = new ListNode<int>;
        newNode->val = location[1];
        newNode->next = nullptr;
        ListNode<int> *temp = &adj[location[0]];
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;

         ListNode<int> *newNode_t = new ListNode<int>;
        newNode_t->val = location[0];
        newNode_t->next = nullptr;
        ListNode<int> *temp_t = &adj[location[1]];
        while(temp_t->next != nullptr){
            temp_t = temp_t->next;
        }
        temp_t->next = newNode_t;
    }
};