#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {

    	if (x == 0) return 0;
    	if (x == 1) return 1.0;
    	if (n == 0) return 1.0;

    	if (n < 0) return 1 / (pow(x, ~n)*x);
    	

        double result = 1.0;
        for (; n > 0; n >>= 1, x *= x){
            if (n & 1)  result *= x;
        }
            
        return result;
    }
};


int main(int argc, char const *argv[])
{
	Solution a;
	cout << a.pow(-1, -2147483648) << endl;
	return 0;
}