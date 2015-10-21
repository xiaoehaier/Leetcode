#include <stdio.h>

int hammingWeight(unsigned n) {
    int onebits = 0;

    while(n){
    	++onebits;
    	n &= n-1;
    }  

    return onebits;
}


int main(int argc, char const *argv[])
{
	unsigned number =0;
	scanf("%d", &number);
	printf("the number: %d\n", number);
	printf("1s in the number: %d\n", hammingWeight(number));
	return 0;
};