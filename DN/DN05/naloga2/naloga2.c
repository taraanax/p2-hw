
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>

#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    int* temp = a[0];
    a[0] = b[0];
    b[0] = temp;
}

void uredi(int** a, int** b, int** c) {
    int* temp;
   
    if (b[0][0] > c[0][0]) {
        temp = c[0];
        c[0] = b[0];
        b[0] = temp;
    }
    if (a[0][0] > c[0][0]) {
        temp = c[0];
        c[0] = a[0];
        a[0] = temp;
    }
    if (a[0][0] > b[0][0]) {
        temp = b[0];
        b[0] = a[0];
        a[0] = temp;
    }
}


#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
