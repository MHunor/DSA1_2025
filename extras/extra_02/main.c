#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labdaSimpleQueue.h"

int main() {
    Queue feher, fekete, athelyezett;
    init_queue(&feher);
    init_queue(&fekete);
    init_queue(&athelyezett);

    FILE* fp = fopen("labdak.txt", "r");
    if (!fp) {
        perror("Hiba a fajl megnyitasakor");
        return 1;
    }

    srand(time(NULL));
    Labda l;
    while (beolvas_labda_fajlbol(fp, &l)) {
        if (tele(&feher) && tele(&fekete)) break;

        if (l.szin == FEHER && !tele(&feher)) {
            betesz(&feher, l);
        } else if (l.szin == FEKETE && !tele(&fekete)) {
            betesz(&fekete, l);
        } else {
            int valasztott = rand() % 2;
            Queue* cel = valasztott == 0 ? &feher : &fekete;
            Labda temp;
            if (!ures(cel)) kivesz(cel, &temp);
            if (!tele(cel)) betesz(cel, l);
        }
    }
    fclose(fp);

    kiir_queue(&feher, "Feher");
    kiir_queue(&fekete, "Fekete");

    printf("\nSzines labdak:\n");
    printf("Feher polc: %d db\n", szines_db(&feher));
    printf("Fekete polc: %d db\n", szines_db(&fekete));

    Labda temp;
    printf("\nAthelyezes masik polcra:\n");
    while (kivesz(&feher, &temp)) betesz(&athelyezett, temp);
    while (kivesz(&fekete, &temp)) betesz(&athelyezett, temp);

    kiir_queue(&athelyezett, "Vegso polc");

    return 0;
}
