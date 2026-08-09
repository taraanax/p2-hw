
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    if (k == 1) return zacetek;

    int i = k - 1;
    while(zacetek->naslednje != NULL) {

        i += k;
    }
    
    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
