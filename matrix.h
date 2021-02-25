#ifndef matrix_h
#define matrix_h

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                       matrix.h                        */
             /*                 Traitement d'une matrice              */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

 
#include <stdio.h>
#include <stdlib.h>
 
/***************************************/
/* Fonction de création de la matrice, */
/* retourne un tableau 2 dimensions    */
/***************************************/

int **createMatrix(int lines, int columns);

/***************************************/
/* Fonction d'insertion des valeurs    */
/* d'un fichier dans la matrice, en    */
/* fonction du nb de ligne et colonnes */
/***************************************/

void insertVal(int** matrix, FILE* file, int lines, int columns);

/***************************************/
/* Fonction d'affichage d'une matrice  */
/* 2 dimensions en fonction du nombre  */
/* de lignes et de colonnes            */
/***************************************/

void displayMatrix(int** matrix,int lines, int columns);

/***************************************/
/* Fonction libérant l'espace mémoire  */
/* allouer à la matrice                */
/***************************************/

void freeMatrix(int** matrix, int lines);

#endif
