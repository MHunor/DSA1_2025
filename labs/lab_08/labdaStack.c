//
// Created by USER on 4/9/2025.
//

#include "labdaStack.h"
#include <stdio.h>
#include <string.h>

// -- Labda függvények --

const char* szinToStr(Szin sz) {
    switch (sz) {
        case PIROS: return "piros";
        case FEHER: return "feher";
        case FEKETE: return "fekete";
        case SARGA: return "sarga";
        case ZOLD: return "zold";
        default: return "ismeretlen";
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
    printf("Atmero: %d cm, Szin: %s, Alairva: %s\n", l->atmero, szinToStr(l->szin), l->alaIrva ? "igen" : "nem");
}

// -- Stack kezelés --

void init_stack(Stack* s) {
    s->teteje = -1;
}

int ures(const Stack* s) {
    return s->teteje == -1;
}

int tele(const Stack* s) {
    return s->teteje == MAX_STACK - 1;
}

int betesz(Stack* s, Labda l) {
    if (tele(s)) return 0;
    s->elemek[++s->teteje] = l;
    return 1;
}

int kivesz(Stack* s, Labda* l) {
    if (ures(s)) return 0;
    *l = s->elemek[s->teteje--];
    return 1;
}

int teteje_alairt(const Stack* s) {
    if (ures(s)) return 0;
    return s->elemek[s->teteje].alaIrva;
}

int teteje_atmero(const Stack* s) {
    if (ures(s)) return -1;
    return s->elemek[s->teteje].atmero;
}

int alairt_db(const Stack* s) {
    int db = 0;
    for (int i = 0; i <= s->teteje; ++i)
        if (s->elemek[i].alaIrva) db++;
    return db;
}

int labdak_szama(const Stack* s) {
    return s->teteje + 1;
}
