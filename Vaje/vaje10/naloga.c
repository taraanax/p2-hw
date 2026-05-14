
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++) {
        Student* s = studentje[i];
        if (s->vpisna == vpisna) return i;
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    int len = student->stPO;
    PO* p = student->po;

    for (int i = 0; i < len; i++) {
        if (strcmp(p[i].predmet, predmet) == 0) {
            return i;
        }
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int s = poisciStudenta(studentje, stStudentov, vpisna);
    
    if (s == -1){
        Student* nov = malloc(sizeof(Student));
        nov->vpisna = vpisna;
        nov->stPO = 1;
        PO* po = calloc(10, sizeof(PO));
        nov->po = po;
        strcpy(po[0].predmet, predmet);
        po[0].ocena = ocena;

        studentje[stStudentov] = nov;

        return stStudentov + 1;
    }
    
    int p = poisciPO(studentje[s], predmet);
    PO* po = studentje[s]->po;

    if (p > -1) {
        po[p].ocena = ocena;
    } else {
        Student* st = studentje[s];
        int i = st->stPO;

        strcpy(st->po[i].predmet, predmet);
        st->po[i].ocena = ocena;

        st->stPO++;
    }
    return stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
