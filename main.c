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
    pakli *eleje = NULL;
    for(int i=1; i<14; i++){
        pakli *uj = letrehoz(i, "Pikk");
        if (uj->ertek == 1)
        printf("%s Ász\n", uj->szin);
        else if (uj->ertek == 11)
        printf("%s Jumbo\n", uj->szin);
        else if (uj->ertek == 12)
        printf("%s Dáma\n", uj->szin);
        else if (uj->ertek == 13)
        printf("%s Király\n", uj->szin);
        else
        printf("%s %d\n", uj->szin, uj->ertek);
    }
    for(int i=1; i<14; i++){
        pakli *uj = letrehoz(i, "Kőr");
    }
    for(int i=1; i<14; i++){
        pakli *uj = letrehoz(i, "Treff");
    }
    for(int i=1; i<14; i++){
        pakli *uj = letrehoz(i, "Káró");
    }
    printf("Üdvözöllek a játékban!\nKészen állsz?\nHa igen, nyomd meg a [J] betűt és üss egy entert, ha meg nem, és el szeretnéd olvasni a játékszabályt, nyomd meg az [I] betűt, majd üss egy entert!\n");
    bool fut = true;
    while (fut){
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
            printf("A játék elkezdődött!\n");
            fut=false;     
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
    while(fut2){
        char valasz2;
        scanf("%c", &valasz2);
        switch(valasz2){
        case 'K':
        case 'k':
        printf("A játék újra elkezdődött!\n");
        srand(time(NULL));

        eredmenyek barmi = { 0, 0, 0 };

        for (int i = 0; i < 10; i++)
        {
            int a = rand() % 21;
            int b = rand() % 21;
            dontes(&barmi, a, b);
        }
    
        printf("%d %d %d", barmi.nyert, barmi.dontetlen, barmi.vesztett);
        break;
        case 'M':
        case 'm':
            printf("A játék véget ért!\n");
            FILE *fp2;
            fp2 = fopen("eredmeny.txt", "w");
            fprintf(fp2, "%d\n%d\n%d\n900", barmi.nyert, barmi.dontetlen, barmi.vesztett);
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
    printf("Ha új kört szeretnél kezdeni, nyomd meg a [K] betűt és nyomj egy entert!\nHa viszont nem és el szeretnéd menteni az eredményt, nyomd meg a [M] betűt és nyomj egy entert!\n");
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