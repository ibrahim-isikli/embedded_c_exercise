#ifndef MATRIX_H
#define MATRIX_H

int **allocateMatrix(int rows, int cols);
void readMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void freeMatrix(int **matrix, int rows);
int **addMatrix(int **matrix_1, int **matrix_2, int rows, int cols);

#endif