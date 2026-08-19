
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -Dtest testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 01--05: ro"cno izdelani
 * 06--14: samodejno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* prevezi(Vozlisce* zacetek) {
    if (zacetek == NULL) return zacetek;
    if (zacetek->nasl == NULL) return zacetek;
    
    Vozlisce* fst = zacetek;
    Vozlisce* snd = zacetek->nasl;
    Vozlisce* trd = zacetek->nasl->nasl;


    zacetek = snd;
    zacetek->nasl = fst;
    zacetek->nasl->nasl = prevezi(trd);

    return zacetek;
}

#ifndef test

int main() {
    return 0;
}

#endif
