
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    
    int count = 0;
    for (int i = 0; niz[i] != '\0'; i++) {
        if (niz[i] == znak) count++;
    }

    return count;
}

char* kopirajDoZnaka(char* niz, char znak) {
    
    
    
    return NULL;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    // popravite / dopolnite ...
    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
