#include <stdio.h>

int bermentesitesDija(double csomagSuly);
void feltolt(double csomagokSulya[], int dijak[], int  csomagokSzama);
void csonagLista(double csomagokSulya[],  int dijak[], int  csomagokSzama);
int bevetel(int dijak[], int  csomagokSzama);
int tulsulyosCsomagok(int dijak[], int  csomagokSzama);
void legkisebbLegnagyobb(double csomagokSulya[], int dijak[], int  csomagokSzama, int* minInd, int* maxmaxInd);

int main(int argc, char *argv[]) {
    double csomagokSulya[] = {1.5,3.6,12.4,6.5,28.0,5.5,32.1,4.5,7.3,15.3};
    const int csomagokSzama = sizeof(csomagokSulya)/sizeof(double);
    int dijak[csomagokSzama];
    feltolt(csomagokSulya, dijak, csomagokSzama);
    csonagLista(csomagokSulya, dijak, csomagokSzama);
    printf("Bevétel: %d\n", bevetel(dijak, csomagokSzama));
    printf("Túlsúlyos csomagok száma: %d\n", tulsulyosCsomagok(dijak, csomagokSzama));
    int legkisebb;
    int legnagyobb;
    legkisebbLegnagyobb(csomagokSulya, dijak, csomagokSzama, &legkisebb, &legnagyobb);
    printf("A legkönnyebb csomag súlya: %lf\n", csomagokSulya[legkisebb-1]);
    printf("A legnehezebb csomag súlya: %lf\n", csomagokSulya[legnagyobb-1]);
}

int bermentesitesDija(double csomagSuly) {
    if (csomagSuly <= 2) return 1630;
    if (csomagSuly <= 5) return 1850;
    if (csomagSuly <= 10) return 1960;
    if (csomagSuly <= 20) return 2180;
    return 0;
}

void feltolt(double csomagokSulya[], int dijak[], int  csomagokSzama) {
    for (int i = 0; i < csomagokSzama; i++) {
        dijak[i] = bermentesitesDija(csomagokSulya[i]);
    }
}

void csonagLista(double csomagokSulya[],  int dijak[], int  csomagokSzama) {
    for (int i = 0; i < csomagokSzama; i++) {
        if (dijak[i] != 0) {
            printf("Sorszam: %d súly: %lf Díj: %d\n", i+1, csomagokSulya[i], dijak[i]);
        }
    }      
}

int bevetel(int dijak[], int  csomagokSzama) {
    int bev = 0;
    for (int i = 0; i < csomagokSzama; i++) {
        bev += dijak[i];
    }
    return bev;
}

int tulsulyosCsomagok(int dijak[], int  csomagokSzama) {
    int db;
      for (int i = 0; i < csomagokSzama; i++) {
        if (dijak[i] ==0) db++;
    }
    return db;
}

void legkisebbLegnagyobb(double csomagokSulya[], int dijak[], int  csomagokSzama, int* minInd, int* maxInd) {
    // Figyelem!!
    // A fuggveny nem ad korrekt erteket, ha egyetlen felvett csomag sincs!!
    int minIndex =0;
    int maxIndex = 0;
    for (int i = 1; i <csomagokSzama; i++) {
        if (dijak[i] != 0 && csomagokSulya[i] < csomagokSulya[minIndex]) minIndex =i;
        if (dijak[i] != 0 && csomagokSulya[i] > csomagokSulya[maxIndex]) maxIndex =i;
    }
    *minInd = minIndex+1;
    *maxInd = maxIndex+1;
}



