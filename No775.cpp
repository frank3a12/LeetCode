// LINK: https://leetcode.com/problems/global-and-local-inversions/

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        
        /*
        KEY: 所有local inversions 都是global inversions
        檢查所有global inversions，若不是local則return false
        */
        
        // corner case
        if(A.size() == 1) return true;
        
        // for each
        int maxVal = INT_MIN;
        for(int i=0; i<A.size() - 2; i++)
        {
            maxVal = max(A[i], maxVal);
            if(maxVal > A[i+2]) return false;
        }
        return true;
    }
};
