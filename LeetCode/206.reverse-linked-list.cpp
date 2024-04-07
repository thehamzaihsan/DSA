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
//     ListNode() : val(0), next(NULL) {}
//     ListNode(int x) : val(x), next(NULL) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nexts = head;
        while(curr != nullptr){
            nexts = nexts->next;
            curr->next = prev;
            prev = curr;
            curr = nexts;
        }
        return prev;
        
    }
};
// @lc code=end
