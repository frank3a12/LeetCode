//LINK: https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        
        /*

        KEY: 把每個數的倍數都過濾掉

        */
      
        // corner case
        if(n == 1) return 0;
        else if(n == 0) return 0;
        else if(n == 2) return 0;
      
        // create a vector of filter
        vector<bool> totalNums(n, true);
        totalNums[0] = false;
        totalNums[1] = false;
      
        // for each number
        for(int i = 0; i < totalNums.size(); i++)
        {
          if(totalNums[i] == false) continue;
          
          // each 倍數
          for(int ii = i+i; ii < n; ii += i) 
          {
            totalNums[ii] = false; 
          }
        }
      
        return count(totalNums.begin(), totalNums.end(), true); 
    }
};
