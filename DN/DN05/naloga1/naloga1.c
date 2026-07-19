
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    
    //leva nicla
    int i = 0;
    while (t[i] != 0) {
        i--;
        printf("\n i: %d | t[i] : %d", i, t[i]);
    }

    //desna nicla
    int j = 0;
    while (t[j] != 0) {
        j++;
        printf("\n j: %d | t[j] : %d", j, t[j]);
    }
    dolzina[0] = abs(i) + abs(j) - 1;
    printf("\n");

    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
