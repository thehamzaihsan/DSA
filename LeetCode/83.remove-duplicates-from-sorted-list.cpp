struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *ptr = head; // from i = 0
        while (ptr->next != nullptr)
        { // length - 1

            if (ptr->val == ptr->next->val)
            {
                ListNode *temp = ptr->next;
                if (temp->next != nullptr)
                {
                    ptr->next = temp->next;
                }
                else
                {
                    ptr->next = nullptr;
                }
                delete temp;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        return head;
    }
};
// @lc code=end
