class Solution {
public:
    vector<int> constructArray(int n, int k) {
        /*
        
        KEY : {1, k+1, 2, k ... 後面補k+2 ~ n}
        
        */
        
        vector<int> ret;
        
        // process [1, k+1, 2, k...]
        int front = 1;
        int back = k+1;
        while(front < back)
        {
            ret.push_back(front);
            ret.push_back(back);
            
            front++;
            back--;
        }

        // odd count
        if(front == back){
            ret.push_back(front);
        }
        
        // push back k+2 ... n
        for(int i=k+2; i<=n; i++)
        {
            ret.push_back(i);
        }
        
        return ret;
    }
};
