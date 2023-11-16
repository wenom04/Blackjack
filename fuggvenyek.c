#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"
#include "fajlkezeles.h"

void dontes(eredmenyek *eredmeny, int osszegjatekos, int osszegoszto)
{
    if (osszegjatekos > osszegoszto)
    {
        ++eredmeny->nyert;
    }
    else if (osszegjatekos < osszegoszto)
    {
        ++eredmeny->vesztett;
    }
    else
    {
        ++eredmeny->dontetlen;
    }
}

void kiiras(void)
{
    printf("\nHa új kört szeretnél kezdeni, nyomd meg a [K] betűt és nyomj egy entert!\nHa viszont nem és el szeretnéd menteni az eredményt, nyomd meg a [M] betűt és nyomj egy entert!\n");
}

void erteke(int ertek, char *tomb)
{
    if (ertek == 11)
        strcpy(tomb, "Jumbo");
    else if (ertek == 12)
        strcpy(tomb, "Dáma");
    else if (ertek == 13)
        strcpy(tomb, "Király");
    else if (ertek == 14)
        strcpy(tomb, "Ász");
}

int tisztertek(int tiszt)
{
    if (tiszt > 10 && tiszt < 14)
        return 10;
    else if (tiszt == 14)
        return 11;
    else
        return tiszt;
}

void nemmegfelelo(void)
{
    printf("Nem megfelelő karaktert adtál meg!\n");
}

void nullazas(int *nyert, int *dontetlen, int *vesztett, int *egyenleg)
{
    *nyert = 0;
    *dontetlen = 0;
    *vesztett = 0;
    *egyenleg = 500;
}

void korutaniszoveg(int osszegjatekos, int osszegoszto)
{
    if (osszegjatekos != 0 && osszegoszto != 0 && osszegjatekos > osszegoszto)
        printf("\nGratulálok, megnyerted a kört!\n");
    else if (osszegjatekos != 0 && osszegoszto != 0 && osszegjatekos < osszegoszto)
        printf("\nSajnálom, ezt a kört elvesztetted!\n");
    else if (osszegjatekos != 0 && osszegoszto != 0)
        printf("\nA kör döntetlennel zárult, de jobb, mintha veszítettél volna!\n");
}

void jatekkezdete(char valasz, bool *fut)
{
    switch (valasz)
    {
    case 'i':
    case 'I':
        jatekszabaly();
        printf("\nMostmár mehet? Ha igen, nyomld le a [J] betűt és üss egy entert!\n");
        break;
    case 'J':
    case 'j':
        printf("\nA játék elkezdődött!\n");
        printf("Visszaakarod állítani az előző állást? Ha igen, nyomd meg a [V] betűt és üss egy entert, ha nem, nyomd meg a [N] betűt és üss egy entert!\n");
        *fut = false;
        break;
    case '\n':
        break;
    default:
        nemmegfelelo();
        break;
    }
}

void visszaallitas(char valasz, bool *fut, int *nyert, int *dontetlen, int *vesztett, int *egyenleg)
{
    switch (valasz)
    {
    case 'V':
    case 'v':
        elozoallas(nyert, dontetlen, vesztett, egyenleg);
        if (*egyenleg < 50)
        {
            printf("Nem lehet betölteni, mert az egyenleged kevesebb, mint 50 coin, de kipróbálhatod a Slotunkat, a NYEREK kuponkóddal kapsz 50 ingyen pörgetést ;)\n");
            nullazas(nyert, dontetlen, vesztett, egyenleg);
            *fut = false;
        }
        else
        {
            *fut = false;
        }
        break;
    case 'N':
    case 'n':
        nullazas(nyert, dontetlen, vesztett, egyenleg);
        *fut = false;
        break;
    case '\n':
        break;
    default:
        nemmegfelelo();
        break;
    }
}