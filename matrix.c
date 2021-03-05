#include "matrix.h"


             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                        matrix.c                       */
             /*                  Traitement d'une matrice             */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/


/********************************************************/
/* Lexique createMatrix:                                */
/* Entier i: Utiliser pour itérations de la boucle pour */
/* Entier verifAlloc: Code retour après une allocation  */
/* Double pointeur entier matrix= Tableau 2 dimensions  */
/* avec les coûts                                       */
/* Entiers lines et columns: Régissent la taille de la  */
/* matrice                                              */
/********************************************************/

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

/********************************************************/
/* Lexique insertVal:                                   */
/* Entiers i,j: Utiliser pour itérations des boucles    */
/*   pour                                               */
/* Double pointeur entier matrix= Tableau 2 dimensions  */
/* avec les coûts                                       */
/* Fichier file: Fichier avec les coûts à récupérer     */
/* Entiers lines et columns: Régissent la taille de la  */
/* matrice                                              */
/********************************************************/

void insertVal(int** matrix, FILE* file, int lines, int columns){
    int i=0;
    int j=0;

    for(i=0; i<lines; i++){ 
        for(j=0; j<columns; j++){
            fscanf(file,"%d", &matrix[i][j]); /* Pour chaque case de chaque ligne, on lit une valeur dans le fichier et on le stocke dans la matrice*/
        }
     
    }
}

/********************************************************/
/* Lexique diplayMatrix:                                */
/* Entiers i,j: Utiliser pour itérations des boucles    */
/*   pour                                               */
/* Double pointeur entier matrix= Tableau 2 dimensions  */
/* avec les coûts                                       */
/* Entiers lines et columns: Régissent la taille de la  */
/* matrice                                              */
/********************************************************/


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

/********************************************************/
/* Lexique freeMatrix:                                  */
/* Entier i: Utiliser pour itérations de la  boucles    */
/*   pour                                               */
/* Double pointeur entier matrix= Tableau 2 dimensions  */
/* avec les coûts                                       */
/* Entier lines: Nombre de lignes dans la matrice       */
/********************************************************/

void freeMatrix(int** matrix, int lines){
    int i=0;

    for(i=0; i<lines; i++){
            free(matrix[i]); /*libération de la ligne de la matrice*/
        }
    free(matrix); /* libération du reste de la matrice*/
}
