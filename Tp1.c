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
        int i, j=0;
        int delete_factory=0;
        char temp[4];
        char *fileName = NULL;
        t_value *cell = NULL;

        fileName = malloc((strlen(argv[1])+1)*sizeof(char));
        K=atoi(argv[2]);
        strcpy(fileName, argv[1]);
        file=fopen(fileName, "r");

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
                /*Question 2*/

                /* Vérification qu'on demande pas de trier plus de valeurs que celles présentent dans la matrice*/

                if (K>0 && K <= n * m )
                {
                    t_value *head = NULL;

                    t_value **preceding=&head;

                    for (i=0; i<m; i++){
                        
                             for(j=0;j<n; j++){
                                 t_value *first_cell=head;
                                 if(i*n+j<K){ /* Ajout des K premiers éléments dans de la matrice dans la liste*/
                                     /*recherche prec*/
                                    preceding=search_prec(&head, matrix[i][j]);

                                     /*Creation elem*/
                                    cell=NULL;
                                    cell=create_cell(matrix[i][j], i, j);

                                     /* Insertion elem */
                                     add_cell(preceding, cell);
            
                                 }

                                 else 
                                                     
                                 {
                                     if(first_cell->cost>matrix[i][j]){ /* Si la valeur en tete de la liste est sup à celle de la matrice*/
                                        preceding=search_prec(&head, matrix[i][j]);
                                        cell=NULL;
                                        cell=create_cell(matrix[i][j], i, j);
                                        add_cell(preceding, cell);
                                        del_cell(&head);
                                     }
                              
                                 }
                             }

                        }
                    
                    display_linkChain(head);
                    printf("Which factory do you want to delete \n\n");
                    scanf("%d", &delete_factory);
                    printf(" \n\n");
                    del_factory(&head, delete_factory);
                    printf("Modify linked-list \n \n");
                    display_linkChain(head);
                    writefile("output.txt",head);
                    freelist(head);
                }
                else
                {
                    printf("K est trop grand par rapport au nombre de valeurs disponibles dans la matrice, soit inférieur ou égale à 0 \n");
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

    return 1;
}
