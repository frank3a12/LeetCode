// LINK: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      
        /*

        KEY: 一圈一圈處理，由外圈處理到內圈
        每一圈的step count會越來越少

        */
      
        int width = matrix.size();
        int depth = width / 2;
        
        for(int i=0; i<depth; i++)
        {
            int len = width - 2 * i - 1;
            int opp = width - 1 - i;
            for (int j = 0; j < len; j++) {
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[opp-j][i];
                matrix[opp-j][i] = matrix[opp][opp-j];
                matrix[opp][opp-j] = matrix[i+j][opp];
                matrix[i+j][opp] = temp;
            }
        }
    }
};
