
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
    // dopolnite ...
}

#ifndef test

int main() {
    return 0;
}

#endif
