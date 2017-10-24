/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

分析
	a^b^a^c^b = a^a^b^b^c = c
	异或操作，不仅能处理两次的情况，element出现偶数次都可以清零
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int res = 0;
		for( auto i : nums ) res ^= i;
		return res;
	}
};

int main()
{
	int n[] = {1,1,-2,-2,4,5,4,6,6}; 
	cout << "{1,1,-2,-2,4,5,4,6,6}" << endl;	
	vector<int> vec(n, n+sizeof(n)/sizeof(int));

	Solution solu;
	cout << solu.singleNumber(vec) << endl;
	return 0;
}
