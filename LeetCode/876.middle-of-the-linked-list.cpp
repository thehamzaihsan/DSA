/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr = head;
        int count = 0;
        while(true){
            if(ptr == NULL){
                break;
            }
            else{
                ptr = ptr->next;
                count++;
            }
        }
        count = count/2 + 1;
        ptr = head;
        int dummy = 0;
        while(true){
            if(ptr == NULL){
                break;
            }
            else{
                dummy++;
                if(dummy == count){
                    return ptr;
                }
                ptr = ptr->next;
            }
        }

        return head;
    }
};
// @lc code=end

