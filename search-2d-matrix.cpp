/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if (matrix.size() == 0) return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int head = 0, tail = row-1;
        
        while (1) {
        	if (head > tail) return false;

        	int tmp = (head + tail)/2;

        	if (matrix[tmp][0] > target) 
        		tail = tmp - 1;
        	else if (matrix[tmp][0] == target)
        		return true;
        	else if (matrix[tmp][col-1] < target)
        		head = tmp + 1;
        	else {
        		row = tmp;
        		head = 0;
        		tail = col-1;
        		break;
        	}
        }

        while (1) {
        	if (head > tail) return false;

        	int tmp = (head + tail)/2;

        	if (matrix[row][tmp] > target) 
        		tail = tmp - 1;
        	else if (matrix[row][tmp] == target)
        		return true;
        	else 
        		head = tmp + 1;    	
        }
    }
};


int main(int argc, char const *argv[])
{
	vector<vector<int> > tester;
	
	vector< int > c;
	c.push_back(1);
	c.push_back(3);
	/*c.push_back(5);
	c.push_back(7);*/
	tester.push_back(c);
	/*vector< int > a;
	a.push_back(10);
	a.push_back(11);
	a.push_back(16);
	a.push_back(20);
	tester.push_back(a);*/

	Solution b;
	if (b.searchMatrix(tester, 2))
		cout << "found" << endl;
	else 
		cout << "nope" << endl;
	return 0;
}