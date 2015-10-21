#include <stdio.h>
#include <string.h>

//char *是字符串常量，在常量区，只读；
//char [] 是变量，可修改；
char result[1024];

int lcp(char *strs[], int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return strlen(strs[0]);
    
    int left = lcp(strs, n/2);
    int right = lcp(strs+n/2, n-n/2);

    if(!left || !right)
        return 0;
    
    
    if(left > right)
        left = right;
    
    for(int i=0; i<left; ++i){
        if(strs[0][i] != strs[n/2][i])
            return i;
    }
}

char *longestCommonPrefix(char *strs[], int n) {
    int length = lcp(strs, n);
    if(!length) return NULL;
    for(int i=0; i<length; ++i){
        result[i] = strs[0][i];
    }
    return result;
}


int main(int argc, char const *argv[])
{
    char *s[] = {"",""};
    printf("%s\n", longestCommonPrefix(s, 1));
    return 0;
}