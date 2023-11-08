#ifndef FUGGVENYEK_H
#define FUGGVENYEK_H

typedef struct eredmenyek {
    int nyert;
    int vesztett;
    int dontetlen;
    }eredmenyek;

typedef struct pakli {
    int ertek;
    char szin[10];
    struct pakli *kov;
    }pakli;


/// @brief Pakli létrehozása
/// @param ertek A kártya értéke
/// @param szin A kártya színe
/// @return Pointer a létrehozott kártyára
pakli *letrehoz(int ertek, char szin[10]);

/// @brief Eldönti egy állásról, hogy ki nyert
/// @param eredmeny 
/// @param jatekos A játékos kártyáinak összege
/// @param oszto Az osztó kártyáinak összege
void dontes(eredmenyek *eredmeny, int jatekos, int jatekos2, int oszto, int oszto2);

/// @brief Kiír egy szöveget a képernyőre 
void kiiras(void);

/// @brief Felszabadítja a pakli listát
void pakli_felszabadit(pakli* eleje);

void erteke(int ertek, char *tomb);

int tisztertek(int tiszt);

#endif // FUGGVENYEK_H

