#include <stdio.h>

/*
int countOnes(int n)
{
	int result = 0;

	for(int i=1; i<=n; ++i){
		int j = i;
		while(j){
			if(j%10 == 1)
				++result;

			j /= 10;
		}
	}

	return result;
}
*/

int countOnes(int n)
{
	int countedN = 0;
	int result = 0;

	for(int i=1, j=0; n; i*=10, n/=10, ++j){
		int curr = n%10;

		if(curr == 0)
			continue;

		result += (curr == 1 ? countedN+1 : i) + i/10*curr*j;

		countedN += curr*i;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;

	while(~scanf("%d", &n)){
		printf("%d\n", countOnes(n));
	}

	return 0;
}