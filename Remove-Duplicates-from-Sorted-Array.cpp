/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].*/


#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n <= 0) return 0;
        int index = 0;
        for(int i=0; i<n; ++i){
        	if(A[index] != A[i]){
        		A[++index] = A[i];
        	}
        }
        return index+1;
        
    }
};

int main(int argc, char const *argv[])
{
	Solution a;
	int aa[]={1,1,1,1,1,1,1,1,2};
	int cnt = a.removeDuplicates(aa, 9);
	std::cout<<cnt<<std::endl;
	for (int i = 0; i < cnt; ++i)
	{
		std::cout<<aa[i]<<std::endl;
	}

	return 0;
}