// LINK: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flatten(TreeNode* root) {

        /*
        KEY: DFS 紀錄pre-order
        */
      
        // corner caee
        if (root == nullptr) return;
      
        // DFS
        vector<int> LList;
        dfs(root, LList);
      
        // post process
        root->left = nullptr;
        root->right = nullptr;
        TreeNode* walk = root;
        for (int i = 1; i < LList.size(); i++) {
            walk->left = nullptr;
            walk->right = new TreeNode(LList[i]);
            walk = (walk ? walk->right : nullptr);
        }
    }
    
    void dfs(TreeNode* cur, vector<int> &LList) {
        if (cur == nullptr) return;
      
        LList.push_back(cur->val);
        if(cur->left) dfs(cur->left, LList);
        if(cur->right) dfs(cur->right, LList);
    }
};
