#include <stdio.h>
#include <stdbool.h>
void beolvasKetSzamot(int* egyik, int* masik);
int nagyobbSzam();

int main(int argc, char const *argv[])
{
    /* code */
    int egyikSzam;
    int masikSzam;
    beolvasKetSzamot(&egyikSzam, &masikSzam);
    printf("A beolvasott szamok: %d,%d\n", egyikSzam, masikSzam);
    /*
    int nagyobb = nagyobbSzam();
    printf("A nagyobb szam: %d\n", nagyobb);
    printf("Mégegszer: A nagyobb szam: %d\n", nagyobbSzam());
*/
    return 0;
}

void beolvasKetSzamot(int* egyik, int* masik) {
    bool ok;
    char c;
    do {
        ok = true;
        printf("Adj meg két egész számot vesszővel elválasztva! ");
        if (scanf("%d,%d", egyik, masik) != 2) {
            printf("Hibás input!\n");
            ok = false;
            // Buffer urites!!!
            while((c=getchar()) != '\n');
         }   
    } while(!ok);

 printf("Teszt kiírás: A beolvasott szamok: %d,%d\n", *egyik, *masik);
 printf("Teszt kiírás: A beolvasott szamok: %d,%d\n", *egyik+10, *masik=*egyik);
}

int nagyobbSzam() {
    int egyik;
    int masik;
    beolvasKetSzamot(&egyik, &masik);
    if (egyik>=masik) {
        return egyik;
    }
    return masik;
}

