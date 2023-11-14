#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"


void dontes(eredmenyek *eredmeny, int osszegjatekos, int osszegoszto){
    if(osszegjatekos > osszegoszto){
        ++eredmeny->nyert;
    }
    else if(osszegjatekos < osszegoszto){
        ++eredmeny->vesztett;
    }
    else{
        ++eredmeny->dontetlen;
    }   
}

void kiiras(void){
    printf("\nHa új kört szeretnél kezdeni, nyomd meg a [K] betűt és nyomj egy entert!\nHa viszont nem és el szeretnéd menteni az eredményt, nyomd meg a [M] betűt és nyomj egy entert!\n");
}

void erteke(int ertek, char *tomb){
    if(ertek == 11)
        strcpy(tomb, "Jumbo");
    else if(ertek == 12)
        strcpy(tomb, "Dáma");
    else if(ertek == 13)
        strcpy(tomb, "Király");
    else if(ertek == 14)
        strcpy(tomb, "Ász");
}

int tisztertek(int tiszt){
    if (tiszt > 10 && tiszt < 14) 
        return 10;
    else if(tiszt == 14)
        return 11;
    else
        return tiszt;
}

void nemmegfelelo(void){
    printf("Nem megfelelő karaktert adtál meg!\n");
}

void nullazas(int* nyert, int *dontetlen, int *vesztett, int *egyenleg){
    *nyert = 0;
    *dontetlen = 0;
    *vesztett = 0;
    *egyenleg = 500;
}
