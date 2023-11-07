#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include "debugmalloc.h"
//#include "fuggvenyek.h"

typedef struct eredmenyek {
    int nyert;
    int vesztett;
    int dontetlen;
    }eredmenyek;

typedef struct pakli {
    int ertek;
    char szin[6];
    struct pakli *kov;
    }pakli;

/// @brief Pakli létrehozása
/// @param ertek A kártya értéke
/// @param szin A kártya színe
/// @return Pointer a létrehozott kártyára
pakli *letrehoz(int ertek, char szin[5]);

/// @brief Eldönti egy állásról, hogy ki nyert
/// @param eredmeny 
/// @param jatekos A játékos kártyáinak összege
/// @param oszto Az osztó kártyáinak összege
void dontes(eredmenyek *eredmeny, int jatekos, int oszto);

/// @brief Kiír egy szöveget a képernyőre 
void kiiras(void);

/// @brief Felszabadítja a pakli listát
void pakli_felszabadit(pakli* eleje);


int main(){
    int tetek;
    int egyenleg;
    eredmenyek barmi = { 0, 0, 0 };
    pakli *eleje = NULL;
    char szinek[4][6]= {"Pikk", "Kőr", "Káró", "Treff"};
    char ertekek[13][7] = {"Ász", "Kettő", "Három", "Négy", "Öt", "Hat", "Hét", "Nyolc", "Kilenc", "Tíz", "Bubi", "Dáma", "Király"};
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            pakli *uj = letrehoz(j+1, szinek[i]);
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
                if (egyenleg == 0)
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
                
                srand(time(NULL));           
                int a = rand() % 52;
                int b = rand() % 52;
                dontes(&barmi, a, b);

                if (a > b)
                    egyenleg = egyenleg + tetek;
                else if (a < b)
                    egyenleg = egyenleg - tetek;
                else
                    egyenleg = egyenleg;
                
                printf("\nNyert:%d Döntetlen:%d Vesztett:%d\nEgyenleg:%d\n\n", barmi.nyert, barmi.dontetlen, barmi.vesztett, egyenleg);

                tetek = 0;
                kiiras();
            }
            else
                printf("\nTúl kevés vagy túl sok tétet raktál meg! Nyomd meg újra a [K] betűt és üss egy entert!\n");
            if (egyenleg == 0)
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
void dontes(eredmenyek *eredmeny, int jatekos, int oszto){
    if(jatekos>oszto)
        ++eredmeny->nyert;
    else if(jatekos<oszto)
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

pakli *letrehoz(int ertek, char szin[5]){
    pakli *uj = (pakli*)malloc(sizeof(pakli));
    uj->ertek = ertek;
    strcpy(uj->szin, szin);
    uj->kov = NULL;
    return uj;
}