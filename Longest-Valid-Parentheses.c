#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int len = strlen(s), cnt = 0, tmp = 0;
    int buffer[len+1];
    int bTop = 0;
    
    for(int i=0; i<len; ++i){
        if(s[i] == '('){
            buffer[bTop++] = i;
            continue;
        }
        
        
        if(bTop > 0){
            s[i] = 2;
            s[buffer[--bTop]] = 0;
        }
    }
    
    for(int i=0; i<len; ++i){
        if(s[i] > 2){
            cnt = cnt < tmp ? tmp : cnt;
            tmp = 0;
            continue;
        }
        
        tmp += s[i];
    }
    
    return cnt>tmp ? cnt : tmp;
}

int main(int argc, char const *argv[])
{
    char s[] = "))))))(((((((((()())()((((((((((()()()()()()()";
    printf("%s\n", s);
    printf("%d\n", longestValidParentheses(s));
    printf("%s\n", s);
    return 0;
}