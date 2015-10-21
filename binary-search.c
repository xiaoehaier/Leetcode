#include <stdio.h>
#include <stdbool.h>


bool binary_search(int *array, int target, int n)
{
	int head = 0, tail = n-1, mid = 0;
	
	while(head <= tail){
		mid = (head+tail)>>1;
		if(array[mid] == target) return true;
		array[mid] > target ? tail = mid-1 : (head = mid+1);
	}

	return false;
}

int main(int argc, char const *argv[])
{
	int x, n;
	int nums[128];
	
	while(~scanf("%d%d", &x, &n)){
		for(int i=0; i<n; ++i)
			scanf("%d", nums+i);
		printf("%s\n", binary_search(nums, x, n) ? "True" : "False");
	}

	return 0;
}

