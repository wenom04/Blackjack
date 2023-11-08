#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"

int main(){
    int tetek;
    int egyenleg;
    eredmenyek barmi = { 0, 0, 0 };
    pakli *eleje = NULL;
    char szinek[4][10]= {"Pikk", "Kőr", "Káró", "Treff"};
    int ertekek[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            pakli *uj = letrehoz(ertekek[j], szinek[i]);
            uj->kov = eleje;
            eleje = uj;
        }
    }

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
                FILE *fp;
                fp = fopen("jatekszabaly.txt", "r");
                //debugmalloc, hogyan nézem meg a hosszát txt fájlnak?
                char c[500];
                while(fgets(c, 500, fp) != NULL)
                    printf("%s", c);
                fclose(fp);
                printf("\nMostmár mehet? Ha igen, nyomld le a [J] betűt és üss egy entert!\n");
            break;
            case 'J':
            case 'j':
                printf("\nA játék elkezdődött!\n");
                printf("Visszaakarod állítani az előző állást? Ha igen, nyomd meg a [V] betűt és üss egy entert, ha nem, nyomd meg a [N] betűt és üss egy entert!\n");
                fut=false;     
            break;
            case '\n':
            break;
            default:
                printf("Nem megfelelő karaktert adtál meg!\n");
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
                FILE *fp2;
                fp2 = fopen("eredmeny.txt", "r");
                fscanf(fp2, "%d\n%d\n%d\n%d", &barmi.nyert, &barmi.dontetlen, &barmi.vesztett, &egyenleg);
                printf("A játék előző állása:\nNyert: %d\nDöntetlen: %d\nVesztett: %d\n", barmi.nyert, barmi.dontetlen, barmi.vesztett);
                fclose(fp2);
                fut1 = false;
                }
                if (egyenleg < 50)
                {
                    printf("Nem lehet betölteni, mert az egyenleged 0 coin, de kipróbálhatod a Slotunkat, a NYEREK kuponkóddal kapsz 50 ingyen pörgetést ;)\n");
                    barmi.nyert = 0;
                    barmi.dontetlen = 0;
                    barmi.vesztett = 0;
                    egyenleg = 500;
                    vanegyenleg = false;

                }
            break;
            case 'N':
            case 'n':
                barmi.nyert = 0;
                barmi.dontetlen = 0;
                barmi.vesztett = 0;
                egyenleg = 500;
                fut1 = false;                        
            break;
            case '\n':
            break;
            default:
                printf("Nem megfelelő karaktert adtál meg!\n");
            break;
        }
    }

    kiiras();
    bool fut2 = true;
    //bool jotet = false;
    while(fut2)
    {
        char valasz2;
        scanf("%c", &valasz2);
        switch(valasz2)
        {
        case 'K':
        case 'k':
            printf("\nA játék újra elkezdődött!\n");
            printf("Most rakd meg a tétedet. Figyelem! A tétnek minimum 50 coinnak kell lennie!\n");
            scanf("%d", &tetek);
            if(tetek>=50 && tetek <= egyenleg)
            {
                pakli *oszto = eleje;
                pakli *jatekos = eleje;

                pakli *oszto2 = eleje;
                pakli *jatekos2 = eleje;

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
                erteke(jatekos->ertek, ertekbetuvel1);
                erteke(oszto2->ertek, ertekbetuvel2);
                erteke(jatekos2->ertek, ertekbetuvel3);

                dontes(&barmi, jatekos->ertek, jatekos2->ertek, oszto->ertek, oszto2->ertek);
                
                if (oszto->ertek < 11)
                    printf("Az osztó lapja: %s %d\n", oszto->szin, oszto->ertek);
                else 
                    printf("Az osztó lapja: %s %s\n", oszto->szin, ertekbetuvel);             

                if (oszto2->ertek < 11)
                    printf("Az osztó 2. lapja: %s %d\n", oszto2->szin, oszto2->ertek);
                else 
                    printf("Az osztó 2. lapja: %s %s\n", oszto2->szin, ertekbetuvel2);
                osszegoszto(oszto->ertek, oszto2->ertek);             
                
                if (jatekos->ertek < 11)
                    printf("A játékos lapja: %s %d\n", jatekos->szin, jatekos->ertek);
                else 
                    printf("A játékos lapja: %s %s\n", jatekos->szin, ertekbetuvel1); 

                if (jatekos2->ertek < 11)
                    printf("A játékos 2. lapja: %s %d\n", jatekos2->szin, jatekos2->ertek);
                else 
                    printf("A játékos 2. lapja: %s %s\n", jatekos2->szin, ertekbetuvel3);
                osszegjatekos(jatekos->ertek, jatekos2->ertek);

                if (jatekos->ertek + jatekos2->ertek > oszto->ertek + oszto2->ertek)
                    egyenleg = egyenleg + tetek;
                else if (jatekos->ertek + jatekos2->ertek < oszto->ertek + oszto2->ertek)
                    egyenleg = egyenleg - tetek;
                
                printf("\nNyert:%d Döntetlen:%d Vesztett:%d\nEgyenleg:%d\n\n", barmi.nyert, barmi.dontetlen, barmi.vesztett, egyenleg);

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
            printf("A játék véget ért!\n");
            FILE *fp2;
            fp2 = fopen("eredmeny.txt", "w");
            fprintf(fp2, "%d\n%d\n%d\n%d", barmi.nyert, barmi.dontetlen, barmi.vesztett, egyenleg);
            fclose(fp2);
            fut2 = false;
        break;
        case '\n':
        break;
        default:
            printf("Nem megfelelő karaktert adtál meg!\n");
        break;
        }
    }
    pakli_felszabadit(eleje);
}
