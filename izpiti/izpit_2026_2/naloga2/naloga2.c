
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -Dtest testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 *
 * 01--05: samo sodi elementi
 * 01, 02, 03, 06, 07: ro"cno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// po potrebi dopolnite ...

void razdeli(Vozlisce* vhod, Vozlisce** sodi, Vozlisce** lihi) {

    Vozlisce* sodRep = NULL;
    Vozlisce* lihRep = NULL;

    Vozlisce* curr = vhod;

    while (curr != NULL) {

        Vozlisce* nov = malloc(sizeof(Vozlisce));
        nov->x = curr->x;
        nov->nasl = NULL;
        
        if (curr->x % 2 == 0) {
            
            if(sodi[0] == NULL) {
                sodi[0] = nov;
                sodRep = sodi[0];
            } else {
                sodRep->nasl = nov;
                sodRep = sodRep->nasl;
            }
        } else {

            if(lihi[0] == NULL) {
                lihi[0] = nov;
                lihRep = lihi[0];
            } else {
                lihRep->nasl = nov;
                lihRep = lihRep->nasl;
            }
        }

        curr = curr->nasl;
    }

    return;
}

#ifndef test

int main() {
    return 0;
}

#endif
