#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "fuggvenyek.h"

int main()
{
    srand(time(NULL));
    int a1 = rand() % 100;
    int a2 = rand() % 100;
    int b1 = rand() % 100;
    int b2 = rand() % 100;
    int b = b1 + b2;
    printf("A gép első sorsolt száma: %d\n", b1);
    printf("A játékos első sorsolt száma: %d\n", a1);
    printf("A játékos második sorsolt száma: %d\n", a2);
    printf("A számaid összege: %d\n", a1 + a2);
    printf("Üss be egy H-át, ha új számot szeretnél, S-et, ha nem.\n");
    bool fusson = true;
    while (fusson)
    {
        char valasz4;
        scanf("%c", &valasz4);
        switch(valasz4)
        {
            case 'H':
            case 'h':
            a2 = rand() % 100; 
            printf("A 2. sorsolt számod: %d\n", a2);
            break;
            case 'S':
            case 's':
                printf("A számaid összege: %d\n", a1 + a2);
                printf("A gép számainak összege: %d\n", b);
                printf("%s", a1 + a2 > b ? "Nyertél\n" : "Vesztettél\n");
            fusson = false;
            break;
            case '\n':
            break;
            default: 
            printf("Nem jó karaktert ütöttél be!\n");
            break;
        }
    }
    return 0;
}

