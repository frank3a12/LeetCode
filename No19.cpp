// LINK: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /*
        
        KEY: 用vector包起來，用Index去查找
        
        */
      
        // corner case
        if(head->next == nullptr) return nullptr;
        
        // use vector
        vector<ListNode*> vec;
        ListNode* root = head;
        while(root)
        {
            vec.push_back(root);
            root = root->next;
        }
        
        // adjust
        ListNode* curr = vec[vec.size() - n];
        if(curr == head)    // remove head
        {
            head = head->next;
        }
        else if(n == 1)   // remove tail
        {
            ListNode* pre = vec[vec.size() - n - 1];
            pre->next = nullptr;
        }
        else
        {
            ListNode* pre = vec[vec.size() - n - 1];
            ListNode* next = vec[vec.size() - n + 1];
            
            pre->next = next;
        }
        
        return head;
    }
};
