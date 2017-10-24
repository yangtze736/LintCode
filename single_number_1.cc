/*
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

分析
	{1,1,1,2,2,2,5}
	00000000 00000000 00000000 00000001
	00000000 00000000 00000000 00000001
	00000000 00000000 00000000 00000001
	00000000 00000000 00000000 00000010
	00000000 00000000 00000000 00000010
	00000000 00000000 00000000 00000010
	00000000 00000000 00000000 00000101

	遍历数组对每一位上1出现的次数sum%3，剩下就是单独的那个数字
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		// TODO
		return -1;
	}
};

int main()
{
	int n[] = {1,1,1,-2,-2,-2,4,4,5,6,4,6,6}; 
	cout << "{1,1,1,-2,-2,-2,4,4,5,6,4,6,6}" << endl;	
	vector<int> vec(n, n+sizeof(n)/sizeof(int));

	Solution solu;
	cout << solu.singleNumber(vec) << endl;
	return 0;
}
