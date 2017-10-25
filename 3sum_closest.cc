/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1. 
The sum that is closest to the target is 2. (-1+2+1=2).

分析
	先给数组排序，然后遍历数组，增加两个数组下标做夹逼
	初始时左右下标left和right分别为i+1和nums.size()-1
	如果三数之和大于target则right--，反之left++
	使用最小abs(sum - target)更新closest并最终返回
*/ 

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &nums, int target) {
		int closest = nums[0] + nums[1] + nums[2];
		int diff = abs(closest - target);

		sort(nums.begin(), nums.end());

		for ( int i = 0; i < nums.size() - 2; i++ ) {
			int left = i + 1;
			int right = nums.size() - 1;
			
			while ( left < right ) {
				int sum = nums[i] + nums[left] + nums[right];
				int new_diff = abs(sum - target);
				if ( new_diff < diff ) {
					diff = new_diff;
					closest = sum;
				}

				/* nums已经排好序 */
				if ( sum > target ) right--;
				else left++;
			}
		}
		return closest;
	}
};

int main()
{
	int n[] = {-1,2,1,4};
	vector<int> vec(n, n+sizeof(n)/sizeof(int));
	for (auto i : vec )
		cout << i << " ";
	cout << endl;

	int target = 1;
	cout << "target: " << target << endl;

	Solution solu;
	int ret = solu.threeSumClosest(vec, target);
	cout << "sum closest: " << ret << endl;

	return 0;
}
