
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int vsota = 0;
    
    for (int* p = zac; p <= kon; p++) {
        vsota = vsota + *p;
    }
    
    return vsota;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    
    if (*indeks == -1) {
        *indeks = (*kazalec - t);
    } else {
        *kazalec = &(t[*indeks]);
    }

}

void frekvenceCrk(char* niz, int** frekvence) {
    
    *frekvence = (int*)calloc(26, sizeof(int)); //tabela črk

}

#ifndef test

int main() {
    


    return 0;
}

#endif
