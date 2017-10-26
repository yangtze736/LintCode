/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

分析
	在一个有序整数数组中寻找相同目标值的起始和结束位置，而且限定了时间复杂度
	为O(logn)，这是典型的二分查找法的时间复杂度，我们的思路是首先对原数组使用
	二分查找法，找出其中一个目标值的位置，然后向两边搜索找出起始和结束的位置
 */

#include<vector>
#include<iostream>

using namespace std;
/*
class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int index = search(nums, 0, nums.size()-1, target);
		if(index == -1) return {-1, -1};
		int left = index, right = index;
		while( left > 0 && nums[left-1] == target ) left--;
		while( right < sizeof(nums)-1 && nums[right+1] == target ) right++;
		return {left, right};
	}
private:
	int search(vector<int> &nums, int left, int right, int target ) {
		if(left > right) return -1;
		int mid = left + (right -left)/2;
		if(nums[mid] == target) {
			return mid;
		}
		else if( nums[mid] < target ) {
			return search(nums, mid+1, right, target);
		}
		else {
			return search(nums, left, mid-1, target);
		}
	}
};
*/

/*
使用两次二分查找法，第一次找到左边界，第二次调用找到右边界
*/
class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			vector<int> res(2, -1);
			int left = 0, right = nums.size() - 1;
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] < target) { 
					left = mid + 1;
				}else{
					 right = mid;
				}
			}
			if (nums[right] != target) return res;
			res[0] = right;
			right = nums.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] <= target) left = mid + 1;
				else right= mid;
			}
			res[1] = left - 1;
			return res;
		}


};

int main()
{
	int n[] = {5,7,7,8,8,10};
	cout << "{5,7,7,8,8,10}" << endl;
	vector<int> vec(n, n+sizeof(n)/sizeof(int));
	Solution solu;
	vector<int> ret = solu.searchRange(vec, 8);
	for( auto i : ret ) cout << i << " ";
	cout << endl;
	return 0;
}
