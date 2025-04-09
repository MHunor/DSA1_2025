#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include "labdaCircularQueue.h"
#include <time.h>

int main() {
    srand(time(NULL)); // Véletlenszám generátor inicializálása

    // Polcok deklarálása
    Polc feher_polc, fekete_polc, szines_polc;
    polc_inicializal(&feher_polc);
    polc_inicializal(&fekete_polc);
    polc_inicializal(&szines_polc);

    // Fájl beolvasás
    FILE* fp = fopen("labdak.txt", "r");
    if (fp == NULL) {
        printf("Hiba a fajl megnyitasakor!\n");
        return 1;
    }

    // Labdák beolvasása és elhelyezése
    while (!feof(fp) && !polc_telt(&feher_polc) && !polc_telt(&fekete_polc)) {
        Labda uj_labda = labda_beolvas(fp);
        if (uj_labda.szin == FEHER) {
            polc_betesz(&feher_polc, uj_labda);
        } else if (uj_labda.szin == FEKETE) {
            polc_betesz(&fekete_polc, uj_labda);
        } else {
            Polc* cel_polc = (rand() % 2 == 0) ? &feher_polc : &fekete_polc;
            polc_kivesz(cel_polc); // Véletlenszerű polcról kiveszünk
            polc_betesz(cel_polc, uj_labda); // Új labda betétele
        }
    }
    fclose(fp);

    // Polcok tartalmának kiírása
    printf("\nFeher polc tartalma:\n");
    for (int i = 0; i < feher_polc.meret; i++) {
        labda_kiir(feher_polc.labdak[(feher_polc.eleje + i) % 20]);
    }

    printf("\nFekete polc tartalma:\n");
    for (int i = 0; i < fekete_polc.meret; i++) {
        labda_kiir(fekete_polc.labdak[(fekete_polc.eleje + i) % 20]);
    }

    // Színes labdák számlálása
    int feher_polcon_szines = 0, fekete_polcon_szines = 0;
    for (int i = 0; i < feher_polc.meret; i++) {
        Szin szin = feher_polc.labdak[(feher_polc.eleje + i) % 20].szin;
        if (szin != FEHER) feher_polcon_szines++;
    }
    for (int i = 0; i < fekete_polc.meret; i++) {
        Szin szin = fekete_polc.labdak[(fekete_polc.eleje + i) % 20].szin;
        if (szin != FEKETE) fekete_polcon_szines++;
    }
    printf("\nSzines labdak szama - Feher polcon: %d, Fekete polcon: %d\n",
           feher_polcon_szines, fekete_polcon_szines);

    // Polcok ürítése és színes labdák áthelyezése
    while (!polc_ures(&feher_polc)) {
        Labda labda = polc_kivesz(&feher_polc);
        if (labda.szin != FEHER) polc_betesz(&szines_polc, labda);
    }
    while (!polc_ures(&fekete_polc)) {
        Labda labda = polc_kivesz(&fekete_polc);
        if (labda.szin != FEKETE) polc_betesz(&szines_polc, labda);
    }

    // Színes polc kiírása
    printf("\nSzines polc tartalma:\n");
    for (int i = 0; i < szines_polc.meret; i++) {
        labda_kiir(szines_polc.labdak[(szines_polc.eleje + i) % 20]);
    }

    return 0;
}