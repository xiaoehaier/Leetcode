#include <stdlib.h>
#include <stdio.h>

int countPrimes(int n) {
    printf("112\n");
    char *record = calloc(n/8 + 1, sizeof(char));
    int result = 0;
    

    printf("1\n");
    for(int i=2; i*i<=n; ++i){
        if(record[i])
            for(int k=i; k<=n; k+=i)
                record[k] = 0;
    }
    printf("2\n");
    for(int i=2; i<=n; ++i){
        if(record[i])
            ++result;
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
    int n = 500000;

    printf("%d\n", countPrimes(n));
    return 0;
}