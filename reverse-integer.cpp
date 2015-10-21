/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/



#include <iostream>
#include <stdlib.h>


class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        int sign = x > 0 ? 1 : -1;

        x = abs(x);
        
        do{
           	result = result * 10 + x % 10;
        }while (x /= 10);

        return result * sign;
    }
};

using namespace std;

int main(int argc, char const *argv[])
{
	int tmp = 100000000;
	Solution a;
	cout << tmp << "reverse is :" << a.reverse(tmp) << endl;
	return 0;
}