#include <stdio.h>
#include <stdlib.h>

void openfile(FILE** file, char* fileName){
    *file=fopen(fileName, "r");
}