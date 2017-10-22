/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

分析
	样例 ：1  2  7  4  3  1

	从末尾往前看数字逐渐变大，到了某个数字n时才减小，我们再从后往前找第一个比n大的数字m，交换n和m，再把此时m后面的所有数字转置一下（转置前已是有序状态）即可，步骤如下：
	
	1   2   7   4   3   1
	1  *2*  7   4  *3*  1
	1  *3*  7   4  *2*  1
	1   3  *1* *2* *4* *7*
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		int i, j, n = nums.size();

		for ( i = n - 2; i >= 0; i-- ) {
			if ( nums[i] < nums[i+1] ) {
				for ( j = n -1; j >= i; j-- ) {
					if ( nums[i] < nums[j] ) break;
				}
				swap(nums[i], nums[j]);
				reverse(nums.begin() + i + 1, nums.end() );

				//从末尾往前看第一次满足nums[i] < nums[i+1]
				//交换m和n将m后面数组转置即退出
				return;
			}
		}
		reverse(nums.begin(), nums.end());
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(1);

	for ( auto i : vec )
		cout << i << " ";
	cout << endl;

	Solution solu;
	solu.nextPermutation(vec);

	for ( auto i : vec )
		cout << i << " ";
	cout << endl;

	return 0;
}
