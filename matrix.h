#ifndef matrix_h
#define matrix_h

#include <stdio.h>
#include <stdlib.h>



int **createMatrix(int lines, int columns);


void insertVal(int** matrix, FILE* file, int lines, int columns);
void displayMatrix(int** matrix,int lines, int columns);

void freeMatrix(int** matrix, int lines);

#endif
