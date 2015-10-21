#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 0x7fffffff


int divide(int dividend, int divisor) {
    if(divisor == 0)
        return MAX_INT;
    
    int flag = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -1 : 1;
    unsigned dividendAbs = abs(dividend), divisorAbs = abs(divisor);
    unsigned result = 0;
        
    unsigned mask = 1;
    
    printf("%u %u %d\n", dividendAbs, divisorAbs, flag);

    while(divisorAbs < dividendAbs){
        divisorAbs <<= 1;
        mask <<= 1;
    }
    
    printf("%u\n", mask);

    while(mask){
        if(dividendAbs >= divisorAbs){
            result |= mask;
            dividendAbs -= divisorAbs;
        }
        
        divisorAbs >>= 1;
        mask >>= 1;
    }
    
    if(flag == 1)
        return result > MAX_INT ? MAX_INT : (int)result;
    
     return -result;
    
}

int main(int argc, char const *argv[])
{
    int a = -2147483648, b = -1;

    printf("%d\n", divide(a, b));
    printf("%u\n", 0-a);
    return 0;
}