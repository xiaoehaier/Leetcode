int numDecodings(char *s) {
    if(!s || !*s) return 0;
    if(*s == '0') return 0;
    int result[2] = {1, 1};

    for(int i=1; ; ++i){
        if(!s[i])
            return result[(i-1)%2];
            
        int tmp = (s[i-1]-'0')*10 + s[i]-'0';
        printf("%d\n", tmp);
        
        if(tmp == 0)
            return 0;
            
        if(tmp < 10 || tmp > 26){
            result[i%2] = result[(i-1)%2];
            continue;
        }
        
        if(tmp != 10 && tmp != 20)
            result[i%2] += result[(i-1)%2];
    }
}

int main(int argc, char const *argv[])
{
    char s[] = "27";
    printf("%d\n", numDecodings(s));
    return 0;
}