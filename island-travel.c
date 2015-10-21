#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

#define min(a,b) ( ((a)>(b)) ? (b):(a) )

struct Island
{
	int_fast64_t x;
	int_fast64_t y;
	int_fast64_t dist;
	short found;
};

void min12N(struct Island *islands, int islandCnt)
{
	int minIslandIndex = 0;
	int newFoundIndex = -1;

	while(!islands[islandCnt-1].found){
		int_fast64_t tmpDist = 0;

		for(int i=1; i<islandCnt; ++i){
			if(islands[i].found)
				continue;

			if(newFoundIndex == -1)
				newFoundIndex = i;

			tmpDist = min( abs(islands[i].x-islands[minIslandIndex].x), 
						   abs(islands[i].y-islands[minIslandIndex].y) );
			
			islands[i].dist = min(tmpDist+islands[minIslandIndex].dist, islands[i].dist);

			if(islands[i].dist < islands[newFoundIndex].dist)
				newFoundIndex = i;
		}

		islands[newFoundIndex].found = 1;
		minIslandIndex = newFoundIndex;
		newFoundIndex = -1;
	}
}

int main(int argc, char const *argv[])
{
	int islandCnt = 0;
	scanf("%d\n", &islandCnt);

	struct Island *islands = calloc(islandCnt, sizeof(struct Island));

	for(int i=0; i<islandCnt; ++i){
		scanf("%lld %lld", &(islands[i].x), &(islands[i].y));
		islands[i].dist = 0X7FFFFFFFFFFFFFFF;
	}
	islands[0].dist = 0;
		
	min12N(islands, islandCnt);

	printf("the distance is: %lld\n", islands[islandCnt-1].dist);

	return 0;
}