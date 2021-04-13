// LINK: https://leetcode.com/problems/deepest-leaves-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
      
        /*
        
        KEY: 先找樹高，再求sum
        
        */
      
        // DFS find tree height
        DFSFindHeight(root, 1);
      
        // find sum
        int sum = 0;
        DFSFindSum(root, 1, sum);
      
        return sum;
    }
private:
  int depth = INT_MIN;
  
  void DFSFindHeight(TreeNode* root, int currHeight)
    {
      depth = max(depth, currHeight);
      if(root->left) DFSFindHeight(root->left, currHeight+1);
      if(root->right) DFSFindHeight(root->right, currHeight+1);
    }
  
    void DFSFindSum(TreeNode* root, int currHeight, int &sum)
    {
      if(IsLeaf(root))
      {
        if(currHeight == depth)
          sum += root->val;
        return;
      }
      
      if(root->left) DFSFindSum(root->left, currHeight+1, sum);
      if(root->right) DFSFindSum(root->right, currHeight+1, sum);
    }
  
    bool IsLeaf(TreeNode* root)
    {
      if(root->left == nullptr && root->right == nullptr) return true;
      else return false;
    }
};
