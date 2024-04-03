/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start

//   Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
#include <stack>
public:
    bool isPalindrome(ListNode *head)
    {
        if(head->next == NULL){
            return true;
        }
        stack<int> s;
        while (true)
        {
            if (s.size() == 0)
            {
                s.push(head->val);
            }
            else
            {
                if (head->val == s.top())
                {
                    s.pop();
                }
                else
                {
                    s.push(head->val);
                }
            }
            if (head->next == NULL)
            {
                break;
            }
            else
            {

                head = head->next;
            }
        }
        if (s.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=ends
