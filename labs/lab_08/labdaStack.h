//
// Created by USER on 4/9/2025.
//

#ifndef LAB_07_LABDASTACK_H
#define LAB_07_LABDASTACK_H

#include <stdio.h>

typedef enum {
    PIROS,
    FEHER,
    FEKETE,
    SARGA,
    ZOLD,
    ISMERETLEN
} Szin;

typedef struct {
    int atmero;
    Szin szin;
    int alaIrva;
} Labda;

const char* szinToStr(Szin sz);
Szin strToSzin(const char* str);
int beolvas_labda_fajlbol(FILE* fp, Labda* l);
void kiir_labda(const Labda* l);

// Stack kezelés
#define MAX_STACK 20

typedef struct {
    Labda elemek[MAX_STACK];
    int teteje;
} Stack;

void init_stack(Stack* s);
int ures(const Stack* s);
int tele(const Stack* s);
int betesz(Stack* s, Labda l);
int kivesz(Stack* s, Labda* l);
int teteje_alairt(const Stack* s);
int teteje_atmero(const Stack* s);
int alairt_db(const Stack* s);
int labdak_szama(const Stack* s);

#endif //LAB_07_LABDASTACK_H
