/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/


#include <iostream>
#include <algorithm>
using std::min;
using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
	double findKthSortedArrays(int A[], int m, int B[], int n, int k) 
	{
		//always assume that m is equal or smaller than n 
		if (m > n)  
        	return findKthSortedArrays(B, n, A, m, k);  
    	if (m == 0)  
        	return B[k - 1];  
    	if (k == 1)  
        	return min(A[0], B[0]);

    	//divide k into two parts  
    	int pA = min(k / 2, m), pB = k - pA;  
    	if (A[pA - 1] < B[pB - 1])  
        	return findKthSortedArrays(A + pA, m - pA, B, n, k - pA);  
    	else if (A[pA - 1] > B[pB - 1])  
        	return findKthSortedArrays(A, m, B + pB, n - pB, k - pB);  
    	else  
        	return A[pA - 1];  
	}


    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        int total = m + n;  
        if (total & 0x1)  
            return findKthSortedArrays(A, m, B, n, total / 2 + 1);  
        else  
            return (findKthSortedArrays(A, m, B, n, total / 2)  
                    + findKthSortedArrays(A, m, B, n, total / 2 + 1)) / 2;
    }
};


int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,4,5,6};
	int B[] = {1,2,7,8,9,10,11,12};
	int m = 6, n = 8;

	Solution s;
	cout << s.findKthSortedArrays(A,m,B,n,5) << endl;
	return 0;
}