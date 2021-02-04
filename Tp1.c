#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"


int main(){
    // Déclaration de toutes les variables nécessaires au programme

    FILE *file=NULL; 
    int** matrix=NULL;
    int m=0;
    int n=0;
    char temp[4];


    // Corps du programme
    openfile(&file, "data.txt");
    if(file!=NULL){
        fgets(temp,4,file);

        m=temp[0]-48;
        n=temp[2]-48;
        matrix=createMatrix(m, n);
        if(matrix){
                
            insertVal(matrix,file, m, n);
            displayMatrix(matrix,m, n);
            freeMatrix(matrix, m);
        }
        
        fclose(file);


    }
    else{
        printf("Pas ok");
    }
    

    
}