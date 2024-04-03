/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while(true){
            if(fast->next == NULL || fast->next->next == NULL || fast == NULL){
                return false;
            }
            else{
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow){
                    return true;
                }
            }
        }
    }
};
// @lc code=end

