#include <stdlib.h>


int isUnderAttack(int *occupied, int occupiedSize, int cur)
	{
		for(int i=0; i < occupiedSize; ++i){
			if(occupied[i] == cur || occupied[i] == cur + occupiedSize - i
				|| occupied[i] == cur - occupiedSize + i)
				return 1;
		}
		return 0;
	}
	
void tryQueen(int *result, int *occupied, int n, int index)
	{
		for(int i=0; i<n; ++i){
			if(!isUnderAttack(occupied, index, i)){
				
				occupied[index]=i;
				if(index == n-1){
					++(*result);	
					//printO(occupied);
				}
				else
					tryQueen(result, occupied, n, index+1);
			}
		}
		
	}


     int totalNQueens(int n) {
         int result = 0;
         int occupied[n];
         tryQueen(&result, occupied, n, 0);
         return result;
    }



int main(int argc, char const *argv[])
{
	printf("%d\n", totalNQueens(1));
	return 0;
}