
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    int nov_N = (N * izvornoStVrstic) / ciljnoStVrstic + 1;

    int** resitev = malloc(ciljnoStVrstic * sizeof(int*));
    
    int k = 0;
    for (int i = 0; i < ciljnoStVrstic; i++) {
        resitev[i] = calloc(nov_N, sizeof(int));
        for (int j = 0; j < nov_N - 1; j++) {
            resitev[i][j] = kazalec[k/N][k%N];
            k++;
       } 
    }
    return resitev;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    int stElementov = 0;

    for (int i = 0; i < izvornoStVrstic; i++) {
        int j = 0;
        while (kazalec[i][j] != 0) {
            stElementov++;
            j++;
        }
    }
    printf("max indeks elementov: %d\n", stElementov);

    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
