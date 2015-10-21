/*Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.*/

#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
    	int cnt0 = 0;
        while(n){
        	cnt0 += (n /= 5);
        }
        return cnt0;
    }
};

int main(int argc, char const *argv[])
{
	Solution a;
	std::cout << a.trailingZeroes(20) << std::endl;
	return 0;
}