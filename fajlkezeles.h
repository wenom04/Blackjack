#ifndef FAJLKEZELES_H
#define FAJLKEZELE_H 
/// @brief Kiírja a játékszabályt
void jatekszabaly();

/// @brief Elmenti a játék jelenlegi állását
/// @param nyert A nyertes játszmák száma
/// @param dontetlen A döntetlen játszmák száma
/// @param vesztett A vesztes Játszmák száma
/// @param egyenleg A játékos egyenlege
void mentes(int nyert, int dontetlen, int vesztett, int egyenleg);

/// @brief Visszaállítja a játék előző állását, mindent cím szerint kell átadni
/// @param nyert A játékos által az előző játék alkalmával megnyert játszmák száma
/// @param dontetlen A játékos által az előző játék alkalmával döntetlent elért játszmák száma
/// @param vesztett A játékos által az előző játék alkalmával elvesztett játszmák száma
/// @param egyenleg A játékos által az előző játékban összegyűjtött egyenleg
void elozoallas(int *nyert, int *dontetlen, int *vesztett, int *egyenleg);

#endif 