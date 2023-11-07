#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void kiiras(void){
    printf("Ha új kört szeretnél kezdeni, nyomd meg a [K] betűt és nyomj egy entert!\nHa viszont nem és el szeretnéd menteni az eredményt, nyomd meg a [M] betűt és nyomj egy entert!\n");
}

int main(){
    kiiras();
    bool fut2 = true;
    while(fut2){
        char valasz2;
        scanf("%c", &valasz2);
        switch(valasz2){
        case 'K':
        case 'k':
            printf("A játék újra elkezdődött!\n");
        break;
        case 'M':
        case 'm':
            printf("A játék véget ért!\n");
            FILE *fp2;
            fp2 = fopen("eredmeny.txt", "w");
            fprintf(fp2, "6\n3\n4\n900");
            fclose(fp2);
            fut2 = false;
        break;
        case '\n':
        break;
        default:
            printf("Nem megfelelő karaktert adtál meg!\n");
        break;
    }
    }

}