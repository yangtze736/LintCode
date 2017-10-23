/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.

uint64_t num = 78945612399;
int n[] = {7,8,9,4,5,6,1,2,3,9,9};
vector<int> vec(n, n+sizeof(n)/sizeof(int));
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int n = digits.size();

		for ( int i = n-1; i >=0; i-- ) {
			if ( digits[i] == 9 ) {
				digits[i] = 0;
				if ( i == 0 ) digits.insert(digits.begin(),1);
				continue;
			}
			digits[i] += 1;
			break;
		}

		return digits;
	}
};

int main()
{
	int n[] = {7,8,9,4,5,6,1,2,3,9,9};
	vector<int> vec(n, n+sizeof(n)/sizeof(int));
	for ( auto i : vec )
		cout << i << " ";
	cout << endl;

	Solution solu;
	vector<int> result = solu.plusOne(vec);
	for ( auto i : result )
		cout << i << " ";
	cout << endl;

	return 0;
}
