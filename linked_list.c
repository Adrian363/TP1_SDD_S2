#include <stdio.h>
#include "linked_list.h"

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                     linked_list.c                     */
             /*            Traitement d'une liste chainée             */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/
 

/********************************************************/
/* Lexique add_cell:                                    */
/* Double pointeur t_value preceding = pointeur sur     */
/*  zone mémoire de la cellule précédent de celle à     */
/*  modifier.                                           */
/*  Pointeur t_value cell: bloc à insérer dans la liste */
/********************************************************/

void add_cell(t_value **preceding, t_value *cell){
    cell->next=*preceding;
    *preceding=cell;
}

/********************************************************/
/* Lexique search_prec:                                 */
/* Double pointeur t_value ad_head = adresse de la      */
/* tête de liste                                        */
/* Entier value: Valeur à rechercher dans la liste      */
/********************************************************/

t_value **search_prec(t_value **ad_head, int value){
    t_value *actual = *ad_head;
    t_value **preceding = ad_head;


    while((actual!=NULL) && (actual->cost>value)){ /*Tant que la liste est pas vide et que la valeur de du bloc est < à celle cherchée:*/
        preceding=&(actual->next); /* on avance dans les blocs*/
        actual=actual->next;    

    }

    return preceding;

}

/********************************************************/
/* Lexique del_cell:                                    */
/* Double pointeur t_value preceding = pointeur sur     */
/*  zone mémoire de la cellule précédente de celle à    */
/*  supprimer.                                          */
/* Pointeur t_value save= élément à supprimer           */
/********************************************************/

void del_cell(t_value **preceding){
    t_value *save=*preceding; /* sauvegarde de l'élement à supprimer*/
    *preceding=save->next; /* modification des liens entre les blocs*/
    free(save); /* suppression du bloc sauvegardé*/
}


/********************************************************/
/* Lexique freelist:                                    */
/* Pointeur t_value head = pointeur sur la tete de la   */
/*   liste                                              */
/* Double pointeur t_value preceding = pointeur sur     */
/*  zone mémoire de la cellule précédente de celle à    */
/*  supprimer.                                          */
/********************************************************/


void freelist(t_value *head){
    t_value **preceding=&head; /* le précédent prend l'adresse de la tête de liste */
    while(head!=NULL){
        del_cell(preceding); /* appel de la fonction pour supprimer un bloc et libérer la mémoire*/
    }
    
}

/********************************************************/
/* Lexique display_linkChain:                           */
/* Pointeur t_value head = pointeur sur la tete de la   */
/*   liste                                              */
/* Pointeur t_value actual= pointeur sur l'élement      */
/*  courant dans la liste                               */
/********************************************************/

void display_linkChain(t_value *head){
    t_value *actual=head; 
    while(actual){
        printf("Cost:%d\n ", actual->cost); /*affichage du coût de prod de chaque bloc*/
        printf("Factory :%d\n ", actual->factory);/* affichage de l'usine de production*/
        printf("Week:%d\n --------- \n ", actual->week);/* affichage de la semaine de production*/
        
        actual=actual->next; /*on met se place sur le bloc suivant*/
    }
}

/********************************************************/
/* Lexique create_cell:                                 */
/* Pointeur t_value cell = bloc qui est crée et qui sera*/
/*  intégré dans la liste                               */
/* Entier value, fact_number, week_number:              */
/*  Valeurs à insérer dans le bloc crée précédement     */
/********************************************************/

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
/********************************************************/
/* Lexique del_factory:                                 */
/* Double pointeur t_value ad_head = adresse de la      */
/* tête de liste                                        */
/* Entier fact: Numero de l'usine à supprimer dans la   */
/*  liste                                               */
/* Double pointeur t_value preceding = pointeur sur     */
/*  zone mémoire de la cellule précédente de celle à    */
/*  supprimer.                                          */
/********************************************************/

void del_factory(t_value **ad_head, int fact){
    t_value **preceding=ad_head;

    while(*preceding!=NULL){ 
        preceding=search_prec_bis (preceding, fact);
        if(*preceding!=NULL){ /*Verification sinon seg fault quand on veut supprimer un element au debut de chaine*/
            del_cell(preceding);
        }
        
    }

}

/********************************************************/
/* Lexique search_prec_bis:                             */
/* Double pointeur t_value preceding = adresse de la    */
/*  tête de liste                                       */
/* Double pointeur t_value prec = pointeur sur          */
/*  zone mémoire de la cellule précédente de celle à    */
/*  supprimer.                                          */
/* Pointeur t_value cour= pointeur sur l'élément        */
/*  courant dans la liste.                              */
/* Entier i: Valeur à rechercher dans la liste          */
/********************************************************/

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

/********************************************************/
/* Lexique writefile:                                   */
/* Fichier file: Fichier d'écriture de la liste chainée */
/* Pointeur t_value actual= pointeur sur l'élément      */
/*  courant dans la liste.                              */
/* Pointeur t_value head = pointeur sur la tete de la   */
/*  liste                                               */
/********************************************************/

void writefile(char *filename, t_value *head){
    FILE *file = NULL;
    t_value *actual=NULL; 
    file=fopen(filename, "w"); /* Ouverture du fichier en mode ecriture */
   

    if(file!=NULL){
        actual=head;
        fprintf(file, "%5s %5s %5s \n", "Cost", "Factory", "Week"); /*formatage de la premiere ligne du fichier */
        while(actual!=NULL){ /* tant qu'on a pas fini la liste, on ecrire le contenu du bloc dans le fichier */
            fprintf(file,"%5d %5d %5d \n", actual->cost, actual->factory, actual->week);
            actual=actual->next;

        }
        fclose(file);
    }
    else{
        printf("Allocation error \n");
    }
}



