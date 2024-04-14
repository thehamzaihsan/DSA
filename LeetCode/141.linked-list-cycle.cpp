struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

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
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while(true){
            if(fast->next == nullptr || fast->next->next == nullptr || fast == nullptr){
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

