/*  
	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
	For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
	Your algorithm should run in O(n) complexity.

	分析
	使用一个集合set存入所有的数字，然后遍历数组中的每个数字，如果其在集合中存在，那么将其移除，然后分别用两个变量pre和next算出其前一个数跟后一个数，然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，直至pre不在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，更新res即可.
 */ 

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
	public:
		int longestConsecutive(const vector<int> &nums) {
			int res = 0;
			unordered_set<int> s(nums.begin(), nums.end());
			/*
			Unordered sets are containers that store **unique** elements in no particular order.
			for ( auto i : s ) cout << i << " ";
			cout << endl;
			*/

			for ( auto val : nums ) {
				if ( !s.count(val) ) continue;
				s.erase(val);
				int pre = val - 1, next = val + 1;
				while (s.count(pre)) s.erase(pre--);
				while (s.count(next)) s.erase(next++);
				res = max(res, next - pre - 1);
			}
			return res;
		}

};

int main()
{
	int n[] = {10,8,15,2,3,5,5,7,8,9};
	vector<int> vec(n, n+sizeof(n)/sizeof(int));

	for ( auto i : vec )	
		cout << i << " ";
	cout << endl;

	Solution solu;
	int ret = solu.longestConsecutive(vec);
	cout << ret << endl;

	return 0;
}
