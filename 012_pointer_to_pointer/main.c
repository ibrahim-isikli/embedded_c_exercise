#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rows = 2, cols = 3;
    // memory allocate for rows of pointers
    int **matrix = (int**)malloc(rows*sizeof(int*));

    // memory allocate for cols
    for(int i=0; i<rows; i++)
    {
        matrix[i] = (int*)malloc(cols*sizeof(int));
    }

    // fill the matrix
    int value = 1;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            matrix[i][j] = value++;
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }

    // free rows
    for(int i=0; i<rows; i++)
    {
        free(matrix[i]);
    }

    // free pointer array
    free(matrix);
    return 0;
}