#include <stdio.h>

#define min(x,y) ( ((x)>(y)) ? (y) : (x))


int trap(int A[], int n) {
    int waterSum = 0;
    int pre, after;

    for(pre=0; pre<n-1 && A[pre]<=A[pre+1]; ++pre);
    for(after=n-1; after>pre && A[after]<=A[after-1]; --after);

    printf("%d=========%d\n", pre, after);

    while(pre < after){
        int tmp = 0;
        for(int peak=pre+1; peak<=after; ++peak){
            if(peak == n-1 || A[peak] > A[peak+1] && A[peak] >= A[peak-1]){
                tmp = min(A[pre], A[peak])*(peak-pre-1)-tmp; 
                printf("%d %d %d\n", pre, peak, tmp); 
                pre = peak;      
                break;
            }
            tmp += A[peak];
        }

        if(tmp > 0)
            waterSum += tmp;
    }
    return waterSum;
}

int main(int argc, char const *argv[])
{
    int A[] = {0,1,2,3,4,5,0,7,8,9,12,13};
    printf("%d\n", trap(A, 12));
    return 0;
}