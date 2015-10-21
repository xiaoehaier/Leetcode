#include <stdlib.h>
#include <stdio.h>

char **letterCombinations(char *digits, int *returnSize) {
    if(!digits || !digits[0]) return NULL;
    
    static char *map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    *returnSize = 1;
    int i = 0;
    for(; digits[i]; ++i){
        *returnSize *= digits[i] == '7' || digits[i] == '9' ? 4 : 3;
    }
    
    char **result = calloc(*returnSize, sizeof(char *));
    for(int j=0; j<*returnSize; ++j)
        result[j] = calloc(i+1, sizeof(char));
    
    int mod = *returnSize;
    for(int j=0; j<i; ++j){
        int len = digits[j] == '7' || digits[j] == '9' ? 4 : 3;
        mod /= len;
        for(int k=0; k<*returnSize; ++k){
            result[k][j] = map[digits[j]-'2'][k/mod%len];
        }
    }
    
    return result;
}


int main(int argc, char const *argv[])
{
    char *input = "222";
    int mySize;
    char **result = letterCombinations(input, &mySize);
    
    for(int i=0; i<mySize; ++i)
        printf("%s\n", result[i]);
    /* code */
    return 0;
}