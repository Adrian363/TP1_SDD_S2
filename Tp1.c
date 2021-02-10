#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basics.h"
#include "matrix.h"
#include "linked_list.h"

int main(int argc, char *argv[])

{
    /*Déclaration de toutes les variables nécessaires au programme*/
    if (argc > 2)
    {
        FILE *file = NULL;
        int **matrix = NULL;
        int m = 0;
        int n = 0;
        int K = 0;
        int save_i = 0;
        int save_j = 0;
        int default_alloc = 0;
        int little = 0;
        char temp[4];
        char *fileName = NULL;

        fileName = malloc(sizeof(argv[1]));

        strcpy(fileName, argv[1]);
        K = atoi(argv[2]);

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
                //Question 2

                // Vérification qu'on demande pas de trier plus de valeurs que celles présentent dans la matrice

                if (K < n * m)
                {
                    t_value *head = NULL;
                    t_value **preceding = &head;

                    little=matrix[0][0];

                    while ((K!=0) && (default_alloc == 0))
                    {

                        for (int i = 0; i < m; i++)
                        {
                            for (int j = 0; j < n; j++)
                            {
                                // 0 représente les valeurs déja traitées
                                if((matrix[i][j]<little) && (matrix[i][j]!=0)){
                                    save_i=i;
                                    save_j=j;
                                    little=matrix[save_i][save_j];
                                }
                            }
                        }
                        matrix[save_i][save_j]=0;
                        printf("\nValeur min trouvée :%d\n \n", little);

                        t_value *cell=create_cell(little, save_i, save_j);
                        if (cell==NULL){
                            printf("Pas ok \n");
                            default_alloc=1;
                        }

                        // Insertion dans la liste
                        add_cell(preceding, cell);

                        if(matrix[0][0]==0 &&((K-1)!=0)){
                            save_i=0;
                            save_j=1;

                            //  Attention si K=NB valeur dans la matrice alors segfault car on ne sort jamais de la boucle
                            while(matrix[save_i][save_j]==0){
                                printf("Valeur dans matrice est %d \n\n", matrix[save_i][save_j]);
                                if(save_j>n){
                                    save_i=save_i+1;
                                    save_j=0;
                                }
                                else{
                                    save_j=save_j+1;
                                }
                                

                            }

                        }
                        else if((K-1)!=0){ // Si la première valeur de la matrice n'est pas déjà traiter,alors elle est choisie comme plus petite valeur de départ
                            save_i=0;
                            save_j=0;
                        }
                        printf("Coordonnées val suivantes à traiter %d %d \n", save_i, save_j);
                        little=matrix[save_i][save_j];
                        printf("Little suivant est %d \n", little);
                        K=K-1;
                    }
                     display_linkChain(head);
                    freelist(head);
                }
                else
                {
                    printf("K est trop grand par rapport au nombre de valeurs disponibles dans la matrice");
                }
        
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
    else
    {
        printf("Veuillez renseignez le fichier de valeurs ou le nombre de valeur min \n");
    }
}
