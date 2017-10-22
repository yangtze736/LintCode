/*
   Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
   Do not allocate extra space for another array, you must do this in place with constant memory.
   For example, Given input array A = [1,1,2],
   Your function should return length = 2, and A is now [1,2]. 
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int> &nums) {
			if ( nums.empty() ) return 0;
			if ( nums.size() == 1 ) return 1;

			int index = 0;
			for ( int i = 0; i < nums.size(); i++ ) {
				if ( nums[index] != nums[i] ) {
					index ++;
					nums[index] = nums[i];
				}
			}
			return index + 1;
		}
};

/*
   class Solution {
   public:
   int removeDuplicates(vector<int>& nums) {
   return distance(nums.begin(), unique(nums.begin(), nums.end()));
   }
   };
 */

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

	for ( int  i = 0; i < vec.size(); i++ )	
		cout << vec[i] << " ";
	cout << endl;

	Solution solu;
	int ret = solu.removeDuplicates(vec);
	cout << ret << endl;

	/* 注意这里的ret, 不是vec.size() */
	for ( int i= 0; i < ret; i++ )	
		cout << vec[i] << " ";
	cout << endl;	

	return 0;
}
