#include <stdio.h>
#include "linked_list.h"

void add_cell(t_value **preceding, t_value *cell){
    cell->next=*preceding;
    *preceding=cell;
}

t_value **search_prec(t_value **ad_head, int value){
    t_value *actual = *ad_head;
    t_value **preceding = ad_head;


    while((actual!=NULL) && (actual->cost>value)){
        preceding=&(actual->next);
        actual=actual->next;    

    }

    return preceding;

}

void del_cell(t_value **preceding){
    t_value *save=*preceding;
    *preceding=save->next;
    free(save);
}
t_value *head = NULL;
                    t_value **preceding = &head;

void freelist(t_value *head){
    t_value **preceding=&head;
    while(head!=NULL){
        del_cell(preceding);
    }
    
}
void display_linkChain(t_value *head){
    t_value *actual=head;
    while(actual){
        printf("%d\n ", actual->cost);
        actual=actual->next;
    }
}

t_value *create_cell(int value, int fact_number, int week_number){
    t_value *cell=NULL;
    cell=(t_value*) malloc(sizeof(t_value));
    if(cell!=NULL){
        cell->cost=value;
        cell->factory=fact_number;
        cell->week=week_number;
    }

    return cell;

}

/* On veut les K couts les plus faibles 
On prend les K premieres, on les stocke dans la liste chainee par ordre decroissant, 
puis on prend chaque autres valeurs pour les conparer avec celles deja presentes dans la liste.
Si pas sup a la valeur de tete, on recherche son prec, on add la cell et on del la cellule de tete*/


