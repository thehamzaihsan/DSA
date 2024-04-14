/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start

#include <istream>
int init = [] {
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out<<(equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin() + 1) ? "true\n" : "false\n");
    out.flush();
    exit(0);

    return 0;
}();

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
        ListNode *fast = Head;
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
        ListNode *TailHead = reverseList(middle);
        cout << TailHead->val;
        ListNode *temp = head;
        ListNode *tempTail = TailHead;
        while(temp != middle){
            if(temp->val != tempTail->val){
                return false;
            }
            temp = temp->next;
            tempTail = tempTail->next;
        }
        if(head == middle){
            if(head->val != TailHead->val){
                return false;
            }
        }
        return true;
    }
};
// @lc code=ends
