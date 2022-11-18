#include <stdio.h>
#include <stdbool.h>

#define SZAMOKDB 5
#define ALSO 1
#define FELSO 90

void beolvasLottoSzamot(int szamok[], int szamokDb, int also, int felso);
bool intervallumVizsgalat(int szamok[], int meret, int also, int felso);
void kiirEgeszTomb(int tomb[], int elemszam);
bool ismetlodikE(int szamok[], int meret);
void rendezNovekvobe(int tomb[], int elemszam);

int main(int argc, char *argv[]) {
    int szamok[SZAMOKDB];
    beolvasLottoSzamot(szamok, SZAMOKDB, ALSO, FELSO);
    kiirEgeszTomb(szamok, SZAMOKDB);
    rendezNovekvobe(szamok, SZAMOKDB);
    printf("A számok növekvő számsorrendben:\n");
    kiirEgeszTomb(szamok, SZAMOKDB);
    return 0;
}


void beolvasLottoSzamot(int szamok[], int szamokDb, int also, int felso) {
    int szam;
    bool ok;
    char c;
    int beolvasottDb = 0;
    do {
        printf("Adj meg öt egész számot %d és %d között egyenként külön sorban! ", also, felso); 
        beolvasottDb = 0;
        for (int i = 0; i < szamokDb; i++) {
            ok = true;
            if (scanf("%d", &szam) != 1) {
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
            ok = true;
            if (!intervallumVizsgalat(szamok, szamokDb, also, felso)) {
                printf("Nem esik a %d - %d intervallumba\n", also, felso );
                ok = false;
                continue;
            }
            if (ismetlodikE(szamok, szamokDb)) {
                printf("Ismétlődés van!\n");
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

bool ismetlodikE(int szamok[], int meret) {
    for (int i = 0; i < meret-1; i++) {
        for (int j = i+1; j < meret; j++) {
            if (szamok[i] ==  szamok[j]) {
                return true;
            }
        }
    }
    return false;
}

void kiirEgeszTomb(int tomb[], int elemszam) {
    //Tomb parameter eseten masik parameter mindig a tomb elemszama!!!
    printf("A tomb elemei:\n");
    for (int i = 0; i < elemszam; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");

}

void rendezNovekvobe(int tomb[], int elemszam) {
    int minindex = 0;
    int tmp;
    for (int i = 0; i < elemszam-1; i++) {
        // Megkeressuk a tomb maradek elemei kozul a legkisebbet
        // Feltetelezzuk, hogy az akt elem a legkisebb,
        // megjegyezzuk az indexet
        minindex = i;
        for (int j = i+1; j <elemszam; j++) {
            if (tomb[j] < tomb[minindex]) {
                // Talaltunk egy eddigi minimumnal kisebb elemet
                // Atirjuk a minindex-et
                minindex = j;
            }
        // Minimum kereses vege
        // Ha nem az aktualis elem a minimalis, cserélunk
        if (i != minindex) {
            tmp = tomb[i];
            tomb[i] = tomb[minindex];
            tomb[minindex] = tmp;
        }

        }
    }
}
