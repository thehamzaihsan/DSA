/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
class Solution
{
#include <stack>
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nexts = head;
        while (curr != nullptr)
        {
            nexts = nexts->next;
            curr->next = prev;
            prev = curr;
            curr = nexts;
        }
        return prev;
    }
    ListNode *findmiddle(ListNode *Head)
    {
        ListNode *slow = Head;
        ListNode *fast = Head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = findmiddle(head);
        cout << middle->val;
        ListNode *end = reverseList(middle);
        cout << end->val;
        
        return false;
    }
};
// @lc code=ends
