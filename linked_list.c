#include <stdio.h>
#include "linked_list.h"

void add_cell(t_value **preceding, t_value cell){
    cell.next=*preceding;
    *preceding=&cell;
}

void del_cell(t_value **preceding){
    t_value *save=*preceding;
    *preceding=preceding; 
    free(save);
}