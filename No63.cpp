// LINK: https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      
        /*

        KEY: 建立一個dp的table，先處理邊界，再處理內部

        */
      
        // corner case
        if (obstacleGrid[0][0] == 1) 
            return 0;
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, std::vector<int>(col, 1));
        
        // process first row
        for (int i = 1; i < row; i++)
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;

        // process first col
        for (int i = 1; i < col; i++)
            dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i-1] == 1) ? 1 : 0;

        // process inner data
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
        
        return dp[row-1][col-1];
    }
};
