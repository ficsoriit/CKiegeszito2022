#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MIN_SULY 35
#define MAX_SULY 50
#define MAX_LETSZAM 50

//GyakorlatiVizsga.pdf példája

typedef struct valogatott
{
    double tti[MAX_LETSZAM];
    int elemszam;
} Valogatott; // Ez gyors, de nem túl elegáns negoldás

void sulytFeltolt(double magassag[], int elemszam, int sulyok[]);
int veletlenSzam(int min, int max);
double testTomeg(double magassag, int suly);
void kiirTomb(double tomb[], int elemek);
void rendez(double testTomeg[], int elemszam);
void minositestBeolvas(char *szoveg);
Valogatott valogat(double tti[], int elemszam, char *szoveg);
void kiirTombFileba(double tomb[], int elemek, char* filenev);

int main(int argc, char *argv[])
{
    // A testmagasságok tömböt inicializálja: 1.20, 1.16, 1.52, 1.18, 1.34
    // A testtömegek sorozatát véletlenszám generátorral állítsa elő a 35-50 intervallumban.
    //  Ha külön függvényben oldja meg a tömbfeltöltést.
    double magassag[] = {1.20, 1.16, 1.52, 1.18, 1.34};
    const int elemszam = sizeof(magassag) / sizeof(double);
    // 1. feladat
    int sulyok[elemszam];
    sulytFeltolt(magassag, elemszam, sulyok);
    double testTomegek[elemszam];
    for (int i = 0; i < elemszam; i++)
    {
        testTomegek[i] = testTomeg(magassag[i], sulyok[i]);
    }
    kiirTomb(testTomegek, elemszam);

    // 2 feladat"
    rendez(testTomegek, elemszam);
    // 3. feladat
    kiirTomb(testTomegek, elemszam);

    // 4. feladat
    char minositoSzoveg[10];
    minositestBeolvas(minositoSzoveg);
    printf("Beolvasott szöveg: %s\n", minositoSzoveg);

    //5. feladat
    Valogatott kivalogatott = valogat(testTomegek, elemszam, minositoSzoveg);
    // 6. feladat 1. rész
    kiirTomb(kivalogatott.tti, kivalogatott.elemszam);
    // 36. feladat: file-ba írás
    kiirTombFileba(kivalogatott.tti, kivalogatott.elemszam, "lista.txt");
}

void sulytFeltolt(double magassag[], int elemszam, int sulyok[])
{
    srand(time(NULL));
    for (int i = 0; i < elemszam; i++)
    {
        sulyok[i] = veletlenSzam(MIN_SULY, MAX_SULY);
    }
}

int veletlenSzam(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

double testTomeg(double magassag, int suly)
{
    return suly / (magassag * magassag);
}

void kiirTomb(double tomb[], int elemek)
{
    printf("A tömb elemei:\n");
    for (int i = 0; i < elemek; i++)
    {
        printf("%lf\t", tomb[i]);
    }
    printf("\n");
}

void rendez(double testTomeg[], int elemszam)
{
    int maxindex;
    int tmp;
    for (int i = 0; i < elemszam - 1; i++)
    {
        maxindex = i;
        for (int j = i + 1; j < elemszam; j++)
        {
            if (testTomeg[j] > testTomeg[maxindex])
            {
                maxindex = j;
            }
        }
        if (i != maxindex)
        {
            tmp = testTomeg[i];
            testTomeg[i] = testTomeg[maxindex];
            testTomeg[maxindex] = tmp;
        }
    }
}

void minositestBeolvas(char *szoveg)
{
    bool ok;
    do
    {
        ok = true;
        if (scanf("%s", szoveg) != 1)
        {
            ok = false;
            printf("Hibas adat!\n");
            continue;
        }
        ok = true;
        if (!(strcmp(szoveg, "sovany") == 0 || strcmp(szoveg, "normalis") == 0 || strcmp(szoveg, "elhizott") == 0))
        {
            ok = false;
            printf("Hibas adat!\n");
        }

    } while (!ok);
}

Valogatott valogat(double tti[], int elemszam, char *szoveg)
{
    Valogatott vv;
    int kivalogatottDb = 0;
    for (int i = 0; i < elemszam; i++)
    {
        if (strcmp(szoveg, "sovany") == 0 && tti[i] < 18.5)
        {
            vv.tti[kivalogatottDb] = tti[i];
            kivalogatottDb++;
        }
        else if (strcmp(szoveg, "normalis") == 0 && tti[i] >= 18.5 && tti[i] < 25)
        {
            vv.tti[kivalogatottDb] = tti[i];
            kivalogatottDb++;
        }
        else if (strcmp(szoveg, "elhizott") == 0 && tti[i] > 25.0)
        {
            vv.tti[kivalogatottDb] = tti[i];
            kivalogatottDb++;
        }
    }
    // Ez a sor hányzott a gyakorlaton
    vv.elemszam = kivalogatottDb;
    return vv;
}

void kiirTombFileba(double tomb[], int elemek, char* filenev)
{
    FILE* output = fopen(filenev, "wt");

    fprintf(output, "A tömb elemei:\n");
    for (int i = 0; i < elemek; i++)
    {
        fprintf(output,"%lf\t", tomb[i]);
    }
    fprintf(output,"\n");
    fflush(output);
    fclose(output);
}