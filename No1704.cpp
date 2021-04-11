// LINK: https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    const string VOWEL = "aeiouAEIOU";
    
    bool halvesAreAlike(string s) {
      
        /*
        KEY: 用substr把字串分兩段，分開統計
        */
      
        // split into two strings
        string str1 = s.substr(0,s.length() / 2);
        string str2 = s.substr(s.length() / 2, s.length() / 2);
        
        int str1VowelCnt = 0, str2VowelCnt = 0;
        for(int i=0; i<str1.size(); i++)
        {
            char currC1 = str1[i];
            char currC2 = str2[i];
          
            // count str1 and str2 vowels
            if(VOWEL.find(currC1) != string::npos)
            {
                str1VowelCnt++;
            }
            if(VOWEL.find(currC2) != string::npos)
            {
                str2VowelCnt++;
            }
        }
        
        return (str1VowelCnt == str2VowelCnt);
    }
};
