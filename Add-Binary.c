char *addBinary(char *a, char *b) {
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    int lengthSum = lengthA;
    
    if(lengthA < lengthB)
        lengthSum = lengthB;
        
    ++lengthSum;
    char *sum = calloc(lengthSum+1, sizeof(char));

    while(lengthA || lengthB){
        --lengthSum;
        sum[lengthSum] += (lengthA ? a[--lengthA]-'0' : 0) + (lengthB ? b[--lengthB]-'0' : 0);
        sum[lengthSum-1] = sum[lengthSum]/2;
        sum[lengthSum] %= 2;
        sum[lengthSum] += '0';
    }
    
    if(!sum[0])
        return sum+1;
    
    sum[0] = '1';
    return sum;
    
}

int main(int argc, char const *argv[])
{
    char *a="1111";
    char *b="0100";
    printf("%s\n", addBinary(a, b));
    return 0;
}