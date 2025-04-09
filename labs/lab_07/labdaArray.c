//
// Created by USER on 4/9/2025.
//

#include "labdaArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ---- Labda függvények ----

const char* szinToStr(Szin sz) {
    switch (sz) {
        case PIROS: return "piros";
        case FEHER: return "feher";
        case FEKETE: return "fekete";
        case SARGA: return "sarga";
        case ZOLD:  return "zold";
        default:    return "ismeretlen";
    }
}

Szin strToSzin(const char* str) {
    if (strcmp(str, "piros") == 0) return PIROS;
    if (strcmp(str, "feher") == 0) return FEHER;
    if (strcmp(str, "fekete") == 0) return FEKETE;
    if (strcmp(str, "sarga") == 0) return SARGA;
    if (strcmp(str, "zold") == 0) return ZOLD;
    return ISMERETLEN;
}

int beolvas_labda_fajlbol(FILE* fp, Labda* l) {
    char szin_str[20];
    int alaIrva;
    if (fscanf(fp, "%d %s %d", &l->atmero, szin_str, &alaIrva) == 3) {
        l->szin = strToSzin(szin_str);
        l->alaIrva = alaIrva;
        return 1;
    }
    return 0;
}

void kiir_labda(const Labda* l) {
    printf("Átmérő: %d cm, Szín: %s, Aláírva: %s\n", l->atmero, szinToStr(l->szin), l->alaIrva ? "igen" : "nem");
}

// ---- Polc kezelés ----

Labda polc[MAX_LABDA];
int polc_meret = 0;

void beszur_labda(int pozicio, Labda l) {
    if (polc_meret >= MAX_LABDA || pozicio < 0 || pozicio > polc_meret) return;

    for (int i = polc_meret; i > pozicio; --i)
        polc[i] = polc[i - 1];
    polc[pozicio] = l;
    polc_meret++;
}

void kiir_polc() {
    printf("\nPolc tartalma (%d labda):\n", polc_meret);
    for (int i = 0; i < polc_meret; ++i) {
        printf("%2d. ", i + 1);
        kiir_labda(&polc[i]);
    }
}

void eltavolit_nagy_labdakat() {
    for (int i = 0; i < polc_meret; ) {
        if (polc[i].atmero > 15) {
            for (int j = i; j < polc_meret - 1; ++j)
                polc[j] = polc[j + 1];
            polc_meret--;
        } else {
            i++;
        }
    }
}

int megszamlal_alairt_labdakat() {
    int db = 0;
    for (int i = 0; i < polc_meret; ++i)
        if (polc[i].alaIrva) db++;
    return db;
}

int compare_labdak(const void* a, const void* b) {
    Labda* l1 = (Labda*)a;
    Labda* l2 = (Labda*)b;
    return l1->atmero - l2->atmero;
}

void rendezes_atmero_szerint() {
    qsort(polc, polc_meret, sizeof(Labda), compare_labdak);
}