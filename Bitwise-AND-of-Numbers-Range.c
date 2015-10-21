#include <stdio.h>

int rangeBitwiseAnd(int m, int n) {
    unsigned result = 0, mask = 1;
    int tmp = m&n, diff = n-m;
    
    for(; m||n; mask<<=1, n>>=1, m>>=1);

    printf("%u\n", mask);


    while((mask>>=1) > diff){
        if(mask & tmp)
            result |= mask;
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
	int m = 64, n = 106;

	printf("%d\n", rangeBitwiseAnd(m, n));
	return 0;
}