/*
Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/


#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n){
        for (int i = 1; i < n; ++i)
            A[0] ^= A[i];
        
        return A[0];
    }
};


/*
class Solution_old {
public:
    int singleNumber(int A[], int n){
    	int half = (n - 1) / 2;

        for (int i = 0; i < half; ++i){
        	for (int j = i + 1; j < n; ++j){

        		if (A[j] == A[i]){
        			swap(A[j], A[i + half]);
        			break;
        		}

        		if ((j == n-1) && (A[i] != A[i + half]))
        			return A[i];
        		
            }  	
        }

        return A[n - 1];
    }
};*/



int main(int argc, char const *argv[])
{
	int A[] = {1, 1, 2, 5, 4, 6, 3, 3, 6, 4, 5};

	Solution a;
	cout << a.singleNumber(A, 3) << endl;
	return 0;
}