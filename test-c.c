#include <stdlib.h>
#include <stdio.h>





int main(int argc, char const *argv[])
{
	char *str = "hello";

	int array[2][5];
	int arraya[10];
	int *p = arraya;
	int *pa = &arraya;


	printf("%s\n", str);
	printf("%d %d %d %d\n", sizeof(array), sizeof(&array), sizeof(*p), sizeof(*pa));



	return 0;
}

