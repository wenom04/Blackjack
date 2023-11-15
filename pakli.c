#include <stdio.h>
#include <time.h>
#include "fuggvenyek.h"
#include "pakli.h"
#include "debugmalloc.h"

void pakli_felszabadit(kartya *eleje)
{
    kartya *mozgo = eleje;
    while (mozgo != NULL)
    {
        kartya *kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

kartya *letrehoz(int ertek, char szin[10])
{
    kartya *uj = (kartya *)malloc(sizeof(kartya));
    uj->ertek = ertek;
    strcpy(uj->szin, szin);
    uj->kov = NULL;
    return uj;
}

kartya *kartyatorlese(kartya *eleje, kartya *keresett)
{
    kartya *torlendo = eleje;
    kartya *elozo = NULL;

    if (keresett == NULL)
        return eleje;
    else if (eleje == NULL)
        return NULL;

    while (torlendo != NULL)
    {
        if (torlendo == keresett)
        {
            if (elozo == NULL)
            {
                // első elem
                kartya *ideiglenes = torlendo->kov;
                free(torlendo);
                return ideiglenes;
            }
            else
            {
                elozo->kov = torlendo->kov;
                free(torlendo);
                return eleje;
            }
        }
    }
    return eleje;
}

kartya *paklitletrehoz()
{
    kartya *pakli = NULL;
    char szinek[4][10] = {"Pikk", "Kőr", "Káró", "Treff"};
    int ertekek[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    kartya *legutobbi = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            kartya *uj = letrehoz(ertekek[j], szinek[i]);
            if (legutobbi == NULL)
            {
                // Mivel a pakli üfres, ezért az első pakli lesz az eleje
                legutobbi = uj;
                pakli = uj;
            }
            else
            {
                // A legutóbbi kártya mutat az új kártyára, ezután az újonnan létrehozott kártya lesz a legutóbbi
                legutobbi->kov = uj;
                legutobbi = uj;
            }
        }
    }
    return pakli;
}

kartya *kartyaosztas(kartya *eleje)
{
    srand(time(NULL));
    int randSzam = rand() % 52;

    kartya *mozgo = eleje;
    for (int i = 0; i < randSzam; i++)
        mozgo = mozgo->kov;

    return mozgo;
}

void osztokartyakiirasa(kartya *mit, char *ertekbetuvel, int hanyadik)
{
    if (mit->ertek < 11)
        printf("Az osztó %d. lapja: %s %d\n", hanyadik, mit->szin, mit->ertek);
    else
        printf("Az osztó %d. lapja: %s %s\n", hanyadik, mit->szin, ertekbetuvel);
}

void jatekoskartyakiirasa(kartya *mit, char *ertekbetuvel, int hanyadik)
{
    if (mit->ertek < 11)
        printf("A játékos %d. lapja: %s %d\n", hanyadik, mit->szin, mit->ertek);
    else
        printf("A játékos %d. lapja: %s %s\n", hanyadik, mit->szin, ertekbetuvel);
}