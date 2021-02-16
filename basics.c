#include <stdio.h>
#include <stdlib.h>

             /*********************************************************/
             /*                   Adrian Cottais 2021                 */
             /*-------------------------------------------------------*/
             /*                       basics.c                        */
             /*              Quelques fonctions classiques            */
             /*                   PROGRAMME PRINCIPAL                 */
             /*********************************************************/

void openfile(FILE** file, char* fileName){
    *file=fopen(fileName, "r");
}