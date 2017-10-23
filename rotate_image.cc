/*
You are given an n × n 2D matrix representing an image. 
Rotate the image by 90 degrees (clockwise).
Follow up: Could you do this in-place?

分析
在计算机图像处理里旋转图片是很常见的操作，图片的本质是二维数组，
所以就变成了对数组的处理。翻转的本质就是某个位置上数移动到另一个位置上，
比如用一个简单的例子来分析：

1  2  3　　　 　　 7  4  1　

4  5  6　　-->　　 8  5  2　　

7  8  9 　　　 　　9  6  3

对于90度的翻转有很多方法，其中一种如下
从对角线为轴翻转，然后再以x轴中线上下翻转即可得到结果：

 1  2 *3*　　  　　 9  6  3　　　　　  7  4  1

 4 *5* 6　　-->　　*8**5**2*　　 -->   8  5  2

*7* 8  9 　　　 　　7  4  1　　　　　  9  6  3

 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		int n = matrix.size();
		for ( int i = 0; i < n-1; i++ ) {
			for(int j = 0; j < n-i; j++ ) {
				swap(matrix[i][j], matrix[n-1-j][n-1-i] );
			}
		}
		for ( int i = 0; i < n/2; i++ ) {
			for ( int j =0; j < n ; j++ ) {
				swap(matrix[i][j], matrix[n-1-i][j]);
			}
		}
	}
};

void printMatrix(vector<vector<int> > &matrix) 
{
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
	vector<vector<int>> matrix;
	for ( int i = 1; i <= 3; i++ ) {
		vector<int> v;
		for (int j= 1; j <= 3; j++ )
			v.push_back((i-1)*3+j);
		matrix.push_back(v);
	}

	cout << "matrix[1].size(): " << matrix[1].size() << endl;
	cout << "matrix.size(): " << matrix.size() << endl;

	printMatrix(matrix);
	Solution solu;
	solu.rotate(matrix);
	printMatrix(matrix);
	
	return 0;
}
