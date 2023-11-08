#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"


void dontes(eredmenyek *eredmeny, int jatekos, int jatekos2, int oszto, int oszto2 ){
    if (jatekos > 10 && jatekos < 14) 
        jatekos = 10;
    else if(jatekos == 14)
        jatekos = 11;
    if (jatekos2 > 10 && jatekos2 < 14) 
        jatekos2 = 10;
    else if(jatekos2 == 14)
        jatekos2 = 11;
    if (oszto > 10 && oszto < 14) 
        oszto = 10;
    else if(oszto == 14)
        oszto = 11;
    if (oszto2 > 10 && oszto2 < 14) 
        oszto2 = 10;
    else if(oszto2 == 14)
        oszto2 = 11;
    if(jatekos + jatekos2 > oszto + oszto2)
        ++eredmeny->nyert;
    else if(jatekos + jatekos2 < oszto + oszto2)
        ++eredmeny->vesztett;
    else
        ++eredmeny->dontetlen;      
}

void kiiras(void){
    printf("\nHa új kört szeretnél kezdeni, nyomd meg a [K] betűt és nyomj egy entert!\nHa viszont nem és el szeretnéd menteni az eredményt, nyomd meg a [M] betűt és nyomj egy entert!\n");
}

void pakli_felszabadit(pakli* eleje)
{
    pakli* mozgo = eleje;
    while(mozgo != NULL)
    {
        pakli* kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

pakli *letrehoz(int ertek, char szin[10]){
    pakli *uj = (pakli*)malloc(sizeof(pakli));
    uj->ertek = ertek;
    strcpy(uj->szin, szin);
    uj->kov = NULL;
    return uj;
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
/*
void osszegjatekos(int jatekos, int jatekos2){
    if (jatekos > 10 && jatekos < 14) 
        jatekos = 10;
    else if(jatekos == 14)
        jatekos = 11;
    if (jatekos2 > 10 && jatekos2 < 14) 
        jatekos2 = 10;
    else if(jatekos2 == 14)
        jatekos2 = 11;
    printf("Összeg: %d\n", jatekos + jatekos2);
}
*/