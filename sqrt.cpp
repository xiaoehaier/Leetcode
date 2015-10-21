#include <iostream>
#include <stdlib.h>


using namespace std;


class Solution {
public:
    int sqrt(int x) {
        if (x ==0)
            return 0;

        double pre;
        double cur = 1;

        do{
            pre = cur;
            cur = x / (2 * pre) + pre / 2.0;
        } while (abs(cur - pre) > 0.00001);

        return int(cur);
    }
    
};


/*class Solution {
public:
    int sqrt(int x) {

    	int part[32];
    	int cnt;
    	int tmp[2] = {0};
    	
    	for (cnt = 1; x != 0; ++cnt){
    		part[cnt] = x % 100;
    		x /= 100;
    	}

    	for (int i = cnt - 1; i > 0; --i){
    		tmp[0] ? tmp[1] = part[i]/(tmp[0]*20) : tmp[1] = 9;
    			

    		while ((tmp[0] * 20 + tmp[1]) * tmp[1] > part[i])
    			--tmp[1];

    		part[i-1] += (part[i] - tmp[1]*(tmp[0]*20 + tmp[1])) * 100;

    		tmp[0] = tmp[0]*10 + tmp[1];
    		
    	}

    	return tmp[0];
    }
};*/



int main(int argc, char const *argv[])
{
	Solution a;
	int hello = 1478523691;
	cout << a.sqrt(hello) << endl << a.sqrt(2) << endl;
	return 0;
}