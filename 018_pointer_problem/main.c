#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "matrix.h"

int main(void)
{
    int rows,cols;

    printf("matrix rows:");
    scanf("%d",&rows);
    printf("matrix cols:");
    scanf("%d",&cols);

    // create matrix
    int **mat1 = allocateMatrix(rows,cols);
    int **mat2 = allocateMatrix(rows,cols);

    // get matrix information from user
    printf("first matrix:\n");
    readMatrix(mat1,rows,cols);
    printf("second matrix:\n");
    readMatrix(mat2,rows,cols);

    // sum two matrix
    int **sumMatrix = addMatrix(mat1,mat2,rows,cols);

    printf("sum of two matrices\n");
    printMatrix(sumMatrix,rows,cols);

    // free memory
    freeMatrix(mat1,rows);
    freeMatrix(mat2,rows);
    freeMatrix(sumMatrix,rows);

    return 0;
}
