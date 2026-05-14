
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    int vsota = 0;

    while (zacetek != NULL) {
        vsota = vsota + zacetek->podatek;
        zacetek = zacetek->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL) return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;
    novo->naslednje = NULL;

    if (zacetek == NULL || element < zacetek->podatek){
        novo->naslednje = zacetek;
        return novo;
    }
    
    Vozlisce* max = zacetek;
    while (max->naslednje != NULL && element > max->naslednje->podatek) {
        //printf("  |test:%d < [%d]|  ", element, max->naslednje->podatek);
        max = max->naslednje;
    }
    novo->naslednje = max->naslednje;
    max->naslednje = novo;
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {

    if (zacetek == NULL || element < zacetek->podatek) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }

    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);

    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
