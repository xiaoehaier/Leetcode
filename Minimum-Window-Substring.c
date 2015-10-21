#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* minWindow(char* s, char* t) {
    int charT[127];
    int charS[127];
    memset(charT, 0, sizeof(int)*127);
    memset(charS, 0, sizeof(int)*127);
    charT[0] = -1;

    //head tail
    char *result[2] = {NULL, NULL};
    
    int tSize = 0, findSize = 0;
    for(; *t; ++t, ++tSize)
        ++charT[*t];
        
    for(char *head=NULL; *s; ++s){
        //skip char not in t
        if(charT[*s] == 0)
            continue;
            
        if(!head)
            head = s;
        
        ++charS[*s];
        if(charS[*s] <= charT[*s])
            ++findSize;
        
        while(findSize == tSize){
            if(charT[*head] == 0){
                ++head;
                continue;
            }
                
            //update min length
            if(charT[*head] == charS[*head]){
                --findSize;
                if(!result[0] || result[1]-result[0] > s-head){
                    result[0] = head;
                    result[1] = s;
                }
            }
            
            --charS[*(head++)];
        }
        
    }
    
    if(result[0]){
        *(result[1]+1) = '\0';
        return result[0];
    }else
        return (char*)&"";

}

int main(int argc, char const *argv[])
{
    char s[] = "cabefgecdaecf";
    char t[] = "cae";
    printf("%s\n", minWindow(s, t));
    return 0;
}