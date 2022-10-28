#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int beolvasEgeszLeall();
int beolvasEgeszIsmetel();
int beolvasEgeszIntervallum(int min, int max);
int beolvasEgeszIntervallumMas(int min, int max);

main(int argc, char **argv) {
    int beolvasottSzam;
    //beolvasottSzam = beolvasEgeszLeall();
    //beolvasottSzam = beolvasEgeszIsmetel();
    //beolvasottSzam = beolvasEgeszIntervallum(10, 100);
    beolvasottSzam = beolvasEgeszIntervallumMas(10, 100);
    printf("A beolvasott szam: %d\n", beolvasottSzam);
    beolvasottSzam = beolvasEgeszIntervallumMas(10, 100);
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
    bool ok;
    char c;
    do {
        ok = true;
        printf("Adj meg egy egész számot! ");
        if (scanf("%d", &szam) != 1) {
            printf("Hibás input!\n");
            ok = false;
            // Buffer urites!!!
            while((c=getchar()) != '\n');
         }   
    } while(!ok);
 
    return szam;
}

int beolvasEgeszIntervallum(int min, int max) {
    int szam;
    bool ok;
    char c;
    do {
        ok = true;
        printf("Adj meg egy egész számot %d és %d között! ", min, max); 
        if (scanf("%d", &szam) != 1) {
            printf("Hibás input!\n");
            ok = false;
            // Buffer urites!!!
            while((c=getchar()) != '\n');
         }   
    } while(!ok || szam<min || szam>max);
 
    return szam;
}

int beolvasEgeszIntervallumMas(int min, int max) {
    int szam;
    bool ok;
    char c;
    do {
        ok = true;
        printf("Adj meg egy egész számot %d és %d között! ", min, max); 
        if (scanf("%d", &szam) != 1) {
            // Formai vizsgalat
            printf("Hibás input!\n");
            ok = false;
            // Buffer urites!!!
            while((c=getchar()) != '\n');
         } else {
            // Tartalmi vizsgalat
            if (szam<min || szam>max) {
                ok = false; 
            }
            // Buffer urites!!! --Ovatosságból
            while((c=getchar()) != '\n');
         } 
    } while(!ok);
 
    return szam;
}
