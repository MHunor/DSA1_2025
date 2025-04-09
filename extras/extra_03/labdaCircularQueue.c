//
// Created by USER on 4/9/2025.
//
#include "labdaCircularQueue.h"

// Segédfüggvények implementációi
void polc_inicializal(Polc* polc) {
    polc->eleje = 0;
    polc->vege = 0;
    polc->meret = 0;
}

bool polc_telt(Polc* polc) {
    return polc->meret == 20;
}

bool polc_ures(Polc* polc) {
    return polc->meret == 0;
}

void polc_betesz(Polc* polc, Labda labda) {
    if (!polc_telt(polc)) {
        polc->labdak[polc->vege] = labda;
        polc->vege = (polc->vege + 1) % 20;
        polc->meret++;
    }
}

Labda polc_kivesz(Polc* polc) {
    Labda ures = {0, PIROS, false};
    if (!polc_ures(polc)) {
        Labda labda = polc->labdak[polc->eleje];
        polc->eleje = (polc->eleje + 1) % 20;
        polc->meret--;
        return labda;
    }
    return ures;
}

Labda labda_beolvas(FILE* fp) {
    Labda labda;
    int szin;
    int alairt;
    fscanf(fp, "%u %d %d", &labda.atmero, &szin, &alairt);
    labda.szin = (Szin)szin;
    labda.alairt = (bool)alairt;
    return labda;
}

void labda_kiir(Labda labda) {
    printf("Atmero: %u, Szin: %s, Alairt: %s\n",
           labda.atmero,
           szin_to_string(labda.szin),
           labda.alairt ? "igen" : "nem");
}

const char* szin_to_string(Szin szin) {
    switch (szin) {
        case PIROS: return "piros";
        case FEHER: return "feher";
        case FEKETE: return "fekete";
        case SARGA: return "sarga";
        case ZOLD: return "zold";
        case KEK: return "kek";
        default: return "ismeretlen";
    }
}