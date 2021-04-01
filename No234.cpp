// LINK: https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        stack<int> myStack;
            
        ListNode* root = head;
        while(root != nullptr) 
        {
            myStack.push(root->val);
            root = root->next;
        }
        
        root = head;
        while(root != nullptr) 
        {
            int val = myStack.top();
            myStack.pop();
            if(val != root->val) return false;
            root = root->next;
        }
        
        return true;
    }
};
