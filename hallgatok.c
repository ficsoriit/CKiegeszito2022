#include <stdio.h>
#include <stdbool.h>
#define MINELETKOR 18
#define MAXELETKOR 28

void kiirEgeszTomb(int tomb[], int elemszam);
int beolvasEgeszIntervallum(int min, int max);
void beolvasTartomanyt(int *tartAlso, int *tartFelso, int min, int max);

int main(int argc, char *argv[]) {
    int eletkorok[] = {19, 25, 20, 21, 22, 21, 24, 19, 26, 25};
    const int ELEMSZAM = sizeof(eletkorok) / sizeof(int);
    kiirEgeszTomb(eletkorok, ELEMSZAM);
    int also;
    int felso;
    beolvasTartomanyt(&also, &felso, MINELETKOR, MAXELETKOR);
    printf("A tartomany: %d - %d\n", also, felso);

    return 0;
}

void kiirEgeszTomb(int tomb[], int elemszam) {
    //Tomb parameter eseten masik parameter mindig a tomb elemszama!!!
    printf("A tomb elemei:\n");
    for (int i = 0; i < elemszam; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");

}

void beolvasTartomanyt(int *tartAlso, int *tartFelso, int min, int max) {
    do {
        *tartAlso = beolvasEgeszIntervallum(min,max);
        *tartFelso = beolvasEgeszIntervallum(min,max);

     } while (*tartAlso >= *tartFelso);
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
}
