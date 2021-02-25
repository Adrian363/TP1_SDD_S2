#ifndef linked_list_h
#define linked_list_h

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                     linked_list.h                     */
             /*            Traitement d'une liste chainée             */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

#include <stdio.h>
#include <stdlib.h>
 
/***************************************/
/* Définition de la structure qui sera */
/* pour les blocs de la liste chainée  */
/***************************************/

typedef struct value{
    int cost;
    int factory;
    int week;
    struct value *next;
}t_value;

/***************************************/
/* Fonction d'insertion d'un bloc dans */
/* une liste chainée, passage en       */
/* du précédent et le bloc à insérer   */
/***************************************/

void add_cell(t_value **preceding, t_value *cell);

/***************************************/
/* Fonction de recherche du précedent  */
/* d'une valeur, passage en paramètre  */
/* de l'adresse de la tête et de la    */
/* valeur à trouver                    */
/***************************************/

t_value **search_prec(t_value **ad_head, int value);

/***************************************/
/* Fonction de suppression d'une       */
/* cellule dans une liste à partir du  */
/* précédent                           */
/***************************************/

void del_cell(t_value **preceding);

/***************************************/
/* Fonction d'affichage d'une liste    */
/* chainée à partir de sa tête         */
/***************************************/

void display_linkChain(t_value *head);

/***************************************/
/* Fonction libèrant la liste chainée  */
/***************************************/

void freelist(t_value *head);

/***************************************/
/* Fonction qui crée un bloc à insérer */
/* dans la liste chainée et ajouter    */
/* les valeurs dans les cases du bloc  */
/***************************************/

t_value *create_cell(int value, int fact_number, int week_number);


t_value ** search_prec_bis (t_value ** preceding, int i);


void del_factory(t_value **ad_head, int fact);

void writefile(char *filename, t_value *head);

#endif
