#include <stdlib.h>
#include <stdio.h>


#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

typedef char bool;

#ifdef COMPLEX
int maximalSquare(char matrix[][5], int matrixRowSize, int matrixColSize) {
    int edgeL = 0;
    bool ***record = calloc(matrixRowSize, sizeof(bool **));
    for(int i=0; i<matrixRowSize; ++i){
        record[i] = calloc(matrixColSize, sizeof(bool *));
        for(int j=0; j<matrixColSize; ++j){
            record[i][j] = calloc(min(matrixRowSize-i, matrixColSize-j), sizeof(bool));
            if(record[i][j][0] = (matrix[i][j] == '1'))
                edgeL = 1;
        }
    }
    
    if(edgeL == 0)
        return 0;
    
    for(int i=matrixRowSize-2; i>=0; --i)
        for(int j=matrixColSize-2; j>=0; --j)
            for(int r=1; r<min(matrixRowSize-i, matrixColSize-j); ++r){
                int nr = r/2;
                int diff = r-nr;
                record[i][j][r] = record[i][j][nr]&&record[i+diff][j][nr]
                                &&record[i][j+diff][nr]&&record[i+diff][j+diff][nr];
                if(r>=edgeL && record[i][j][r])
                    edgeL = r+1;
            }
            
    return edgeL*edgeL;
}
#endif



#ifndef COMPLEX
int maximalSquare(char matrix[][5], int matrixRowSize, int matrixColSize) {
    int record[matrixRowSize][matrixColSize];
    int maxEdge = 0;
    
    for(int i=0; i<matrixColSize; ++i)
        if(record[matrixRowSize-1][i] = matrix[matrixRowSize-1][i] - '0')
            maxEdge = 1;
    
    for(int i=0; i<matrixRowSize; ++i)
        if(record[i][matrixColSize-1] = matrix[i][matrixColSize-1] - '0')
            maxEdge = 1;
        
    
    
    for(int i=matrixRowSize-2; i>=0; --i)
        for(int j=matrixColSize-2; j>=0; --j)
            if(matrix[i][j] == '1'){
                record[i][j] = min(min(record[i][j+1], record[i+1][j]), record[i+1][j+1]) + 1;
                maxEdge = max(maxEdge, record[i][j]);
            }
            else
                record[i][j] = 0;
                
    return maxEdge*maxEdge;
            
}
#endif


int main(int argc, char const *argv[])
{
    char matrix[4][5] = {{'1', '0', '1', '1', '1'},
                         {'1', '0', '1', '1', '1'},
                         {'1', '1', '1', '1', '1'},
                         {'1', '0', '0', '1', '0'}};

    //char matrix[1][5] = {{'1', '0', '1', '1', '1'}};
    printf("%d\n", maximalSquare(matrix, 3, 5));

    printf("%p\n", &"7777");
    return 0;
}