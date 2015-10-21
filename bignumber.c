#include <stdint.h>

#define N 512

void fac(uint32_t n)
{
	uint32_t *result = calloc(n, 4);
	uint64_t tmp;
	result[n-1] = n;
	for(int i=n-1; i>=1; --i){
		tmp = result[n-1] * i;
		if()
	}
}