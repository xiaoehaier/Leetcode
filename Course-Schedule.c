#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define true 1
#define false 0
typedef char bool;


/* time limit exceeded
bool dfs(bool *isFinding, bool **clue, int n, int toFind)
{
	isFinding[toFind] = true;

	for(int i=0; i<n; ++i){
		if(clue[toFind][i]){
			printf("%d ---> %d\n", toFind, i);

			if(isFinding[i])
				return false;
				
			if(!dfs(isFinding, clue, n, i))
				return false;
		}
	}

	isFinding[toFind] = false;
	
	return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    if(prerequisitesRowSize == 0 || !prerequisites)
        return true;

    bool result = true;
    
    bool isFinding[numCourses];
	bool **clue;
	clue = calloc(numCourses, sizeof(bool*));
	
	memset(isFinding, 0, numCourses*sizeof(bool));
	printf("initial isFinding over!\n");

	for(int i=0; i<numCourses; ++i)
		clue[i] = calloc(numCourses, sizeof(bool));
	printf("initial clue over!\n");
		
    
    for(int i=0; i<prerequisitesRowSize; ++i){
    	clue[prerequisites[i][0]][prerequisites[i][1]] = true;
    }
        

    printf("put info to clue over!\n");
            
    for(int i=0; i<numCourses; ++i)
        if(!dfs(isFinding, clue, numCourses, i)){
        	result = false;
        	break;
        }
     
    for(int i=0; i<numCourses; ++i)
		free(clue[i]);
    free(clue); 

    return result;
}
*/

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    if(prerequisitesRowSize == 0 || !prerequisites)
        return true;
        
    // -1：该点已经移除
    // >=0：入度
    int info[numCourses];
    memset(info, 0, numCourses*sizeof(int));
    
    for(int i=0, newOne=0; i<numCourses; newOne=0){

        for(int i=0; i<prerequisitesRowSize; ++i){
            if(info[prerequisites[i][0]] != -1)
                ++info[prerequisites[i][1]];
        }
        
        for(int i=0; i<numCourses; ++i){
            if(info[i] == 0){
                info[i] = -1;
                ++newOne;
            }
            if(info[i] > 0)
                info[i] = 0;
        }
        
        i += newOne;

        if(newOne == 0)
            return false;
    }
    
    return true;
}


int main(int argc, char const *argv[])
{
	int tCnt, rCnt;
	int **rTable;

	while(scanf("%d %d\n", &tCnt, &rCnt) != EOF){
		rTable = calloc(rCnt, sizeof(int*));

		for(int i=0, prior, base; i<rCnt; ++i){
			scanf("%d %d", &prior, &base);
			rTable[i] = calloc(2, sizeof(int));
			rTable[i][0] = prior;
			rTable[i][1] = base;
		}

		if(canFinish(tCnt, rTable, rCnt, 2))
			printf("YES\n");
		else 
			printf("NO\n");

		//free calloc
		for(int i=0; i<rCnt; ++i)
			free(rTable[i]);
		free(rTable);
	}

	return 0;
}

