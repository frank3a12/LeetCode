//LINK: https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {
      
        /*

        KEY: 用preBlock以及curBlock來記錄先前連續出現的數字and目前出現的連續數字
        再用min就可以取出兩個block最多可能的substring
        
        */
      
      
        // initial
        int curBlock = 1;
        int preBlock = 0;
        int ret = 0;
        char preChar = s[0];
        
        for(int i=1; i<s.size(); i++)
        {
            char curChar = s[i];
            if(preChar == curChar)
            {
                curBlock++;
            }
            else
            {
                ret += min(curBlock, preBlock);
                preBlock = curBlock;
                curBlock = 1;
            }
            preChar = curChar;
        }
        
        ret += min(curBlock, preBlock); // final block
        return ret;
    }
};
