/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{>
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *ptr = head;
        while (ptr->next != nullptr)
        {
            if(ptr == head){
                if(ptr->val > ptr->next->val){
                    ptr->next == ptr->next->next;
                    
                }
            }
            else if (ptr->val > ptr->next->val)
            {
                Swap(ptr, ptr->next);
            }
            ptr = ptr->next;
        }
    }
    // large->next = small
    void Swap(ListNode *large, ListNode *small)
    {
        
    }
};
// @lc code=end
