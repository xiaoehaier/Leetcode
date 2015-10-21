/*
Given an array of integers, every element appears three times except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/




#include <iostream>

#define REPEAT_COUNT 3

using namespace std;

/*int singleNumber(int A[], int n) {
    int ones = 0, twos = 0, xthrees = 0;
    for(int i = 0; i < n; ++i) {
        twos |= (ones & A[i]);
        ones ^= A[i];
        xthrees = ~(ones & twos);
        ones &= xthrees;
        twos &= xthrees;
    }

    return ones;
}*/

class Solution {
public:
    int singleNumber(int A[], int n){
        int temp = 0;
        int result = 0;
		unsigned mask = 0x1;

        for (int i = 0; i < sizeof(int) * 8; 
        	++i, mask <<= 1, temp = 0){
        	
        	for (int j = 0; j < n; ++j)
        		temp += (mask & A[j]) ? 1 : 0; 

        	result |= (temp % REPEAT_COUNT) ? mask : 0;

        }

        return result;
    }
};


int main(int argc, char const *argv[])
{
	int A[] = {-1, -1, -1, -2, -2, -2, 3, 3, 3, -5};
    cout << sizeof(int) << endl;
	Solution a;
	cout << a.singleNumber(A, 10) << endl;

	return 0;
}