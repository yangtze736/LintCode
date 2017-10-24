/*
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

分析
	类似trapping_rain_water
	两遍遍历的解法
		1.首先初始化每个人一个糖果，然后这个算法需要遍历两遍
		2.第一遍从左向右遍历，如果右边的小盆友的等级高，则加一个糖果，这样保证了一
			个方向上高等级的糖果多。
		3.再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，则左
			边糖果数为右边糖果数加一。
		4.最后再把所有小盆友的糖果数都加起来返回即可
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		int res = 0;
		vector<int> nums(ratings.size(), 1);
		for( int i = 0; i < ratings.size()-1; i++ )	{
			if( ratings[i+1] >ratings[i] ) nums[i+1] = nums[i]+1;
		}
		for( auto i : nums )
			cout << i << " ";
		cout << endl;

		for( int i = ratings.size()-1; i > 1; i-- ) {
			if( ratings[i-1] > ratings[i] ) nums[i-1] = nums[i]+1;
		}
		for( auto i : nums )
			cout << i << " ";
		cout << endl;
		
		for( auto i : nums ) res += i;
		return res;
	}
};


int main()
{
	int n[] = {1, 3, 5, 5, 7, 9, 8, 4, 1};
	vector<int> vec(n, n+sizeof(n)/sizeof(int));
	cout << "vector: {1, 3, 5, 5, 7, 9, 8, 4, 1}" << endl;
	cout << "result: {1, 2, 3, 1, 2, 4, 3, 2, 1}" << endl;

	Solution solu;
	cout <<	solu.candy(vec) << endl;
	return 0;
}


