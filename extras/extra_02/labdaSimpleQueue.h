//
// Created by USER on 4/9/2025.
//

#ifndef DSA1_2025_LABDASIMPLEQUEUE_H
#define DSA1_2025_LABDASIMPLEQUEUE_H
#include <stdbool.h>
#include <stdio.h>

#define MAX 20

typedef enum { PIROS, FEHER, FEKETE, SARGA, ZOLD, KÉK } Szin;

typedef struct {
    int atmero;
    Szin szin;
    bool alairt;
} Labda;

typedef struct {
    Labda tomb[MAX];
    int eleje;
    int vege;
    int meret;
} Queue;

void init_queue(Queue* q);
bool tele(const Queue* q);
bool ures(const Queue* q);
bool betesz(Queue* q, Labda l);
bool kivesz(Queue* q, Labda* l);
void kiir_labda(const Labda* l);
bool beolvas_labda_fajlbol(FILE* fp, Labda* l);
void kiir_queue(const Queue* q, const char* nev);
int szines_db(const Queue* q); // nem fekete/feher
const char* szin_str(Szin s);

#endif //DSA1_2025_LABDASIMPLEQUEUE_H
