/*
   Given an array of integers, find two numbers such that they add up to a specific target number.
   The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

   You may assume that each input would have exactly one solution. Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

分析
这个题很巧妙的用了map，因为是找两个数凑起来能是target, 所以遇到一个数，你就知道了它应该和谁去凑对，虽然不知道能凑对的这个数是否在array中存在又或者存在在什么地方。搞一个<number, index>的map, 记录每个数字出现的位置。逐个去检查数字，看看他要凑成对的那个数字是不是已经存在了即可。

 */ 

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
			unordered_map<int, int> mapping;
			vector<int> result;
			/*如果nums有重复元素，取最大下标做index*/
			for (int i = 0; i < nums.size(); i++ ) {
				mapping[nums[i]] = i;
			}
			/*
			for ( int i = 0; i < mapping.size(); i++ ) {
				cout << "mapping[" << i << "]: " << mapping[i] << ", ";
			}
			cout << endl;
			*/

			for (int i = 0; i < nums.size(); i++ ) {

				int gap = target - nums[i];
				if ( mapping.find(gap) != mapping.end() && mapping[gap] > i ) {
					result.push_back(i + 1);
					result.push_back(mapping[gap] + 1);
					/*break,取出一组下标满足条件即返回*/
					break;
				}
			}

			return result;
		}
};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);

	for ( auto i : vec )	
		cout << i << " ";
	cout << endl;

	int target = 7;
	cout << "target: " << target <<endl;

	Solution solu;
	vector<int> result;
	result = solu.twoSum(vec, target);
	for ( auto i : result ) {
		cout << i << " ";
	}
	cout << endl;	

	return 0;
}
