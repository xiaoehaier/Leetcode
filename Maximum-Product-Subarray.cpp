/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

struct Info
{
	int position0;
	int negCnt;
	Info(int a, int b):position0(a), negCnt(b){}
};

class Solution {
public:

    int maxProduct(int A[], int n) {
        vector<Info> seg;
        if (A[0] != 0) seg.push_back(Info(-1,0));
        int cnt = 0;
        int max = A[0];

        for (int i = 0; i < n; ++i) {
        	if (A[i] < 0) ++cnt;
        	if (A[i] == 0) {
        		seg.push_back(Info(i, cnt));
        		cnt = 0;
        	}
        }

        if (A[n-1] != 0) seg.push_back(Info(n,cnt));

        for (int i = 1; i < seg.size(); ++i) {
    
        	if (seg[i].negCnt % 2 == 0) {
        		int tmp = A[seg[i-1].position0+1];
        		for (int j = seg[i-1].position0+2; 
        			j < seg[i].position0; ++j) {
        			tmp *= A[j];
        		}
        		if (tmp > max) max = tmp;

        	} else {
        		int j;
        		for (j = seg[i-1].position0+1; A[j] > 0; ++j) {}
        		int k;
        		for (k = seg[i].position0-1; A[k] > 0; --k) {}
        		int tmp1 = A[seg[i-1].position0+1];
        		for (int m = seg[i-1].position0+2; m < k; ++m)
        			tmp1 *= A[m];
        		int tmp2 = A[seg[i].position0-1];
        		for (int m = seg[i].position0-2; m > j; --m)
        			tmp2 *= A[m];
        		
        		int tmp = tmp1 > tmp2 ? tmp1 : tmp2;
        		if (max < tmp) max = tmp;

        		if (max < 0 && (seg[i].position0 != n || seg[i-1].position0 != -1))
        			max = 0;		
        	}
        }

        return max;    		
    }
};

int main(int argc, char const *argv[])
{
	int test[] = {-2};
	

	Solution a;
	cout << a.maxProduct(test, 1) << endl;
	return 0;
}