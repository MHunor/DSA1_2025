//
// Created by USER on 4/9/2025.
//

#ifndef LAB_07_LABDAARRAY_H
#define LAB_07_LABDAARRAY_H

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

// Polc kezelés
#define MAX_LABDA 20

extern Labda polc[MAX_LABDA];
extern int polc_meret;

void beszur_labda(int pozicio, Labda l);
void kiir_polc();
void eltavolit_nagy_labdakat();
int megszamlal_alairt_labdakat();
void rendezes_atmero_szerint();


#endif //LAB_07_LABDAARRAY_H
