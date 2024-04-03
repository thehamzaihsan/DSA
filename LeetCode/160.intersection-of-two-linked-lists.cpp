/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        while (true)
        {
            if (ptrA == NULL)
            {
                break;
            }
            else
            {
                while (true)
                {
                    if (ptrB == NULL)
                    {
                       ptrB = headB;
                       break;
                    }
                    else
                    {
                        cout << "comp" << ptrA->val << ptrB->val;
                        if(ptrA == ptrB){
                            return ptrA;
                        }
                        ptrB = ptrB->next;
                    }
                }
                ptrA = ptrA->next;
            }
        }
        return ptrA;
    }
};
// @lc code=end
