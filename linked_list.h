#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>

typedef struct value{
    int cost;
    int factory;
    int week;
    struct value *next;
}t_value;

void add_cell(t_value **preceding, t_value *cell);

t_value **search_prec(t_value **ad_head, int value);

void del_cell(t_value **preceding);

void display_linkChain(t_value *head);

void freelist(t_value *head);

t_value *create_cell(int value, int fact_number, int week_number);

#endif