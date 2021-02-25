#include "matrix.h"


             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                        matrix.c                       */
             /*                  Traitement d'une matrice             */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

 
int **createMatrix(int lines, int columns){
    int i=0;
    int verifAlloc=0;
    int **matrix=NULL;
    matrix=(int**)malloc(lines*sizeof(int*));

    if(matrix){ /* si la matrice est bien allouée on continue*/
        for(i=0; i<lines; i++){
            matrix[i]=NULL;
            matrix[i]=(int*)malloc(columns*sizeof(int)); /*Allocation de n colones sur chaque ligne*/

            if(matrix[i]==NULL){ /* vérification de la création de la colonne*/
                verifAlloc=1;
            }
            
        }

        if(verifAlloc==1){ /* si problème allocation, alors on libère la matrice*/
            free(matrix);
            matrix=NULL;
        }
        
    }
    return matrix;
}

void insertVal(int** matrix, FILE* file, int lines, int columns){
    int i=0;
    int j=0;

    for(i=0; i<lines; i++){ 
        for(j=0; j<columns; j++){
            fscanf(file,"%d", &matrix[i][j]); /* Pour chaque case de chaque ligne, on lit une valeur dans le fichier et on le stocke dans la matrice*/
        }
     
    }
}

void displayMatrix(int** matrix,int lines, int columns){
    int i=0;
    int j=0;

    for(i=0; i<lines; i++){
        for(j=0; j<columns; j++){
           printf("%d ",matrix[i][j]); /* affichage de case de la matrice*/
        }
        printf("\n");
    
    }
    printf("\n");
}

void freeMatrix(int** matrix, int lines){
    int i=0;

    for(i=0; i<lines; i++){
            free(matrix[i]); /*libération de la ligne de la matrice*/
        }
    free(matrix); /* libération du reste de la matrice*/
}
