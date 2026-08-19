
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

int TABELA[] = {39, 4, 3, 55, 15, 35, 2, 34, 51, 50, 46, 0, 17, 12, 40, 42, 45, 53, 13, 27, 25, 9, 11, 47, 49, 23, 52, 36, 6, 19, 28, 26, 54, 18, 7, 41, 43, 38, 22, 37, 30, 33, 14, 32, 29, 21, 5, 20, 56, 44, 16, 31, 8, 10, 1, 24, 48};
int N = sizeof(TABELA) / sizeof(TABELA[0]);

Vozlisce* zgradi(int* t, int n) {
    Vozlisce* zacetek = NULL;
    for (int i = n - 1; i >= 0; i--) {
        Vozlisce* novo = calloc(1, sizeof(Vozlisce));
        novo->x = t[i];
        novo->nasl = zacetek;
        zacetek = novo;
    }
    return zacetek;
}

Vozlisce** shraniNaslove(Vozlisce* zacetek, int n) {
    Vozlisce** naslovi = calloc(n, sizeof(Vozlisce*));
    Vozlisce* p = zacetek;
    while (p != NULL) {
        naslovi[p->x] = p;
        p = p->nasl;
    }
    return naslovi;
}

void izpisi(Vozlisce* zacetek) {
    printf("[");
    Vozlisce* p = zacetek;
    while (p != NULL) {
        if (p != zacetek) {
            printf(", ");
        }
        printf("%d", p->x);
        p = p->nasl;
    }
    printf("]\n");
}

bool preveriNaslove(Vozlisce* zacetek, Vozlisce** naslovi) {
    Vozlisce* p = zacetek;
    while (p != NULL) {
        if (p != naslovi[p->x]) {
            return false;
        }
        p = p->nasl;
    }
    return true;
}

void pocisti(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    while (p != NULL) {
        Vozlisce* q = p->nasl;
        free(p);
        p = q;
    }
}

int main() {
    Vozlisce* zacetek = zgradi(TABELA, N);
    Vozlisce** naslovi = shraniNaslove(zacetek, N);
    izpisi(zacetek);

    Vozlisce* noviZacetek = prevezi(zacetek);
    izpisi(noviZacetek);
    printf("%d\n", preveriNaslove(noviZacetek, naslovi));

    free(naslovi);
    pocisti(noviZacetek);
    return 0;
}
