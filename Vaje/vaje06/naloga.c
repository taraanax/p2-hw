
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
    
    //za dolzino dobit
    int dolzina = 0;
    while (niz[dolzina] != '\0' && niz[dolzina] != znak) {
        dolzina++;
    }

    //nova tabela
    char* p = malloc((dolzina + 1) * sizeof(char));
    
    
    for (int i = 0; i < dolzina; i++) {
        p[i] = niz[i];
    }
    p[dolzina] = '\0';

    return p;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    //stOdsekov
    int count = 1;
    for (int i = 0; niz[i] != '\0'; i++) {
        if (niz[i] == locilo) {
            count++;
        }
    }
    *stOdsekov = count;

    char** tabela = malloc(count * sizeof(char*));

    int i = 0;
    while (*niz != '\0') {
        tabela[i] = kopirajDoZnaka(niz, locilo);
        
        //premik naprej
        int len = 0;
        while (niz[len] != '\0' && niz[len] != locilo) {
            len++;
        }
        if (niz[len] == '\0') break;

        niz = &(niz[len + 1]);
        i++;
    }

    return tabela;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
