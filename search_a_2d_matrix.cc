/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 . Integers in each row are sorted from left to right.
 . The first integer of each row is greater than the last integer of the previous row.
 
For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

解法一
. 先搜索行的位置然后在该行上找是否有目标值

解法二
. 搜索一个二维矩阵，由于给的矩阵是有序的，所以很自然的想到要用**二分查找法**，我们
	可以在第一列上先用一次二分查找法找到目标值所在的行的位置，然后在该行上再用一次二
	分查找法来找是否存在目标值

 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target ) {
		if(matrix.empty()) return false;
		if(target < matrix[0][0] || target > matrix.back().back()) return false;
	
		int m = matrix.size();
		int n = matrix.front().size();
		
		int first = 0;
		int last = m*n;

		while(first <= last) {
			int mid = first + (last-first)/2;
			if( matrix[mid/n][mid%n] == target ) return true;
			else if( matrix[mid/n][mid%n] < target ) first = mid+1;
			else last = mid-1;
		}

		return false;
	}
};

/*
class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if(matrix.empty()) return false;
		if(target < matrix[0][0] || target > matrix.back().back()) return false;

		int left = 0, right = matrix.size()-1;
		while( left <= right ) {
			int mid = (left+right)/2;
			if( matrix[mid][0] == target) return true;
			else if (matrix[mid][0] < target) left = mid + 1;
			else right = mid - 1;
		}
		int tmp = right;
		left = 0;
		right = matrix[tmp].size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (matrix[tmp][mid] == target) return true;
			else if (matrix[tmp][mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return false;
	}
};
*/
/*
	 class Solution {
	 public:
	 bool searchMatrix(vector<vector<int>> &matrix, int target) {
	 bool ret = false;
	 cout << "target: " << target << endl;

	 int row = 0;
	 for( int i=0; i < matrix.size(); i++ ) {
	 if( matrix[i][0] > target ) break;
	 else row++;
		}
		for( int i=0; i < matrix[0].size(); i++ ) {
			if( matrix[row-1][i] == target ) {
				cout << "matrix[" << row-1 << "][" << i <<"]" << endl;
				return true;
			}
		}

		return ret;
	}
};
*/
int main()
{
	int row[] = {1,3,5,7};
	int row1[] = {10,11,16,20};
	int row2[] = {23,30,34,50};
	vector<int> v( row, row+sizeof(row)/sizeof(int));
	vector<int> v1( row1, row1+sizeof(row1)/sizeof(int));
	vector<int> v2( row2, row2+sizeof(row2)/sizeof(int));
	vector<vector<int>> matrix;
	matrix.push_back(v);
	matrix.push_back(v1);
	matrix.push_back(v2);

	Solution solu;
	if ( solu.searchMatrix(matrix, 20) )
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}
