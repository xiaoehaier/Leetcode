int rob(int num[], int n) {
    int getSum = 0, lostSum = 0;
    int isafe = 1;
    
    for(int i=0; i<n; ++i){
        if(isafe){
            if(i == n-1){
                getSum += num[i];
                continue;
            }
            if(num[i] > num[i+1]){
                getSum += num[i];
                lostSum += num[i+1];
            }else{
                getSum += num[i+1];
                lostSum += num[i];
                isafe = 0;
            }
            ++i;
            continue;
        }
        
        if(lostSum + num[i] > getSum){
            int tmp = lostSum + num[i];
            lostSum = getSum;
            getSum = tmp;
            continue;
        }
        
        isafe = 1;
        lostSum += num[i];
    }
    
    return getSum;
}

int main(int argc, char const *argv[])
{
    int test[] = {8,2,8,9,2};
    printf("%d\n", rob(test, 5));
    return 0;
}