//
// Created by USER on 4/9/2025.
//

#ifndef DSA1_2025_LABDACIRCULARQUEUE_H
#define DSA1_2025_LABDACIRCULARQUEUE_H
#include <stdbool.h>
#include <stdio.h>

// Labda szín enumeráció
typedef enum {
    PIROS, FEHER, FEKETE, SARGA, ZOLD, KEK
} Szin;

// Labda struktúra
typedef struct {
    unsigned int atmero;
    Szin szin;
    bool alairt;
} Labda;

// Polc struktúra (körkörös sor)
typedef struct {
    Labda labdak[20];
    int eleje;
    int vege;
    int meret;
} Polc;

// Függvénydeklarációk
void polc_inicializal(Polc* polc);
bool polc_telt(Polc* polc);
bool polc_ures(Polc* polc);
void polc_betesz(Polc* polc, Labda labda);
Labda polc_kivesz(Polc* polc);
Labda labda_beolvas(FILE* fp);
void labda_kiir(Labda labda);
const char* szin_to_string(Szin szin);

#endif //DSA1_2025_LABDACIRCULARQUEUE_H
