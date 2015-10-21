#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PM '+'+'-'

int calculate(char* s) {
    //remove ()
    char *buffer[strlen(s)];
    int index = -1;
    
    for(char *i=s; *i; ++i){
        if(*i == '('){
            *i = ' ';
            buffer[++index] = i;
            continue;
        }
        
        if(*i == ')'){
            *i = ' ';
            --index;
            continue;
        }
        
        if(index>-1 && buffer[index] != s && *(buffer[index]-1) == '-')
            if(*i == '+' || *i == '-')
                *i = PM - *i;
        
    }
    
    int result = 0, tmp = 0;
    char op = '+';
    while(1){
        if(isdigit(*s)){
            tmp *= 10;
            tmp += *(s++) - '0';
            continue;
        }
        
        
        result += (op == '+' ? tmp : -tmp);
        tmp = 0;
        
        if(*s != ' ')
            op = *s;

        if(!*(s++))
            return result;
    }
    
}

int main(int argc, char const *argv[])
{
    char expr[1024];
    printf("input express:\n");
    scanf("%s", expr);

    printf("%d\n", calculate(expr));

    return 0;
}