#include <stdio.h>
#include "linked_list.h"

void add_cell(t_value **preceding, t_value *cell){
    cell->next=*preceding;
    *preceding=cell;
}

void del_cell(t_value **preceding){
    t_value *save=*preceding;
    *preceding=preceding; 
    free(save);
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
