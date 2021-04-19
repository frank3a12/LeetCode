// LINK: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    // Approach 1: DFS -> TIME EXCEEDED!!!
    /*
    int count = 0;
    void DFS(vector<int>& nums, int currSum, int &target)
    {
        for(int element : nums)
        {
            if(element + currSum == target)
            {
                count++;
                continue;
            }
            else if(element + currSum > target)
            {
                continue;
            }
            else
            {
                DFS(nums, element + currSum, target);
            }
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        DFS(nums, 0, target);
        return count;
    }
    */
    
    // Approach 2: DP
  
    /*

    KEY: DP去紀錄每一個位置可以如何抵達

    */
  
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        
        return dp[target];
    }
};
