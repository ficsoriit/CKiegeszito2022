#include <stdio.h>
#include <stdbool.h>

#define HONAPOK_SZAMA 12
#define INDULO_KM 100

void feltolt(int tomb[], int elemek, FILE *input);
void listaz(int tomb[], int elemek);
void futasTeljesitmeny(int km[], int honapok, int futas[]);
bool ellenorzes(int km[], int honapok);
bool ellenorzes1(int km[], int honapok);
void jelentesKeszites(int km[], int honapok, int futas[], FILE *out);
void jelentesKeszites1(int km[], int honapok, int futas[], char* filenev);

int main(int argc, char **argv)
{
    int kmora[HONAPOK_SZAMA];
    FILE *input;
    char filenev[] = "menetlevel.txt";
    if ((input = fopen(filenev, "rt")) == NULL)
    {
        printf("A(z) %s nevűfile megnyitása sikertelem\n", filenev);
        return 1;
    }

    feltolt(kmora, HONAPOK_SZAMA, input);
    fclose(input);

    listaz(kmora, HONAPOK_SZAMA);

    int futastelj[HONAPOK_SZAMA];
    futasTeljesitmeny(kmora, HONAPOK_SZAMA, futastelj);
    listaz(futastelj, HONAPOK_SZAMA);

    bool helyesE = ellenorzes(kmora, HONAPOK_SZAMA);
    printf("Ellenorzes eredmenye: %d\n", helyesE);
    printf("Ellenorzes eredmenye: %s\n", helyesE ? "Helyes" : "Helytelen");
    printf("Ellenorzes eredmenye: %s\n", ellenorzes(kmora, HONAPOK_SZAMA) ? "Helyes" : "Helytelen");

    FILE *output = fopen("jelentes.txt", "wt");
    jelentesKeszites(kmora, HONAPOK_SZAMA, futastelj, output);
    fclose(output);

    jelentesKeszites1(kmora, HONAPOK_SZAMA, futastelj, "masikJelentes.txt");
}

void feltolt(int tomb[], int elemek, FILE *input)
{
    for (int i = 0; i < elemek; i++)
    {
        // fscanf(input, "%d", &tomb[i]); - ez is jo
        fscanf(input, "%d", tomb++);
        // int km[], int honapok/fscanf(input, "%d", tomb+i); ez is jo!
    }
}

void listaz(int tomb[], int elemek)
{
    for (int i = 0; i < elemek; i++)
    {
        printf("%d\t", tomb[i]); // EZ az ugyesebb
        // printf("%d\t", *(tomb+i)); De igy is lehetne irni
    }
    printf("\n");
}

void futasTeljesitmeny(int km[], int honapok, int futas[])
{
    futas[0] = km[0] - INDULO_KM;
    for (int i = 1; i < honapok; i++)
    {
        futas[i] = km[i] - km[i - 1];
    }
}

bool ellenorzes(int km[], int honapok)
{
    int jo = true; // Feltetelezzuk, hogy jo
    for (int i = 1; i < honapok; i++)
    {
        if (km[i] < km[i - 1])
        {
            jo = false; // Talaltunk egy hibat, kar is tovabb vizsgalodni
            break;
        }
    }
    return jo;
}

bool ellenorzes1(int km[], int honapok)
{
    for (int i = 1; i < honapok; i++)
    {
        if (km[i] < km[i - 1])
        {
            return false;
        }
    }
    return true;
}

void jelentesKeszites(int km[], int honapok, int futas[], FILE *out)
{
    fprintf(out, "Honap\tkm óra\tFutas\n");
    for (int i = 0; i < honapok; i++)
    {
        fprintf(out, "%d\t%d\t%d\n", i + 1, km[i], futas[i]);
    }
    fflush(out);
}

void jelentesKeszites1(int km[], int honapok, int futas[], char* filenev)
{
    FILE* out = fopen(filenev, "wt");
    fprintf(out, "Honap\tkm óra\tFutas\n");
    for (int i = 0; i < honapok; i++)
    {
        fprintf(out, "%d\t%d\t%d\n", i + 1, km[i], futas[i]);
    }
    fflush(out);
    fclose(out);
}
