#include <stdio.h>
#include "fuggvenyek.h"
#include "pakli.h"
#include "debugmalloc.h"

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

void kartyatorlese(pakli *eleje, int ertek, char *szin){
    pakli *torlendo = eleje;
    pakli *elozo = NULL;

    while (torlendo != NULL){
        if (torlendo->ertek == ertek && strcmp(torlendo->szin, szin) == 0){
            if (elozo == NULL){
                //első elem
                eleje = torlendo->kov;
            }
            else{
                elozo->kov = torlendo->kov;
            }
        }
        free(torlendo);
        return;
    }
}

/*
pakli* paklitletrehoz(pakli *eleje){
    char szinek[4][10]= {"Pikk", "Kőr", "Káró", "Treff"};
    int ertekek[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};

    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            pakli *uj = letrehoz(ertekek[j], szinek[i]);
            uj->kov = eleje;
            eleje = uj;
        }
    }
    return eleje;
}
*/