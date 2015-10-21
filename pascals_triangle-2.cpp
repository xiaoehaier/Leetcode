/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/



#include <vector>
#include <iostream>


using namespace std;


//********************* 34 overflow****************
class Solution {
public:
    vector<int> getRow(int n) {
        
        if (n < 0) return vector<int>();

		vector<int> level;

		for (int i = 0; i <= n; i++){
			int k = (int)level.size();

			for(int j = k-1; j >= 1; j--)
				level[j]+=level[j-1];

			level.push_back(1);
		}
		return level;
    }
};

/*
********** 32 overflow ***********

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> result(rowIndex + 1);
		
        result[0] = result[rowIndex] = 1;

        for (int i = 1; i <= rowIndex/2; ++i){
        	result[i] = result[rowIndex - i] 
        	          = (result[i-1] * (rowIndex-i+1)) / i;
        }

        return result;
    }
};*/

int main(int argc, char const *argv[])
{
	Solution a;
	int row;
	vector<int> pt;
	cin >> row;
	pt = a.getRow(row);
	
	for (int i = 0; i < pt.size(); ++i)
		cout << pt[i] <<" ";
	
	cout << endl;
	
	return 0;
}