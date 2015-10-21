/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.*/




/*
class Solution {  
public:  
    bool canJump(int A[], int n) {  
        if(n==0||n==1){  
            return true;  
        }  
        int maxstep=A[0];  
        for(int i=1;i<n;i++){  
            if(maxstep==0) return false;  
            maxstep--;  
            if(maxstep<A[i]){  
                maxstep=A[i];  
            }  
            if(maxstep+i>=n-1){  
                return true;  
            }  
        }  
    }  
};  
*/


#include <iostream>

class Solution {
public:
    bool canJump(int A[], int n) {
    	for (int i = 0; i <= A[0]; ++i){
    		if(A[0] >= n-1) return true;
    		if(A[i] + i > A[0])
    			A[0] = A[i] + i;
    	}
    	return false;
    }
};

int main(int argc, char const *argv[])
{
	int a[]={3,2,1,0,4};
	Solution b;
	std::cout << b.canJump(a, 5) << std::endl;
	return 0;
}