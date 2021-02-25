#include <stdio.h>
#include "linked_list.h"

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                     linked_list.c                     */
             /*            Traitement d'une liste chainée             */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/
 

void add_cell(t_value **preceding, t_value *cell){
    cell->next=*preceding;
    *preceding=cell;
}
 
t_value **search_prec(t_value **ad_head, int value){
    t_value *actual = *ad_head;
    t_value **preceding = ad_head;


    while((actual!=NULL) && (actual->cost>value)){ /*Tant que la liste est pas vide et que la valeur de du bloc est < à celle cherchée:*/
        preceding=&(actual->next); /* on avance dans les blocs*/
        actual=actual->next;    

    }

    return preceding;

}

void del_cell(t_value **preceding){
    t_value *save=*preceding; /* sauvegarde de l'élement à supprimer*/
    *preceding=save->next; /* modification des liens entre les blocs*/
    free(save); /* suppression du bloc sauvegardé*/
}


void freelist(t_value *head){
    t_value **preceding=&head; /* le précédent prend l'adresse de la tête de liste */
    while(head!=NULL){
        del_cell(preceding); /* appel de la fonction pour supprimer un bloc et libérer la mémoire*/
    }
    
}
void display_linkChain(t_value *head){
    t_value *actual=head; 
    while(actual){
        printf("Cost:%d\n ", actual->cost); /*affichage du coût de prod de chaque bloc*/
        printf("Factory :%d\n ", actual->factory);/* affichage de l'usine de production*/
        printf("Week:%d\n --------- \n ", actual->week);/* affichage de la semaine de production*/
        
        actual=actual->next; /*on met se place sur le bloc suivant*/
    }
}

t_value *create_cell(int value, int fact_number, int week_number){
    t_value *cell=NULL;
    cell=(t_value*) malloc(sizeof(t_value));
    if(cell!=NULL){
        /*Insertion des valeurs dans le bloc*/
        cell->cost=value;
        cell->factory=fact_number;
        cell->week=week_number;
    }

    return cell;

}

void del_factory(t_value **ad_head, int fact){
    t_value **preceding=ad_head;

    while(*preceding!=NULL){
        preceding=search_prec_bis (preceding, fact);
        printf("Suppression \n");
        del_cell(preceding);
    }

}

t_value ** search_prec_bis (t_value ** preceding, int i){

t_value  *cour, **prec;

 prec = preceding;
 cour = *preceding;

   while ((cour !=NULL) && (cour->factory!=i)){                   
       prec = &(cour->next) ;
       cour = cour->next ;
     }
   return (prec);
}

void writefile(char *filename, t_value *head){
    FILE *file = NULL;
    file=fopen(filename, "w");
    t_value *actual=head;

    if(file!=NULL){
        fprintf(file, "%5s %5s %5s \n", "Cost", "Factory", "Week");
        while(actual!=NULL){
            fprintf(file,"%5d %5d %5d \n", actual->cost, actual->factory, actual->week);
            actual=actual->next;

        }
        fclose(file);
    }
    else{
        printf("Allocation error \n");
    }
}



