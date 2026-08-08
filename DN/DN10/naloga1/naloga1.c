
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

int primerjava(const void *a, const void *b);

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    
    VO** opravili = malloc(stStudentov * sizeof(VO*));
    stVO[0] = 0;
    int k = 0;

    for (int i = 0; i < stStudentov; i++) {
        Student* student = studentje[i];
        PO* po = student->po;
        for (int j = 0; j < student->stPO; j++) {
            if(strcmp((po[j]).predmet, predmet) == 0 && (po[j]).ocena > 5) {
                opravili[k] = malloc(sizeof(VO));
                (opravili[k])->vpisna = student->vpisna;
                (opravili[k])->ocena = (po[j]).ocena;
                k++;
            }
        }
    }

    stVO[0] = k;

    //sortiranje
    VO** urejeno = malloc(k * sizeof(VO*));
    for (int i = 0; i < k; i++) {
        urejeno[i] = malloc(sizeof(VO));
        urejeno[i] = opravili[i];
    }

    qsort(urejeno, k, sizeof(VO), primerjava);

    return urejeno;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif

int primerjava(const void *a, const void *b) {
    VO* x = *(VO **)a;
    VO* y = *(VO **)b;

    if(x->ocena > y->ocena) return -1;
    else if(x->ocena < y->ocena) return 1;
    else {
        if(x->vpisna < y->vpisna) return -1;
        else if(x->vpisna > y->vpisna) return 1;
    }
    return 0;
}