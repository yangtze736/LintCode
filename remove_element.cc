/*
 * Copyright (c) 2015 xxxx Inc, All rights reserved.
 * Created: 2017-10-22
 */

/*
Given an array and a value, remove all instances of that value in place and return the new length. The order of elements can be changed. It doesn’t matter what you leave beyond the new length.
*/ 

#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
		int removeElement(vector<int> &nums, int target) {
			int index = 0;
			for ( int i = 0; i < nums.size(); i++ ) {
				if ( nums[i] != target ) {
					nums[index++] = nums[i];
				}
			}
			return index;
		}
};

int main()
{
	vector<int> vec;
	vec.push_back(12);
	vec.push_back(7);
	vec.push_back(2);
	vec.push_back(8);
	vec.push_back(12);
	vec.push_back(8);
	vec.push_back(6);

	for ( auto i : vec ) cout << i << " ";
	cout << endl;
		
	int target = 8;
	cout << "target: " << target << endl;

	Solution solu;
	int ret = solu.removeElement(vec, target);
	for ( int i = 0; i < ret; i++ ) {
		cout << vec[i] << " ";
	}
	cout << endl;

	return 0;
}
