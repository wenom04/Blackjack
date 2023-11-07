#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "fuggvenyek.h"

int main()
{
    srand(time(NULL));

    eredmenyek barmi = { 0, 0, 0 };

    for (int i = 0; i < 10; i++)
    {
        int a = rand() % 21;
        int b = rand() % 21;
        dontes(&barmi, a, b);
    }
    
    printf("%d %d %d", barmi.nyert, barmi.dontetlen, barmi.vesztett);

    return 0;
}
