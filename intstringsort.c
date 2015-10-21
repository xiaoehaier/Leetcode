#include <stdio.h>
#include <stdlib.h>

int* intSortString(int n)
{
	int *result = malloc(n*sizeof(int));
	int buff[16];
	buff[0] = n;
	buff[1] = 1;
	int ir = 0, ib = 1, digits = 1;

	while(buff[0]/=10) ++digits;

	while(buff[0] == 0){
		while(buff[ib] / 10 > buff[ib-1])
			++buff[--ib];

		while(ib != digits){
			buff[ib+1] = buff[ib]*10;
			result[ir++] = buff[ib++];
		}

		if(buff[ib] > n){
			++buff[--ib];
			--digits;
			continue;
		}
		
		result[ir++] = buff[ib]++;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int *intString = intSortString(n);
	for(int i=0; i<n; ++i)
		printf("%d ", intString[i]);
	free(intString);
	return 0;
}