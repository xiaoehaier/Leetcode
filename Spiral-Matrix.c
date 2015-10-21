#include <stdio.h>
#include <stdlib.h>

#define ROW 50
#define COL 20

int *spiralOrder(int **matrix, int numRows, int numColumns) {
    if(numRows == 1) 
        return matrix[0];
        
    int *result = calloc(numRows*numColumns, sizeof(int));
    int *final = result;
    int para[5] = {0, numRows-1, 0, numColumns-1, 0};
    
    while(para[1]>=para[0] && para[3]>=para[2]){
        switch(para[4]){
        case 0:
            for(int i=para[2]; i<=para[3]; ++i)
                *(result++) = matrix[para[0]][i];
            ++para[0];
            break;
        case 1:
            for(int i=para[0]; i<=para[1]; ++i)
                *(result++) = matrix[i][para[3]];
            --para[3];
            break;
        case 2:
            for(int i=para[3]; i>=para[2]; --i)
                *(result++) = matrix[para[1]][i];
            --para[1];
            break;
        case 3:
            for(int i=para[1]; i>=para[0]; --i)
                *(result++) = matrix[i][para[2]];
            ++para[2];
            break;
        }
    
        para[4] = (para[4]+1)%4;
    }
    
    return final;
}

int main(int argc, char const *argv[])
{
    int **matrix;
    matrix = calloc(ROW, sizeof(int *));

    for(int i=0; i<ROW; ++i){
        matrix[i] = calloc(COL, sizeof(int));
        for(int j=0; j<COL; ++j)
            matrix[i][j] = j;
    }

    int *result = spiralOrder(matrix, ROW, COL);

    for(int i=0; i<ROW*COL; ++i)
        printf("%d ", result[i]);

    return 0;
}