#ifndef PAKLI_H
#define PAKLI_H

/// @brief Kártya létrehozása
/// @param ertek A kártya értéke
/// @param szin A kártya színe
/// @return Pointer a létrehozott kártyára
kartya *letrehoz(int ertek, char szin[10]);

/// @brief Felszabadítja a pakli listát
void pakli_felszabadit(kartya* eleje);

/// @brief Kitöröl egy már kihúzott kártyát a pakliból
/// @param eleje A pakli első kártyájának pointere
/// @param keresett A törlendő kárya pointere
/// @return Az új pakli első kártyájának pointere
kartya *kartyatorlese(kartya *eleje, kartya *keresett);

/// @brief Létrehozza a paklit a letrehoz() függvény segítségével
/// @return EGy 52 elemmel feltöltött pakli
kartya* paklitletrehoz();

/// @brief Kioszt egy kártyát
/// @param eleje A pakli első kártyájámnak pointere
/// @param db Hány db kártya lett eddig kihúzva a pakliból, ez a randomszámgenerátornak szükséges
/// @return A kihúzott kártyára mutató pointer
kartya *kartyaosztas(kartya *eleje, int db);

/// @brief Kiírja az osztó kártyáját a terminálba
/// @param mit A kiirandó kártyára mutató pointer
/// @param ertekbetuvel A tömb, amibe be lesz írva a tiszt neve, ha a kártya tiszt
/// @param hanyadik Az osztónak hanyadik kártyája
void osztokartyakiirasa(kartya *mit, char *ertekbetuvel, int hanyadik);

/// @brief Kiírja a játékos kártyáját a terminálba
/// @param mit A kiirandó kártyára mutató pointer
/// @param ertekbetuvel A tömb, amibe be lesz írva a tiszt neve, ha a kártya tiszt
/// @param hanyadik A játékos hanyadik kártyája
void jatekoskartyakiirasa(kartya *mit, char *ertekbetuvel, int hanyadik);

#endif