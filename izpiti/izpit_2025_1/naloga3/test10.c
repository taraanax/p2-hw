
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

int TABELA[] = {204, 211, 9, 182, 176, 104, 0, 179, 137, 125, 107, 59, 8, 61, 120, 58, 101, 163, 86, 208, 166, 73, 87, 51, 147, 15, 185, 121, 41, 111, 131, 167, 155, 22, 212, 210, 207, 173, 11, 132, 90, 52, 143, 31, 110, 146, 136, 174, 43, 138, 105, 95, 66, 80, 7, 65, 130, 30, 124, 206, 92, 158, 128, 64, 144, 145, 4, 194, 103, 135, 45, 54, 28, 201, 117, 47, 88, 114, 187, 177, 14, 209, 99, 2, 3, 40, 183, 154, 84, 70, 93, 116, 127, 142, 118, 169, 160, 85, 164, 57, 96, 34, 189, 67, 191, 122, 25, 27, 33, 113, 188, 129, 1, 153, 139, 171, 199, 126, 29, 89, 69, 17, 97, 78, 109, 112, 141, 162, 98, 140, 133, 12, 94, 186, 48, 196, 203, 193, 16, 23, 55, 195, 46, 10, 180, 178, 36, 119, 165, 157, 44, 77, 123, 106, 150, 83, 60, 19, 72, 53, 161, 5, 205, 18, 134, 62, 159, 39, 50, 26, 76, 24, 156, 192, 100, 115, 184, 175, 148, 42, 75, 20, 202, 63, 170, 32, 151, 21, 56, 168, 13, 91, 6, 149, 79, 49, 68, 71, 38, 152, 198, 82, 37, 108, 197, 181, 74, 102, 172, 35, 190, 200, 81};
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
