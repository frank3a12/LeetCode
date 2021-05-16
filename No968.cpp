// LINK: https://leetcode.com/problems/binary-tree-cameras/

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
    int minCameraCover(TreeNode* root) {
      
      /*

      KEY: 每個節點有三種可能的狀態：
            0:節點沒有安裝監視器,且監視得到,當前節點不需要安裝監視器,暗示上層節點不需要裝監視器 
            1:節點沒有安裝監視器,且監視不到,暗示上層節點需要裝監視器
            2:節點安裝了監視器,暗示上層節點不需要裝監視器 
      
      */

        if(!root) return 0;
        if(DFS(root) == NodeType::NoMonitor_CannotSpy)
          ret++;
      
        return ret;
    }
    
private:
    enum NodeType
    {
      NoMonitor_CanSpy = 0,
      NoMonitor_CannotSpy,
      HasMonitor
    };
    int ret = 0;
    NodeType DFS(TreeNode* root)
    {
      if(!root) return NodeType::NoMonitor_CanSpy; //如果為空,視作可以監視,但是上層不用安裝監視器
      
      NodeType leftNodeType = DFS(root->left);
      NodeType rightNodeType = DFS(root->right);
      
      //1 0, 0 1, 1 2, 2 1, 1 1
      if (leftNodeType == NodeType::NoMonitor_CannotSpy ||
          rightNodeType == NodeType::NoMonitor_CannotSpy) { //如果左右子樹有一個沒有安裝監視器,且監視不到
        ++ret;                   //當前節點需要安裝監視器
        return NodeType::HasMonitor;                  //節點安裝了監視器,返回對應type,上層節點不用安裝監視器
      } 
      
      //0 2, 2 0, 2 2
      if (leftNodeType == NodeType::HasMonitor ||
          rightNodeType == NodeType::HasMonitor)  //如果左右子樹有一個安裝監視器而另一個監視得到或都裝了,當前節點就不用安裝監視器
        return NodeType::NoMonitor_CanSpy; 
      
      return NodeType::NoMonitor_CannotSpy;
    }
};
