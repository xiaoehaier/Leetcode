#include <stdlib.h>

int *plusOne(int *digits, int len, int *newLen) {
    *newLen = len;
    int *newDigits = calloc(len+1, sizeof(int));
    ++digits[len-1];
    
    while(len--){
        newDigits[len+1] += digits[len];
        
        if(newDigits[len+1] >= 10){
            newDigits[len+1] -= 10;
            newDigits[len] = 1;
        }
    }
    
    if(!newDigits[0])
        return newDigits+1;
    
    ++*newLen;
    return newDigits;
}

int main(int argc, char const *argv[])
{
    int digits[] = {9,8};
    int *newDigits = NULL;
    int newLen;
    newDigits = plusOne(digits, 2, &newLen);
    printf("%d\n", newLen);
    for(int i=0; i<newLen; ++i)
        printf("%d", newDigits[i]);

    printf("\n");
    printf("%d---%d\n", newDigits+1, newDigits+2);
    return 0;
}