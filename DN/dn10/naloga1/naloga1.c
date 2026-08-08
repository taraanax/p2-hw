
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

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
    

    return opravili;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
