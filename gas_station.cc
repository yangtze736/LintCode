/*
There are N gas stations along a circular route, where the amount
of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of
gas to travel from station i to its next station (i+1). You begin
the journey with an empty tank at one of the gas stations.

Return the starting gas station’s index if you can travel around 
the circuit once, otherwise return -1. 

Note: The solution is guaranteed to be unique.

分析

 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
	public:
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			// TODO
			return -1;
		}
};

int main()
{
	int gas[] = {13, 5, 6, 8, 12, 4};
	int cost[] = {6, 8, 8, 9, 5, 8};
	vector<int> vgas(gas, gas+sizeof(gas)/sizeof(int));
	vector<int> vcost(cost, cost+sizeof(cost)/sizeof(int));

	Solution solu;
	cout << solu.canCompleteCircuit(vgas, vcost) << endl;

	return 0;
}
