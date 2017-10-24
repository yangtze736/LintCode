/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

分析
  设f(n)表示爬n阶楼梯的不同方法数，为了爬到第n阶楼梯，有两个选择：
  * 从第n-1阶前进1步
  * 从第n-2阶前进2步
  因此有f(n) = f(n-1) + f(n-2), 其中f(1) = 1, f(2) = 2
 */

#include <vector>
#include <iostream>

using namespace std;
/*
class Solution{
public:
  int climbStairs(int n) {
    if( n <= 0 ) return 0;
    if( n == 1 || n == 2 ) return n;
  
    vector<int> vec(n);
    vec[0] = 1, vec[1] = 2;
    
    for( int i = 2; i < n; i++ ) {
      vec[i] = vec[i-1] + vec[i-2];
    }
    
    return vec[n-1];
  }
};
*/


class Solution {
public:
  int climbStairs(int n) {
    if( n <= 0 ) return 0;
    
    /*
     * a    b
     *      a    b
     *           a    b
     *                a    b
     *                     .....
     *
     * 1    2    3    5    8    13    21    34    55    89
     */
    int a = 1, b = 1;
    while (n--) {
      b = a + b;
      a = b - a;
    }
    
    return a;
  }
};

int main()
{
  Solution solu;
  int n = 10;
  cout << "n numbers: " << n << endl;
  cout << "fibonacci: " << solu.climStairs(n) << endl;
  return 0;
}
