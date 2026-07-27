
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
    //printf("stElementov: %d\n", stElementov);
    ciljnoStVrstic[0] = stElementov / N;
    if (stElementov % N != 0) ciljnoStVrstic[0] = ciljnoStVrstic[0] + 1;

    int (*resitev)[N] = calloc(*ciljnoStVrstic, sizeof(*resitev));
    //printf("ciljnoStVrstic: %d\n", ciljnoStVrstic[0]);

    int vrst = 0;
    int stolp = 0;
    for (int i = 0; i < izvornoStVrstic; i++) {
        int j = 0;
        while (kazalec[i][j] != 0) {
            resitev[vrst][stolp] = kazalec[i][j];
            stolp++;
            if (stolp == N) {
                stolp = 0;
                vrst++;
            }
            j++;
        }
    }

    return resitev;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
