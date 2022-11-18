#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALSOHATAR 10
#define FELSOHATAR 100
#define TOMB_ELEMSZAMA 10

int egeszVeletlenSzam(int also, int felso);
void kiirEgeszTomb(int tomb[], int elemszam);
int legkisebbElem(int tomb[], int elemszam);

int main(int argc, char *argv[]) {
    int veletlenSzamok[TOMB_ELEMSZAMA];
    //Velelenszam genrator inicializalasa
    //A time(NULL) a rendszeridot adja vissza egesz szankent,
  kiirEgeszTomb(szamok, SZAMOKDB);  //tehat minden futaskor mas az erteke
    srand(time(NULL));

    for (int i = 0; i < TOMB_ELEMSZAMA; i++) {
        veletlenSzamok[i] = egeszVeletlenSzam(ALSOHATAR, FELSOHATAR);
    }

    kiirEgeszTomb(veletlenSzamok, TOMB_ELEMSZAMA);

    int minInd = legkisebbElem(veletlenSzamok, TOMB_ELEMSZAMA);
    printf("A tombb legkisebb elemenek indexe: %d, erteke: %d\n", minInd,  veletlenSzamok[minInd]);

    return 0;
}

int egeszVeletlenSzam(int also, int felso)
{
    // Veletleszam generalas az [also,felso] intervallumban
    return rand() % (felso-also+1) + also;
}

void kiirEgeszTomb(int tomb[], int elemszam) {
    //Tomb parameter eseten masik parameter mindig a tomb elemszama!!!
    printf("A tomb elemei:\n");
    for (int i = 0; i < elemszam; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");

}

int legkisebbElem(int tomb[], int elemszam) {
    //A tomb legkisebb elemenek indexet adja vissza
    //Feltetelezzuk, hogy az elso elem a legkisebb
    int minIndex = 0;
    int minimum = tomb[0];
    for (int i = 1; i < elemszam; i++) {
        if (tomb[i] < tomb[minIndex]) {
            //Talaltunk az eddiginel kisebb elemet, ez lesz az uj minimum
            minIndex = i;
            minimum = tomb[i];
        }
    }
    return minIndex;
}


