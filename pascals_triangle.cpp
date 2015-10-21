/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pascal_triangle(numRows);

        for (int i = 0; i < numRows; ++i){
        	pascal_triangle[i].resize(i+1);

        	pascal_triangle[i][0] = 1;
        	pascal_triangle[i][i] = 1;

        	for (int j = 1; j < i; ++j)
        		pascal_triangle[i][j] = pascal_triangle[i-1][j-1]
        				+ pascal_triangle[i-1][j];     		
        	}
        

        return pascal_triangle;
    }
};