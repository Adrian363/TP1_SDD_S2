#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basics.h"
#include "matrix.h"

int main(int argc, char *argv[])

{
    /*Déclaration de toutes les variables nécessaires au programme*/
    if (argc > 1)
    {
        FILE *file = NULL;
        int **matrix = NULL;
        int m = 0;
        int n = 0;
        char temp[4];
        char* fileName=NULL;


        fileName=malloc(sizeof(argv[1]));
      
        strcpy(fileName, argv[1] );

        // Corps du programme
        openfile(&file, fileName);
        if (file != NULL)
        {
            fgets(temp, 4, file);

            m = temp[0] - 48;
            n = temp[2] - 48;
            matrix = createMatrix(m, n);
            if (matrix)
            {

                insertVal(matrix, file, m, n);
                displayMatrix(matrix, m, n);
                freeMatrix(matrix, m);
                
            }

            fclose(file);
            free(fileName);
        }
        else
        {
            printf("Le fichier renseigné est introuvable");

        }
    }
    else{
        printf("Veuillez renseignez le fichier de valeur \n");
    }
}
