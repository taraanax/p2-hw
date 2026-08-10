
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int izpisiA(A* a, char* cilj);
int izpisiB(B* b, char* cilj);
int izpisiC(C* c, char* cilj);

int izpisiA(A* a, char* cilj) {
    
    if (a == NULL) strcat(cilj, "NULL");
    else {
        sprintf(cilj + strlen(cilj), "{%d, ", a->p);
        izpisiB(a->b, cilj);
        strcat(cilj, "}");
    }
    

    return strlen(cilj);
}

int izpisiB(B* b, char* cilj) {
    
    if (b == NULL) strcat(cilj, "NULL");
    else {
        sprintf(cilj + strlen(cilj), "{%s, ", b->q);
        izpisiC(b->c, cilj);
        strcat(cilj, "}");
    }
    
    return strlen(cilj);
}

int izpisiC(C* c, char* cilj) {
    
    if (c == NULL) strcat(cilj, "NULL");
    else {

        if (c->r) strcat(cilj, "{true, ");
        else strcat(cilj, "{false, ");

        izpisiA(c->a, cilj);
        strcat(cilj, ", ");
        
        izpisiB(c->b, cilj);
        strcat(cilj, "}");
    }

    return strlen(cilj);
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
