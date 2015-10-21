/*There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> gas;
	vector<int> cost;
	gas.push_back(1);
	gas.push_back(3);
	gas.push_back(5);
	cost.push_back(2);
	cost.push_back(1);
	cost.push_back(6);

	Solution a;
	cout << a.canCompleteCircuit(gas, cost) << endl;
	return 0;
}