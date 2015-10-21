#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printO(vector<int > &result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] <<"  " ; 
	}
	cout << endl;
		
}
class Solution {
public:
	bool isUnderAttack(vector<int> &occupied, int cur)
	{
		int occupiedSize = occupied.size();
		for(int i=0; i < occupiedSize; ++i){
			if(occupied[i] == cur || occupied[i] == cur + occupiedSize - i
				|| occupied[i] == cur - occupiedSize + i)
				return true;
		}
		return false;
	}

	vector<string> generate(vector<int> &occupied, int n){
		vector<string> oneResult;
		for(int i=0; i<occupied.size(); ++i){
			oneResult.push_back(string(occupied[i], '.') + 'Q' + string(n-occupied[i]-1, '.'));
		}
		return oneResult;
	}


	void tryQueen(vector<vector<string> > &result, vector<int> &occupied, int n)
	{
		for(int i=0; i<n; ++i){
			if(!isUnderAttack(occupied, i)){
				//cout << "Occupied " << i << endl; 
				occupied.push_back(i);
				if(occupied.size() == n){
					result.push_back(generate(occupied, n));	
					//printO(occupied);
				}
				else
					tryQueen(result, occupied, n);

				occupied.pop_back();
			}
		}
		
	}

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> occupied;
        tryQueen(result, occupied, n);
        return result;
    }
};

void printVVS(vector<vector<string> > &result)
{
	for(int i=0; i<result.size(); ++i){
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << endl;

		cout << endl;
	}
		
}



int main(int argc, char const *argv[])
{
	Solution a;
	vector<vector<string> > result;
	result = a.solveNQueens(16);
	printVVS(result);
	return 0;
}