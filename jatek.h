#ifndef FUGGVENYEK_H
#define FUGGVENYEK_H

#include <stdbool.h>

typedef struct eredmenyek {
    int nyert;
    int vesztett;
    int dontetlen;
    }eredmenyek;

typedef struct kartya {
    int ertek;
    char szin[10];
    struct kartya *kov;
    }kartya;

/// @brief Eldönti egy állásról, hogy ki nyert
/// @param eredmeny Eredmeny nevű struct, címszerint kell átadni
/// @param jatekos A játékos kártyáinak összege
/// @param oszto Az osztó kártyáinak összege
void dontes(eredmenyek *eredmeny, int osszegjatekos, int osszegoszto);

/// @brief Kiír egy szöveget a képernyőre 
void kiiras(void);

/// @brief Ha tiszt kártyát kap a játékos vagy az osztó, akkor a függvény eldönti, hogy melyik tisztről van szó, és nem egy számot ír ki, hanem a tiszt nevét 
/// @param ertek A kártya értéke (11 v. 12 v. 13 v. 14)
/// @param tomb A tömb, amelybe a függvény beírja a tiszt nevét
void erteke(int ertek, char *tomb);

/// @brief Egy számot ad vissza, amely a tiszt értéke
/// @param tiszt A kártya értéke
/// @return Ha sima szám van, akkor azt fogja visszaadni, Jumbó, Dáma és Király esetén 10, Ász esetén 11
int tisztertek(int tiszt);

/// @brief Kiír egy rövid szöveget, ha a játékos nem megfelelő karaktert ütött be
void nemmegfelelo();

/// @brief Ha hiba van betöltéskor, akkor 0-za az eredményeket és az egyenleget beállítja 500 coinra
/// @param nyert A struct nyert változója
/// @param dontetlen A struct döntetlen változója
/// @param vesztett A struct vesztett változója
/// @param egyenleg Az egyenleg változó
void nullazas(int *nyert, int *dontetlen, int *vesztett, int *egyenleg);

/// @brief Ha nem haladta meg az osztó, sem a játékos kártyáinak az összege a 21-et, akkor kiír egy üzenet, hogy ki nyert
/// @param osszegjatekos A játékos kártyáinak összege
/// @param osszegoszto Az osztó kártyáinak összege
void korutaniszoveg(int osszegjatekos, int osszegoszto);

/// @brief A játék kezdete előtti rövid switch, ki tudja írni a játékszabályt, vagy elindítja a játékot a megfelelő karakter lenyomása után
/// @param valasz A leütött karakter, a switchnek kell 
/// @param fut Igaz, hamis változó, címszerint kell átadni
bool jatekkezdete(char valasz);

/// @brief Vagy visszaállítja az előző állást, vagy mindent a kezdőállapotra állít be
/// @param valasz A leütött karakter, a switchnek kell 
/// @param fut Igaz, hamis változó, címszerint kell átadni
/// @param nyert A struct nyert nevű változója, címszerint kell átadni
/// @param dontetlen A struct döntetlen nevű változója, címszerint kell átadni
/// @param vesztett A struct vesztett nevű változója, címszerint kell átadni
/// @param egyenleg A játékos egyenlegváltozója, címszerint kell átadni
/// @return Visza ad igazat, ha jó karaktert ütött be a játékos, ez a kör előtti szövegnek fontos, hogy az első kör előtt ne legyen kiírva
bool visszaallitas(char valasz, bool *fut, int *nyert, int *dontetlen, int *vesztett, int *egyenleg);

#endif // FUGGVENYEK_H

