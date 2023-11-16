#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"
#include "fajlkezeles.h"
#include "pakli.h"

int main()
{
    srand(time(NULL));
    int tetek;
    int egyenleg;
    eredmenyek eredmeny = {0, 0, 0};
    kartya *eleje = NULL;
    eleje = paklitletrehoz();

    printf("Üdvözöllek a játékban!\nKészen állsz?\nHa igen, nyomd meg a [J] betűt és üss egy entert, ha meg nem, és el szeretnéd olvasni a játékszabályt, nyomd meg az [I] betűt, majd üss egy entert!\n");

    bool fut = true;
    while (fut)
    {
        char valasz;
        scanf("%c", &valasz);
        jatekkezdete(valasz, &fut);
    }

    bool fut1 = true;
    while (fut1)
    {
        char valasz2;
        scanf("%c", &valasz2);
        visszaallitas(valasz2, &fut1, &eredmeny.nyert, &eredmeny.dontetlen, &eredmeny.vesztett, &egyenleg);
    }

    kiiras();
    bool fut2 = true;
    bool osztovanasz = false;
    bool jatekosvanasz = false;
    while (fut2)
    {
        char valasz2;
        scanf("%c", &valasz2);
        switch (valasz2)
        {
        case 'K':
        case 'k':
            printf("\nA játék újra elkezdődött!\n");
            printf("Most rakd meg a tétedet. Figyelem! A tétnek minimum 50 coinnak kell lennie!\nAz egyenleged: %d\n", egyenleg);
            scanf("%d", &tetek);
            if (tetek >= 50 && tetek <= egyenleg)
            {
                int darab_kartya = 0;
                int daraboszto = 1;
                int darabjatekos = 1;

                char ertekbetuvel[10] = {'\0'};
                char ertekbetuvel1[10] = {'\0'};
                char ertekbetuvel2[10] = {'\0'};
                char ertekbetuvel3[10] = {'\0'};

                kartya *oszto = kartyaosztas(eleje, darab_kartya);
                erteke(oszto->ertek, ertekbetuvel);
                if (oszto->ertek == 14)
                {
                    osztovanasz = true;
                }
                osztokartyakiirasa(oszto, ertekbetuvel, daraboszto);
                int osztoelso = tisztertek(oszto->ertek);
                eleje = kartyatorlese(eleje, oszto);
                darab_kartya = darab_kartya + 1;
                daraboszto = daraboszto + 1;
                printf("\n");

                kartya *jatekos = kartyaosztas(eleje, darab_kartya);
                erteke(jatekos->ertek, ertekbetuvel1);
                if (jatekos->ertek == 14)
                {
                    jatekosvanasz = true;
                }
                jatekoskartyakiirasa(jatekos, ertekbetuvel1, darabjatekos);
                int jatekoselso = tisztertek(jatekos->ertek);
                darab_kartya = darab_kartya + 1;
                darabjatekos = darabjatekos + 1;
                eleje = kartyatorlese(eleje, jatekos);

                kartya *jatekos2 = kartyaosztas(eleje, darab_kartya);
                erteke(jatekos2->ertek, ertekbetuvel3);
                if (jatekos2->ertek == 14)
                {
                    jatekosvanasz = true;
                }
                jatekoskartyakiirasa(jatekos2, ertekbetuvel3, darabjatekos);
                int jatekosmasodik = tisztertek(jatekos2->ertek);
                darab_kartya = darab_kartya + 1;
                darabjatekos = darabjatekos + 1;
                eleje = kartyatorlese(eleje, jatekos2);

                kartya *oszto2 = kartyaosztas(eleje, darab_kartya);
                erteke(oszto2->ertek, ertekbetuvel2);
                if (oszto2->ertek == 14)
                {
                    osztovanasz = true;
                }
                int osztomasodik = tisztertek(oszto2->ertek);
                char oszto2szin[10];
                strcpy(oszto2szin, oszto2->szin);
                darab_kartya = darab_kartya + 1;
                daraboszto = daraboszto + 1;
                eleje = kartyatorlese(eleje, oszto2);

                kartya *oszto3 = eleje;

                int osszegoszto = osztoelso + osztomasodik;
                int osszegjatekos = jatekoselso + jatekosmasodik;

                if (jatekoselso == 14 && jatekosmasodik == 14)
                {
                    osszegjatekos = 12;
                }

                if (osztoelso == 14 && osztomasodik == 14)
                {
                    osszegoszto = 12;
                }

                printf("Az összege: %d\n\n", osszegjatekos);
                printf("\nHa szeretnél új lapot, akkor nyomd meg a [H] betűt és üss entert, ha viszont jók ezek a lapok neked, nyomd meg az [S] betűt és üss egy entert.\n");
                bool fusson = true;
                bool nemeleg = true;
                while (fusson)
                {
                    char valasz4;
                    scanf("%c", &valasz4);
                    switch (valasz4)
                    {
                    case 'H':
                    case 'h':

                        char ertekbetuvel1[10] = {'\0'};
                        jatekos = kartyaosztas(eleje, darab_kartya);
                        erteke(jatekos->ertek, ertekbetuvel1);
                        if (jatekos->ertek == 14)
                        {
                            jatekosvanasz = true;
                        }
                        jatekoskartyakiirasa(jatekos, ertekbetuvel1, darabjatekos);
                        osszegjatekos = osszegjatekos + tisztertek(jatekos->ertek);            
                        darabjatekos = darabjatekos + 1;
                        darab_kartya = darab_kartya + 1;
                        eleje = kartyatorlese(eleje, jatekos);
                        printf("Összegük: %d\n\n", osszegjatekos);

                        if (osszegjatekos > 21 && jatekosvanasz)
                        {
                            osszegjatekos = osszegjatekos - 10;
                            printf("Volt ászod!\n");
                            printf("Új összeg: %d\n\n", osszegjatekos);
                            jatekosvanasz = false;
                        }

                        if (osszegjatekos > 21 && !jatekosvanasz)
                        {
                            printf("Sajnos meghaladtad a 21-et, így elvesztetted a kört.\n");
                            osszegjatekos = 0;
                            fusson = false;
                        }
                        else
                            printf("Ha szeretnél új lapot, akkor nyomd meg a [H] betűt és üss entert, ha viszont jók ezek a lapok neked, nyomd meg az [S] betűt és üss egy entert.\n");

                        break;
                    case 'S':
                    case 's':
                        printf("Maradtak ezek a kártyaid. Összegük: %d\n\n", osszegjatekos);
                        if (oszto2->ertek < 11)
                            printf("Az osztó 2. lapja: %s %d\n", oszto2szin, osztomasodik);
                        else
                            printf("Az osztó 2. lapja: %s %s\n", oszto2szin, ertekbetuvel2);

                        if (osszegoszto >= 17 && osszegoszto <= 21)
                        {
                            printf("Az összege: %d\n", osszegoszto);
                            nemeleg = false;
                            fusson = false;
                        }

                        while (nemeleg)
                        {
                            oszto3 = eleje;
                            int e = rand() % 52 - darab_kartya;

                            for (int i = 0; i < e; i++)
                                oszto3 = oszto3->kov;

                            if (oszto3->ertek == 14)
                            {
                                osztovanasz = true;
                            }

                            char ertekbetuvel4[10] = {'\0'};
                            erteke(oszto3->ertek, ertekbetuvel4);
                            if (oszto3->ertek < 11)
                                printf("\nAz osztó következő lapja: %s %d\n", oszto3->szin, oszto3->ertek);
                            else
                                printf("\nAz osztó következő lapja: %s %s\n", oszto3->szin, ertekbetuvel4);
                            osszegoszto = osszegoszto + tisztertek(oszto3->ertek);

                            darab_kartya = darab_kartya + 1;

                            if (osszegoszto > 21 && osztovanasz)
                            {
                                osszegoszto = osszegoszto - 10;
                                osztovanasz = false;
                            }

                            if (osszegoszto >= 17)
                            {
                                printf("Az összege: %d\n", osszegoszto);
                                nemeleg = false;
                            }
                        }

                        if (osszegoszto > 21)
                        {
                            printf("Az osztó kártyáinak összege meghaladta a 21-et, így te nyerted a kört!\n");
                            osszegoszto = 0;
                            fusson = false;
                        }

                        if (osszegoszto >= 17 && osszegoszto <= 21)
                        {
                            nemeleg = false;
                            fusson = false;
                        }
                        break;
                    case '\n':
                        break;
                    default:
                        nemmegfelelo();
                        break;
                    }
                }
                dontes(&eredmeny, osszegjatekos, osszegoszto);
                if (osszegjatekos > osszegoszto)
                    egyenleg = egyenleg + tetek;
                else if (osszegjatekos < osszegoszto)
                    egyenleg = egyenleg - tetek;
                    
                pakli_felszabadit(eleje);
                korutaniszoveg(osszegjatekos, osszegoszto);

                printf("\nNyert:%d Döntetlen:%d Vesztett:%d\nEgyenleg:%d\n\n", eredmeny.nyert, eredmeny.dontetlen, eredmeny.vesztett, egyenleg);

                tetek = 0;
                kiiras();
            }
            else
                printf("\nTúl kevés vagy túl sok tétet raktál meg! Nyomd meg újra a [K] betűt és üss egy entert!\n");
            if (egyenleg < 50)
            {
                printf("\nSajnálom, de elvesztetted az egész egyenlegedet, így már nem tudsz tétet rakni, de kipróbálhatod a Slotunkat, a NYEREK kuponkóddal kapsz 50 ingyen pörgetést ;)\n\n");
                fut2 = false;
            }
            eleje = paklitletrehoz();
            break;
        case 'M':
        case 'm':
            mentes(eredmeny.nyert, eredmeny.dontetlen, eredmeny.vesztett, egyenleg);
            fut2 = false;
            break;
        case '\n':
            break;
        default:
            nemmegfelelo();
            break;
        }
    }
}