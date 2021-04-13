// LINK: https://leetcode.com/problems/flatten-nested-list-iterator/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*

KEY: 建構式就先攤平，取next的時候就方便許多

*/

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // flatten first
        DFS(nestedList);
        
        // initial index
        currentIndex = 0;
    }
    
    int next() {
        int val = flatten[currentIndex];
        currentIndex++;
        
        return val;
    }
    
    bool hasNext() {
        return currentIndex < flatten.size();
    }
    
private:
    int currentIndex;
    vector<int> flatten;
    void DFS(vector<NestedInteger> &nestedList)
    {
        for(NestedInteger &element : nestedList) 
        {
            // element is integer
            if(element.isInteger()) flatten.push_back(element.getInteger());
            
            // element is a list
            else DFS(element.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
