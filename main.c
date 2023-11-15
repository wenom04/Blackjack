#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"
#include "fajlkezeles.h"
#include "pakli.h"

int main(){
    int tetek;
    int egyenleg;
    eredmenyek eredmeny = { 0, 0, 0 };
    kartya *eleje = NULL;
    eleje = paklitletrehoz();
    
    printf("Üdvözöllek a játékban!\nKészen állsz?\nHa igen, nyomd meg a [J] betűt és üss egy entert, ha meg nem, és el szeretnéd olvasni a játékszabályt, nyomd meg az [I] betűt, majd üss egy entert!\n");
    
    bool fut = true;
    while (fut)
    {
        char valasz;
        scanf("%c", &valasz);
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
                fut = false;     
            break;
            case '\n':
            break;
            default:
                nemmegfelelo();
            break;
        }
    }

    bool fut1 = true;
    bool vanegyenleg = true;
    while(fut1)
    {
        char valasz3;
        scanf("%c", &valasz3);
        switch(valasz3)
        {
            case 'V':
            case 'v':
                if (vanegyenleg)
                {
                    elozoallas(&eredmeny.nyert, &eredmeny.dontetlen, &eredmeny.vesztett, &egyenleg);
                fut1 = false;
                }
                if (egyenleg < 50)
                {
                    printf("Nem lehet betölteni, mert az egyenleged kevesebb, mint 50 coin, de kipróbálhatod a Slotunkat, a NYEREK kuponkóddal kapsz 50 ingyen pörgetést ;)\n");
                    nullazas(&eredmeny.nyert, &eredmeny.dontetlen, &eredmeny.vesztett, &egyenleg);
                    vanegyenleg = false;

                }
            break;
            case 'N':
            case 'n':
                nullazas(&eredmeny.nyert, &eredmeny.dontetlen, &eredmeny.vesztett, &egyenleg);
                fut1 = false;                        
            break;
            case '\n':
            break;
            default:
                nemmegfelelo();
            break;
        }
    }

    kiiras();
    bool fut2 = true;
    bool osztovanasz = false;
    bool jatekosvanasz = false;
    while(fut2)
    {
        char valasz2;
        scanf("%c", &valasz2);
        switch(valasz2)
        {
        case 'K':
        case 'k':
            printf("\nA játék újra elkezdődött!\n");
            printf("Most rakd meg a tétedet. Figyelem! A tétnek minimum 50 coinnak kell lennie!\nAz egyenleged: %d\n", egyenleg);
            scanf("%d", &tetek);
            if(tetek >= 50 && tetek <= egyenleg)
            {
                kartya *oszto = eleje;
                kartya *jatekos = eleje;

                kartya *oszto2 = eleje;
                kartya *jatekos2 = eleje;

                kartya *oszto3 = eleje;

                srand(time(NULL));           
                int a = rand() % 52;
                int b = rand() % 52;
                int c = rand() % 52;
                int d = rand() % 52;
                
                for(int i=0; i<b; i++)
                    oszto = oszto->kov;
                for(int i=0; i<a; i++)
                    jatekos = jatekos->kov;
                for(int i=0; i<c; i++)
                    oszto2 = oszto2->kov;
                for(int i=0; i<d; i++)
                    jatekos2 = jatekos2->kov;
                
                char ertekbetuvel[10] = {'\0'};
                char ertekbetuvel1[10] = {'\0'};
                char ertekbetuvel2[10] = {'\0'};
                char ertekbetuvel3[10] = {'\0'};

                erteke(oszto->ertek, ertekbetuvel);
                if (oszto->ertek == 14){
                    osztovanasz = true;
                }
                

                erteke(jatekos->ertek, ertekbetuvel1);
                if (jatekos->ertek == 14){
                    jatekosvanasz = true;
                }
                //kartyatorlese(eleje, jatekos);

                erteke(oszto2->ertek, ertekbetuvel2);
                if (oszto2->ertek == 14){
                    osztovanasz = true;
                }
                //kartyatorlese(eleje, oszto2);

                erteke(jatekos2->ertek, ertekbetuvel3);
                if (jatekos2->ertek == 14){
                    jatekosvanasz = true;
                }
                //kartyatorlese(eleje, jatekos2);
                
                int osszegoszto = tisztertek(oszto->ertek) + tisztertek(oszto2->ertek);
                int osszegjatekos = tisztertek(jatekos->ertek) + tisztertek(jatekos2->ertek);

                if (jatekos->ertek == 14 && jatekos2->ertek == 14){
                    osszegjatekos = 12;
                }

                if (oszto->ertek == 14 && oszto2->ertek == 14){
                    osszegoszto = 12;
                }
                
                if (oszto->ertek < 11)
                    printf("\nAz osztó lapja: %s %d\n\n", oszto->szin, oszto->ertek);
                else 
                    printf("\nAz osztó lapja: %s %s\n\n", oszto->szin, ertekbetuvel);
                kartyatorlese(eleje, oszto);             
                if (jatekos->ertek < 11)
                    printf("A játékos lapja: %s %d\n", jatekos->szin, jatekos->ertek);
                else 
                    printf("A játékos lapja: %s %s\n", jatekos->szin, ertekbetuvel1); 

                if (jatekos2->ertek < 11)
                    printf("A játékos 2. lapja: %s %d\n", jatekos2->szin, jatekos2->ertek);
                else 
                    printf("A játékos 2. lapja: %s %s\n", jatekos2->szin, ertekbetuvel3);
                printf("Az összege: %d\n\n", osszegjatekos);
                printf("\nHa szeretnél új lapot, akkor nyomd meg a [H] betűt és üss entert, ha viszont jók ezek a lapok neked, nyomd meg az [S] betűt és üss egy entert.\n");
               bool fusson = true;
               bool nemeleg = true;
               int darab_kartya = 0;
               while (fusson)
                {  
                        char valasz4;
                        scanf("%c", &valasz4);
                        switch(valasz4)
                        {
                            case 'H':
                            case 'h':

                                jatekos = eleje;
                                a = rand() % 52 - darab_kartya;               
                                for(int i = 0; i < a; i++)
                                    jatekos = jatekos->kov;
                                char ertekbetuvel1[10] = {'\0'};

                                if (jatekos->ertek == 14){
                                    jatekosvanasz = true;
                                }
                                erteke(jatekos->ertek, ertekbetuvel1);  
                                if (jatekos->ertek < 11)
                                    printf("\nA játékos következő lapja: %s %d\n", jatekos->szin, jatekos->ertek);
                                else 
                                    printf("\nA játékos következő lapja: %s %s\n", jatekos->szin, ertekbetuvel1); 
                                osszegjatekos = osszegjatekos + tisztertek(jatekos->ertek);
                                printf("Összegük: %d\n\n", osszegjatekos);

                                darab_kartya = darab_kartya + 1;

                                if(osszegjatekos > 21 && jatekosvanasz ){
                                    osszegjatekos = osszegjatekos - 10;
                                    printf("Volt ászod!\n");
                                    printf("Új összeg: %d\n\n", osszegjatekos);
                                    jatekosvanasz = false;
                                }
                                
                                if (osszegjatekos > 21 && !jatekosvanasz){
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
                                    printf("Az osztó 2. lapja: %s %d\n", oszto2->szin, oszto2->ertek);
                                else 
                                    printf("Az osztó 2. lapja: %s %s\n", oszto2->szin, ertekbetuvel2);

                                if(osszegoszto >= 17 && osszegoszto <= 21 )
                                {
                                    printf("Az összege: %d\n", osszegoszto);
                                    nemeleg = false;
                                    fusson = false;
                                }
                                
                                while(nemeleg)
                                {
                                    oszto3 = eleje;
                                    int e = rand () % 52 - darab_kartya;

                                    for(int i = 0; i < e; i++)
                                        oszto3 = oszto3->kov;

                                    if (oszto3->ertek == 14){
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

                                    if (osszegoszto > 21 && osztovanasz){
                                        osszegoszto = osszegoszto - 10;
                                    }

                                    if(osszegoszto >= 17)
                                    {
                                        printf("Az összege: %d\n", osszegoszto);
                                        nemeleg = false;
                                    }

                                }

                                if(osszegoszto > 21)
                                {
                                    printf("Az osztó kártyáinak összege meghaladta a 21-et, így te nyerted a kört!\n");
                                    osszegoszto = 0;
                                    fusson = false;
                                }

                                if(osszegoszto >= 17 && osszegoszto <= 21)
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
                
                if (osszegjatekos != 0 && osszegoszto != 0 && osszegjatekos > osszegoszto)
                    printf("\nGratulálok, megnyerted a kört!\n");
                else if (osszegjatekos != 0 && osszegoszto != 0 && osszegjatekos < osszegoszto)
                    printf("\nSajnálom, ezt a kört elvesztetted!\n");
                else if(osszegjatekos != 0 && osszegoszto != 0)
                    printf("\nA kör döntetlennel zárult, de jobb, mintha veszítettél volna!\n");
                
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
    pakli_felszabadit(eleje);
}
