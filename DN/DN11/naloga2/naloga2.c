
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int izpisiC(C* c, char* cilj);
int izpisiB(B* b, char* cilj);
int izpisiC(C* c, char* cilj);

int izpisiA(A* a, char* cilj) {
    
    if (a == NULL) printf("NULL");
    else {
        printf("%d ,", a->p);
        izpisiB(a->b, cilj);
    }
    

    return strlen(cilj);
}

int izpisiB(B* b, char* cilj) {
    
    if (b == NULL) printf("NULL");
    else {
        printf("%s ,", b->q);
        izpisiC(b->c, cilj);
    }
    
    return strlen(cilj);
}

int izpisiC(C* c, char* cilj) {
    
    if (c == NULL) printf("NULL");
    else {
        if (c->r) {
            printf("true");
            izpisiA(c->a, cilj);
            izpisiB(c->b, cilj);
        } else {
            printf("false");
            izpisiA(c->a, cilj);
            izpisiB(c->b, cilj);
        }
    }

    return strlen(cilj);
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
