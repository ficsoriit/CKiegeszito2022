#include <stdio.h>
#include <stdbool.h>

#define SZAMOKDB 5
#define ALSO 1
#define FELSO 90

void beolvasLottoSzamot(int szamok[], int szamokDb, int also, int felso);
bool intervallumVizsgalat(int szamok[], int meret, int also, int felso);
void kiirEgeszTomb(int tomb[], int elemszam);

int main(int argc, char *argv[]) {
    int szamok[SZAMOKDB];
    beolvasLottoSzamot(szamok, SZAMOKDB, ALSO, FELSO);
    kiirEgeszTomb(szamok, SZAMOKDB);
    return 0;
}


void beolvasLottoSzamot(int szamok[], int szamokDb, int also, int felso) {
    int szam;
    bool ok;
    char c;
    int beolvasottDb = 0;
    do {
        printf("Adj meg öt egész számot %d és %d között vesszővel elválasztva! ", also, felso); 
        for (int i = 0; i < szamokDb; i++) {
            ok = true;
            if (scanf("%d,", &szam) != 1) {
            // Formai vizsgalat
            printf("Hibás input!\n");
            ok = false;
            // Buffer urites!!!
            while((c=getchar()) != '\n');
            break;
            }
            szamok[i] = szam;
            beolvasottDb++;
        }
        if (beolvasottDb != szamokDb) {
            ok = false;
         } else {
            // Tartalmi vizsgalat
            if (!intervallumVizsgalat(szamok, szamokDb, also, felso)) {
                ok = false; 
            }
            // Buffer urites!!! --Ovatosságból
            while((c=getchar()) != '\n');
         } 
    } while(!ok);
}

bool intervallumVizsgalat(int szamok[], int meret, int also, int felso) {
    for (int i = 0; i < meret; i++) {
        if (szamok[i] < also || szamok[i] > felso) {
            return false;
        }
    }
    return true;
}

void kiirEgeszTomb(int tomb[], int elemszam) {
    //Tomb parameter eseten masik parameter mindig a tomb elemszama!!!
    printf("A tomb elemei:\n");
    for (int i = 0; i < elemszam; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");

}