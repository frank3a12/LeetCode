// LINK: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*

KEY: DFS

*/

class Solution {
public:
    vector<int> ret;
    void DFS(Node* root)
    {
        if(root == nullptr) return;
        
        for(Node* element : root->children)
        {
            if(element)
            {
                ret.push_back(element->val);
                DFS(element);
            }
        }
    }
    vector<int> preorder(Node* root) {
        // corner case
        if(root == nullptr) return ret;
        
        // DFS
        ret.push_back(root->val);
        DFS(root);
        
        return ret;
    }
};
