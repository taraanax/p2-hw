
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int TABELA[] = {2};

Vozlisce* ustvari(int* t, int n) {
    Vozlisce* zacetek = NULL;
    for (int i = n - 1; i >= 0; i--) {
        Vozlisce* novo = calloc(1, sizeof(Vozlisce));
        novo->x = t[i];
        novo->nasl = zacetek;
        zacetek = novo;
    }
    return zacetek;
}

void izpisi(Vozlisce* zacetek) {
    printf("[");
    Vozlisce* v = zacetek;
    while (v != NULL) {
        if (v != zacetek) {
            printf(", ");
        }
        printf("%d", v->x);
        v = v->nasl;
    }
    printf("]\n");
}

void pocisti(Vozlisce* zacetek) {
    Vozlisce* v = zacetek;
    while (v != NULL) {
        Vozlisce* w = v->nasl;
        free(v);
        v = w;
    }
}

int main() {
    Vozlisce* vhod = ustvari(TABELA, sizeof(TABELA) / sizeof(TABELA[0]));
    Vozlisce* sodi = NULL;
    Vozlisce* lihi = NULL;

    razdeli(vhod, &sodi, &lihi);

    izpisi(vhod);
    izpisi(sodi);
    izpisi(lihi);
    pocisti(vhod);
    pocisti(sodi);
    pocisti(lihi);
    return 0;
}
