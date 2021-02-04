#include <stdio.h>

/* Déclaration des fonctions du TP1 */

void openfile(FILE** file, char* fileName){
    *file=fopen(fileName, "r");
}

int **createMatrix(int lines, int columns){
    int i=0;
    int **matrix=NULL;
    matrix=(int**)malloc(lines*sizeof(int*));

    if(matrix){
        for(i=0; i<lines; i++){
            matrix[i]=NULL;
            matrix[i]=(int*)malloc(columns*sizeof(int));
            
        }
        
    }
    return matrix;
}

void insertVal(int** matrix, FILE* file, int lines, int columns){
    int i=0;
    int j=0;

    for(i=0; i<lines; i++){
        for(j=0; j<columns; j++){
            fscanf(file,"%d", &matrix[i][j]);
        }
    
    }
}

void displayMatrix(int** matrix,int lines, int columns){
    int i=0;
    int j=0;

    for(i=0; i<lines; i++){
        for(j=0; j<columns; j++){
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    
    }
}

void freeMatrix(int** matrix, int lines){
    int i=0;

    for(i=0; i<lines; i++){
            free(matrix[i]);
        }
    free(matrix);
}