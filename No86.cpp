// LINK: https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        /*
        
        KEY: 大的放一起，小的放一起；基礎做法可以每個node都用new的，進階作法則是直接調整root這個ptr
        
        */
        
        ListNode* small = new ListNode(-1);
        ListNode* smallIter = small;
        ListNode* big = new ListNode(-1);
        ListNode* bigIter = big;
        
        ListNode* root = head;
        while(root)
        {
            if(root->val < x)
            {
                smallIter->next = root;
                smallIter = smallIter->next;
            }
            else
            {
                bigIter->next = root;
                bigIter = bigIter->next;
            }
            
            root = root->next;
        }
        bigIter->next = nullptr;
        smallIter->next = big->next;
        
        return small->next;
    }
};
