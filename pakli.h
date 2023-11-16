#ifndef PAKLI_H
#define PAKLI_H

/// @brief Kártya létrehozása
/// @param ertek A kártya értéke
/// @param szin A kártya színe
/// @return Pointer a létrehozott kártyára
kartya *letrehoz(int ertek, char szin[10]);

/// @brief Felszabadítja a pakli listát
void pakli_felszabadit(kartya* eleje);


kartya *kartyatorlese(kartya *eleje, kartya *keresett);


/// @brief Létrehozza a paklit a letrehoz() függvény segítségével
/// @return EGy 52 elemmel feltöltött pakli
kartya* paklitletrehoz();

kartya *kartyaosztas(kartya *eleje, int db);

void osztokartyakiirasa(kartya *mit, char *ertekbetuvel, int hanyadik);

void jatekoskartyakiirasa(kartya *mit, char *ertekbetuvel, int hanyadik);

#endif