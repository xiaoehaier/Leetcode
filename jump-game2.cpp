/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)*/

#include <iostream>

/*
class Solution {  
public:  
    int jump(int A[], int n) {  
        int ret = 0;//当前跳数  
        int last = 0;//上一跳可达最远距离  
        int curr = 0;//当前一跳可达最远距  
        for (int i = 0; i < n; ++i) {  
            //无法向前继跳直接返回  
            if(i>curr){  
                return -1;  
            }  
            //需要进行下次跳跃，则更新last和当执行的跳数ret  
            if (i > last) {  
                last = curr;  
                ++ret;  
            }  
            //记录当前可达的最远点  
            curr = max(curr, i+A[i]);  
        }  
  
        return ret;  
    }  
};  

*/
class Solution {
public:
    int jump(int A[], int n){
    	if(n == 1) return 0;
    	A[n-1] = 0;
    	int index[] = {0,1};
    	while(1){
    		for (int i = index[0]; i < index[1]; ++i){
    			if(A[i] + i > index[0])
    				index[0] = A[i] + i;
    		}

    		++A[n-1];

    		if(index[0] >= n-1)
    			return A[n-1];

    		A[0] = index[0];
    		index[0] = index[1];
    		index[1] = A[0]+1;
    	}
    }
};

int main(int argc, char const *argv[])
{
	int A[] = {2,3,1,1,4};
	Solution b;
	std::cout << b.jump(A, 5) << std::endl;
	return 0;
}