#include <stdio.h>
#include "labdaStack.h"

int main() {
    Stack piros, feher, egyeb;
    init_stack(&piros);
    init_stack(&feher);
    init_stack(&egyeb);

    FILE* fp = fopen("labdak.txt", "r");
    if (!fp) {
        perror("Hiba a fajl megnyitasakor");
        return 1;
    }

    Labda l;
    while (beolvas_labda_fajlbol(fp, &l)) {
        if (l.szin == PIROS) {
            betesz(&piros, l);
        } else if (l.szin == FEHER) {
            betesz(&feher, l);
        } else {
            betesz(&egyeb, l);
        }
    }
    fclose(fp);

    printf("Alairt labdak szama:\n");
    printf("Piros lada: %d db\n", alairt_db(&piros));
    printf("Feher lada: %d db\n", alairt_db(&feher));
    printf("Egyeb lada: %d db\n", alairt_db(&egyeb));

    int max_piros = teteje_atmero(&piros);
    int max_feher = teteje_atmero(&feher);
    int max_egyeb = teteje_atmero(&egyeb);

    printf("\nTetejen levo labdak atmeroje:\n");
    printf("Piros: %d\n", max_piros);
    printf("Feher: %d\n", max_feher);
    printf("Egyeb: %d\n", max_egyeb);

    // Eltavolitas, amig tetejen nem lesz alairt labda vagy ures
    int kivett_piros = 0, kivett_feher = 0, kivett_egyeb = 0;
    Labda temp;

    while (!ures(&piros) && !teteje_alairt(&piros)) {
        kivesz(&piros, &temp);
        kivett_piros++;
    }

    while (!ures(&feher) && !teteje_alairt(&feher)) {
        kivesz(&feher, &temp);
        kivett_feher++;
    }

    while (!ures(&egyeb) && !teteje_alairt(&egyeb)) {
        kivesz(&egyeb, &temp);
        kivett_egyeb++;
    }

    printf("\nEltavolitas utan:\n");
    printf("Piros ladaban maradt: %d db, kivett: %d db\n", labdak_szama(&piros), kivett_piros);
    printf("Feher ladaban maradt: %d db, kivett: %d db\n", labdak_szama(&feher), kivett_feher);
    printf("Egyeb ladaban maradt: %d db, kivett: %d db\n", labdak_szama(&egyeb), kivett_egyeb);

    return 0;
}
/*
Gyakorló feladat
(1 pont) Készíts típus definíciót egy labdáról. Egy labdáról a következő információkat tudjuk:
labda átmérője (természetes szám), labda színe (enum: piros, fehér, fekete, sárga stb.), alá
van-e írva (igaz/hamis érték). Írd meg a következő műveleteket egy labdára vonatkozóan:
• (1 pont) Egy labda adatainak beolvasása
• (1 pont) Egy labda adatainak kiírása
A vásárhelyi sportcsarnokban egy maximum 20 kapacitású oszlopszerű ládába helyezhetünk
el labdákat. A labdákat mindig a polc tetejére tudjuk bedobni, illetve, ha ki szeretnénk venni,
akkor mindig csak a legfelsőt érjük el. Alkalmazva a fenti szabályokat valósítsd meg a
következőket:
• (1.5 pont) Olvassunk be állományból labdákat (állomány végjelig vagy max
kapacitásig).
• (1 pont) Készítsünk elő három külön ládát: egyet a piros labdáknak, egyet a
fehéreknek és egyet a többi színű labdának. A beolvasott labdákat ennek megfelelően
helyezzük el a ládákban.
• (1 pont) Hány aláírt labda került külön-külön a három ládába?
• (1 pont) Melyik láda tetején van a legnagyobb átmérőjű labda?
• (1.5 pont) Vegyünk ki addig labdákat mindhárom ládából, amíg mindenik láda tetején
aláírt labda lesz, vagy üresek nem lesznek a ládák. Mennyi labda maradt külön-külön
a három ládában, illetve hányat vettünk ki az egyes ládákból?
A program megírása során használj az adott adatszerkezetnek megfelelő függvényeket.
Emellett, strukturáld a programodat ízlésesen, legyen a megoldásod átlátható, használj
segédfüggvényeket. */