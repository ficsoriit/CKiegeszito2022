#include <stdio.h>
#include <stdbool.h>

#define MIN 100
#define MAX 10000

int beolvasEgeszIntervallum(int min, int max);
int beolvasEgeszIsmetel();
bool primszamE(int szam);

main(int argc, char *argv[]) {
    // Masik lehetoseg konstans definiciora
    // const int MIN=100;
    // const int MAX=10000;
int darab;
darab = beolvasEgeszIsmetel();
int i;
int inputSzam;
int primekSzama = 0;
int primekOsszege = 0;
for (int i=0; i<darab; i++) {
    inputSzam = beolvasEgeszIntervallum(MIN, MAX);
    if (primszamE(inputSzam) ) {
        primekSzama++;
        primekOsszege += inputSzam;
    }
}
printf("A primek szama: %d\n", primekSzama);
if (primekSzama != 0) {
    printf("A primek atlaga: %lf\n", (double)primekOsszege / primekSzama);
} else {
    printf("Nem volt primszam!\n");
}
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

bool primszamE(int szam) {
    bool valasz = true;
    for (int i=2; i<szam/2; i++) {
        if (szam%i == 0) {
            valasz = false;
            break;
        }
    }
    return valasz;
}
