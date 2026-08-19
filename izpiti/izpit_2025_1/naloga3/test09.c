
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

int TABELA[] = {123, 101, 103, 137, 4, 140, 39, 94, 135, 48, 42, 51, 97, 194, 199, 21, 179, 35, 76, 166, 188, 50, 128, 78, 73, 70, 176, 8, 104, 105, 24, 43, 46, 19, 89, 40, 44, 151, 72, 49, 167, 107, 58, 116, 41, 28, 30, 12, 65, 195, 153, 182, 126, 177, 147, 5, 139, 23, 17, 129, 118, 15, 67, 138, 102, 198, 32, 158, 20, 112, 113, 163, 191, 125, 7, 190, 154, 100, 77, 157, 169, 22, 10, 34, 146, 98, 99, 64, 156, 3, 173, 115, 53, 121, 81, 84, 45, 95, 174, 80, 185, 127, 9, 159, 75, 181, 152, 59, 149, 175, 52, 134, 47, 132, 184, 172, 26, 141, 90, 88, 170, 193, 36, 93, 11, 197, 122, 61, 6, 192, 142, 131, 120, 168, 186, 29, 68, 25, 130, 136, 83, 108, 14, 63, 37, 0, 69, 79, 38, 162, 161, 133, 111, 155, 91, 71, 109, 13, 33, 62, 144, 1, 86, 160, 66, 196, 92, 171, 178, 96, 187, 143, 54, 74, 57, 27, 2, 18, 148, 85, 106, 110, 119, 114, 183, 164, 87, 82, 60, 189, 150, 145, 16, 124, 31, 165, 55, 180, 56, 117};
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
