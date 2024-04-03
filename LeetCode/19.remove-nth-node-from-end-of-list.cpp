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
        int count = 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;

        }
        int deletethis = 0;
        if (count != n)
        {
            deletethis = count - n;
        }
        else if(count == 1){
            return NULL;
        }
        else{
            deletethis = 1;
        }
       
        cout << "count: " << count << endl;
        cout << "deletethis: " << deletethis << endl;

        ListNode *nptr = head;
        count = 1;
        while (nptr != NULL)
        {
            cout << nptr->val;
            if (count == deletethis)
            {
                cout << "deleted index: " << count;
                ListNode *temp = nptr->next;
                nptr->next = nptr->next->next;
                delete temp;
            }
            count++;
            nptr = nptr->next;
        }
        return head;
    }
};
// @lc code=end
