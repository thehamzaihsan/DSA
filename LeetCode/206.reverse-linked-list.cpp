/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
//   Definition for singly-linked list.
#include <iostream>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
     ListNode* reverse(ListNode* node , ListNode* head)
    {
        if (node == NULL)
            return NULL;
        if (node->next == NULL) {
            head = node;
            return node;
        }
        ListNode* node1 = reverse(node->next , head);
        node1->next = node;
        node->next = NULL;
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr = head;
        ListNode *x = head;
        reverse(head , head);
        
        return x;
    }
};
// @lc code=end

