/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		int idx = 0;
		for( int i=0; i < nums.size()-1; i++ ) {
			if(nums[i] < target) idx++;
			else break;
		}
		return idx;
	}
};


int main()
{
	int n[] = {1,3,5,6};
	vector<int> v(n, n+sizeof(n)/sizeof(int));
	Solution solu;
	cout << solu.searchInsert(v, 2) << endl;
	return 0;
}
