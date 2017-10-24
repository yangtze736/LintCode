/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

感觉像是泡泡堂里的炸弹，横竖扩展

分析
- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
- 扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
- 扫描除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
- 最后根据第一行第一列的flag来更新第一行第一列
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
 void setZeroes(vector<vector<int>> &matrix) {
  if(matrix.empty() || matrix[0].empty()) return;
  int m = matrix.size(), n = matrix[0].size();
  
  bool rowflag = false, colflag = false;
  for( int i = 0; i < m; i++ ) {
      if(matrix[i][0] == 0) { colflag = true; break; }
  }
  for( int i = 0; i < n; i++ ) {
      if(matrix[0][i] == 0) { rowflag = true; break; }
  }
  
  for( int i = 1; i < m; i++ ) {
    for( int j = 1; j < n; j++ ) {
      if( matrix[i][j] == 0 ) { matrix[0][j] = 0; matrix[i][0] = 0; }
    }
  }
  
  for( int i = 1; i < m; i++ ) {
    for( int j = 1; j < n; j++ ) {
      if( matrix[0][j] == 0 || matrix[i][0] == 0 ) { matrix[i][j] = 0; }
    }
  }
    
  if(rowflag) {
   for( int i = 0; i < n; i++ ) matrix[0][i] = 0;
  }
  if(colflag) {
   for( int i = 0; i < m; i++ ) matrix[i][0] = 0;
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
	vector< vector<int> > matrix;
	int n = 15;

	for (int i=1; i<=n; i++) {
		vector<int> v;
		for(int j=1; j<=n; j++){
			v.push_back( (i-1)*n + j );
		}
		matrix.push_back(v);
	}
	matrix[5][7] = 0;
	matrix[2][3] = 0;
	printMatrix(matrix);

	Solution solu;
	solu.setZeroes(matrix);
	printMatrix(matrix);	

	return 0;
}
