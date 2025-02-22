#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "matrix.h"


// memory allocation for matrix
int **allocateMatrix(int rows, int cols)
{
    int **matrix = (int**)malloc(rows*sizeof(int*));
    for(uint8_t i=0; i<rows; i++)
    {
        matrix[i] = (int*)malloc(cols*sizeof(int));
    }
    return matrix;
}


void readMatrix(int **matrix, int rows, int cols)
{
    for(uint8_t i=0; i<rows; i++)
    {
        for(uint8_t j=0; j<cols; j++)
        {
            printf("matrix[%d][%d]\n",i,j);
            scanf("%d",*(matrix+i) + j); //scanf("%d",matris[i][j]);
        }
    }
}


void printMatrix(int **matrix, int rows, int cols)
{
    printf("------------MATRIX------------\n");

    for(uint8_t i=0; i<rows; i++)
    {
        for(uint8_t j=0; j<cols; j++)
        {
            printf("%d\t",*(*(matrix+i)+j));
        }
        printf("\n");
    }
}


void freeMatrix(int **matrix, int rows)
{
    for(uint8_t i=0; i<rows; i++)
    {
        free(*(matrix+i));
    }
    free(matrix);

}


int **addMatrix(int **matrix_1, int **matrix_2, int rows, int cols)
{
    int **result = allocateMatrix(rows,cols);
    for(uint8_t i=0; i<rows; i++)
    {
        for(uint8_t j=0; j<cols; j++)
        {
            *(*(result+i)+j) = *(*(matrix_1+i)+j) + *(*(matrix_2+i)+j);
        }
    }

    return result;
}