#pragma once

typedef struct eredmenyek {
    int nyert;
    int vesztett;
    int dontetlen;
    }eredmenyek;
    
void dontes(eredmenyek *eredmeny, int jatekos, int oszto);

void kiiras(void);
