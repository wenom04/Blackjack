#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "fajlkezeles.h"


void jatekszabaly(){
    FILE *fp;
    fp = fopen("jatekszabaly.txt", "r");
    char c[500];
    while(fgets(c, 500, fp) != NULL)
    printf("%s", c);
    fclose(fp);
}

void mentes(int nyert, int dontetlen, int vesztett, int egyenleg){
    printf("A játék véget ért!\n");
    FILE *fp3;
    fp3 = fopen("eredmeny.txt", "w");
    fprintf(fp3, "%d\n%d\n%d\n%d", nyert, dontetlen, vesztett, egyenleg);
    fclose(fp3);
}
void elozoallas(int *nyert, int *dontetlen, int *vesztett, int *egyenleg){
    FILE *fp2;
    fp2 = fopen("eredmeny.txt", "r");
    fscanf(fp2, "%d\n%d\n%d\n%d", nyert, dontetlen, vesztett, egyenleg);
    printf("A játék előző állása:\nNyert: %d\nDöntetlen: %d\nVesztett: %d\nEgyenleg: %d\n", *nyert, *dontetlen, *vesztett, *egyenleg);
    fclose(fp2);
}