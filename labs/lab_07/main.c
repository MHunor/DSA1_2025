#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labdaArray.h"

int main() {
    srand((unsigned)time(NULL));

    FILE* fp = fopen("labdak.txt", "r");
    if (!fp) {
        perror("Hiba a fajl megnyitasa kozben");
        return 1;
    }

    Labda l;
    while (polc_meret < MAX_LABDA && beolvas_labda_fajlbol(fp, &l)) {
        if (l.szin == PIROS) {
            beszur_labda(0, l);
        } else if (l.szin == FEHER) {
            beszur_labda(polc_meret, l);
        } else {
            int veletlen_poz = rand() % (polc_meret + 1);
            beszur_labda(veletlen_poz, l);
        }
    }

    fclose(fp);

    printf("Feltöltés után:");
    kiir_polc();

    eltavolit_nagy_labdakat();
    printf("\n15 cm-nél nagyobb labdák eltávolítása után:");
    kiir_polc();

    int alairtak = megszamlal_alairt_labdakat();
    printf("\nAláírt labdák száma: %d db\n", alairtak);

    rendezes_atmero_szerint();
    printf("\nRendezés átmérő szerint:");
    kiir_polc();

    return 0;
}

/*
Gyakorló feladat
(1 pont) Készíts típus definíciót egy labdáról. Egy labdáról a következő információkat tudjuk:
labda átmérője (természetes szám), labda színe (enum: piros, fehér, fekete, sárga stb.), alá
van-e írva (igaz/hamis érték). Írd meg a következő műveleteket egy labdára vonatkozóan:
• (1 pont) Egy labda adatainak beolvasása
• (1 pont) Egy labda adatainak kiírása
A vásárhelyi sportcsarnokban egy maximum 20 kapacitású polcon helyezhetünk el labdákat.
A labdákat feltehetjük a polc elejére, végére és belső helyeire is. Csak egy szabály van: a
labdák közvetlenül egymás után helyezkedjenek el (ne legyenek „lyukak”, üres helyek a
labdák között). A polcról bármelyik helyről elvehetünk labdát, csupán arra kell vigyázni,
hogy mindig töltsük be a keletkezett réseket. Alkalmazva a fenti szabályokat valósítsd meg a
következőket:
• (1 pont) Olvassunk be állományból labdákat (állomány végjelig vagy max
kapacitásig).
• (1 pont) A piros labdákat mindig a polc elejére, a fehéreket a polc végére tegyük.
Minden más színű labdát a lehetséges pozíciók közül egy véletlenszerű pozícióra
helyezzünk.
• (1 pont) Írd ki a feltöltést követően a polc tartalmát.
• (0.5 pont) Vegyük le a polcról a 15 cm átmérőnél nagyobb labdákat, majd ismét írjuk
ki a polc tartalmát.
• (0.5 pont) Számoljuk meg, hogy hány olyan labda van jelenleg a polcon, amely alá
van írva.
• (2 pont) Rendezzük a polcon található labdákat átmérő szerint növekvő sorrendbe,
majd írjuk ki az polc aktuális állapotát.
A program megírása során használj az adott adatszerkezetnek megfelelő függvényeket.
Emellett, strukturáld a programodat ízlésesen, legyen a megoldásod átlátható, használj
segédfüggvényeket.
*/
