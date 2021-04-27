// LINK: https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    
      /*

      KEY: 紀錄每一次往上跳的差距

      */

      multiset<int> climbs;
      int n = heights.size();
      for (int i = 1; i < n; i++) {

        // current building is higher than prev building
        if (heights[i] - heights[i-1] > 0) {
            climbs.insert(heights[i] - heights[i-1]);
        }

        // if climb count greater than ladders (梯子用完了)
        if (climbs.size() > ladders) {
            bricks -= *climbs.begin();  // use brick
            climbs.erase(climbs.begin());
            if (bricks < 0) return i-1;
        }
      }
      return n-1;
    }
};
