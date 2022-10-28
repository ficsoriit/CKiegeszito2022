#include <stdio.h>
#include <stdlib.h>

int beolvasEgeszLeall();
int beolvasEgeszIsmetel();

main(int argc, char **argv) {
    int beolvasottSzam;
    //beolvasottSzam = beolvasEgeszLeall();
    beolvasottSzam = beolvasEgeszIsmetel();
    printf("A beolvasott szam: %d\n", beolvasottSzam);
}

int beolvasEgeszLeall() {
    int szam;
    if (scanf("%d", &szam) != 1) {
        printf("Hibás input, a program leáll!\n");
        exit(1);
    }
    return szam;
}

int beolvasEgeszIsmetel() {
    int szam;
    int ok;
    char c;
    do {
        ok = 1;
        printf("Adj meg egy egész számot! ");
        if (scanf("%d", &szam) != 1) {
            printf("Hibás input!\n");
            ok = 0;
            // Buffer urites!!!
            while((c=getchar()) != '\n');
         }   
    } while(!ok);
 
    return szam;
}