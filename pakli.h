#ifndef PAKLI_H
#define PAKLI_H

/// @brief Kártya létrehozása
/// @param ertek A kártya értéke
/// @param szin A kártya színe
/// @return Pointer a létrehozott kártyára
pakli *letrehoz(int ertek, char szin[10]);

/// @brief Felszabadítja a pakli listát
void pakli_felszabadit(pakli* eleje);

/// @brief Eltávolít egy kártyát a a pakliból
/// @param eleje A kártyák listája
/// @param ertek A kártya értéke
/// @param szin A kártya színe
void kartyatorlese(pakli *eleje, int ertek, char *szin);

/*
/// @brief Létrehozza a paklit a letrehoz() függvény segítségével
/// @return EGy 52 elemmel feltöltött pakli
pakli* paklitletrehoz();
*/
#endif