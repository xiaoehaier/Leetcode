#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *infoCard(char *a)
{
	int *info = (int*)calloc(2, sizeof(int));

	if(*a == 'j'){
		info[0] = 6;
		return info;
	}

	switch(*a){
		case '1': info[1] = 10; break;
		case 'A': info[1] = 14; break;
		case '2': info[1] = 15; break;
		case 'J': info[1] = 11; break;
		case 'Q': info[1] = 12; break;
		case 'K': info[1] = 13; break;
		default: info[1] = *a-'0';
	}

	while(*a)
		if(*(a++) == ' ')
			++info[0];
	
	++info[0];

	return info;
}

int main(int argc, char const *argv[])
{
	char a[64], b[64];

	while(~scanf("%[^-]-%[^\n]\n", a, b)){
		//printf("%s................%s\n", a, b);

		int *ai = infoCard(a), *bi = infoCard(b);

		if(ai[0] == 6)
			printf("%s\n", a);
		else if(bi[0] == 6)
			printf("%s\n", b);
		else if(ai[0] == bi[0])
			printf("%s\n", ai[1] > bi[1] ? a : b);
		else if(ai[0] == 4)
        	printf("%s\n", a);
    	else if(bi[0] == 4)
			printf("%s\n", b);
    	else
			printf("ERROR\n");

		free(ai);
		free(bi);
	}

	return 0;
}