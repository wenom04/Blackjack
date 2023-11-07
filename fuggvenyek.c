#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"


void dontes(eredmenyek *eredmeny, int jatekos, int oszto){
    if(jatekos>oszto)
        ++eredmeny->nyert;
    else if(jatekos<oszto)
        ++eredmeny->vesztett;
    else
        ++eredmeny->dontetlen;      
}

void kiiras(void){
    printf("Ha új kört szeretnél kezdeni, nyomd meg a [K] betűt és nyomj egy entert!\nHa viszont nem és el szeretnéd menteni az eredményt, nyomd meg a [M] betűt és nyomj egy entert!\n");
}