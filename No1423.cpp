// LINK: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      
        /*
        
        KEY: 怎麼拿，都是從最左或最右開始拿
        
        */
      
        // initial
        int ans = 0, N = cardPoints.size(), left = 0, right = 0;
      
        // 統計最右邊k個的總和
        for (int i = 0; i < k; ++i) 
          right += cardPoints[N - i - 1];
      
        // 右邊越拿越少，左邊越拿越多
        ans = right;
        for (int i = 0; i < k; ++i) 
        {
            left += cardPoints[i];
            right -= cardPoints[N - k + i];
            ans = max(ans, left + right);
        }
        return ans;
    }
};
