//
// Created by USER on 4/9/2025.
//

#include "labdaSimpleQueue.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(Queue* q) {
    q->eleje = 0;
    q->vege = 0;
    q->meret = 0;
}

bool tele(const Queue* q) {
    return q->meret == MAX;
}

bool ures(const Queue* q) {
    return q->meret == 0;
}

bool betesz(Queue* q, Labda l) {
    if (tele(q)) return false;
    q->tomb[q->vege++] = l;
    q->meret++;
    return true;
}

bool kivesz(Queue* q, Labda* l) {
    if (ures(q)) return false;
    *l = q->tomb[q->eleje++];
    q->meret--;
    return true;
}

bool beolvas_labda_fajlbol(FILE* fp, Labda* l) {
    int szinint, alairtint;
    if (fscanf(fp, "%d %d %d", &l->atmero, &szinint, &alairtint) != 3) return false;
    l->szin = (Szin)szinint;
    l->alairt = alairtint;
    return true;
}

void kiir_labda(const Labda* l) {
    printf("Atmero: %d, Szin: %s, Alairt: %s\n", l->atmero, szin_str(l->szin), l->alairt ? "true" : "false");
}

void kiir_queue(const Queue* q, const char* nev) {
    printf("%s polc tartalma:\n", nev);
    for (int i = q->eleje; i < q->vege; i++) {
        printf("%d. ", i - q->eleje + 1);
        kiir_labda(&q->tomb[i]);
    }
}

int szines_db(const Queue* q) {
    int db = 0;
    for (int i = q->eleje; i < q->vege; i++) {
        if (q->tomb[i].szin != PIROS && q->tomb[i].szin != FEHER && q->tomb[i].szin != FEKETE)
            db++;
    }
    return db;
}

const char* szin_str(Szin s) {
    switch (s) {
        case PIROS: return "piros";
        case FEHER: return "feher";
        case FEKETE: return "fekete";
        case SARGA: return "sarga";
        case ZOLD: return "zold";
        case KÉK: return "kek";
        default: return "ismeretlen";
    }
}
