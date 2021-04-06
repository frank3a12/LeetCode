// LINK: https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution {
public:
    int minOperations(int n) {
      
        /*
        KEY: 每個數都要移動到正中間(平均)，就可以直接用數學規則計算
        */
      
        int averageNum = n;
        
        int count = 0;
        for(int i=0; i<n/2; i++)
        {
            int currVal = 2*i+1;
            count += averageNum-currVal;
        }
        
        return count;
    }
};
