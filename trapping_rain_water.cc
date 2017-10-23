/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

+
|
|                             +----+
|                             |    |
|                             |    |
|                             |    |
|            +---+            |    +----+    +----+
|            |   |            |    |    |    |    |
|   +---+    |   +---+    +---+    |    +----+    +----+
|   |   |    |   |   |    |   |    |    |    |    |    |
|   |   |    |   |   |    |   |    |    |    |    |    |
+---+---+----+---+---+----+---+----+----+----+----+----+-------->

*/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
  int trap(const vector<int> &nums) {
    vector<int> left, right;
    int mx = 0;
    int result = 0;
    
    for ( int i = 0; i < nums.size(); i++ ) {
      left.push_back(mx);
      mx = max(mx, nums[i]);
    }
    
    mx = 0;
    for( int i = nums.size() - 1; i >= 0; i-- ) {
      right.push_bask(mx);
      mx = max(mx, nums[i]);
    }
    reverse(right.begin(), right.end());
    
    for( int i = 0; i < nums.size(); i++ ) {
      if ( min(left[i], right[i]) > nums[i] )
        result += min(left[i], right[i]) - nums[i];
    }
    
    return result;
};

int main()
{
  int n[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> vec(n, n+sizeof(n)/sizeof(int));
  Solution solu;
  cout << solu.trap(vec) << endl;
  return 0;
}
