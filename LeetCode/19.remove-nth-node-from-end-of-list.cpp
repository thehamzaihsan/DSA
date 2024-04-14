/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //starting indexing from 1
        ListNode *temp = head;
        int count = 0;
        while (temp != nullptr){
            count++;
            temp = temp->next; 
        }
        temp = head;
        int deletecount = count - n;
        cout << deletecount;
        count = 0;
        while(temp != nullptr){
            count++;
            if(count == deletecount){
                ListNode *ttemp = temp->next;
                temp->next = temp->next->next;
                delete ttemp;
            }
            temp = temp->next;
        }
        return head;
    }
};
// @lc code=end
