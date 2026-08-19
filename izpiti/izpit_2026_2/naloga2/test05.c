
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int TABELA[] = {1064, 1968, 976, 240, 1448, 1800, 1244, 460, 1772, 1696, 342, 1226, 530, 1814, 820, 800, 1334, 1262, 516, 166, 672, 542, 656, 408, 1316, 1172, 58, 1520, 110, 1492, 1260, 1908, 1114, 584, 990, 1442, 1962, 26, 598, 1050, 1880, 418, 1690, 908, 878, 1108, 1014, 1058, 1648, 264, 264, 528, 1140, 1396, 1306, 254, 334, 1892, 1190, 898, 372, 542, 1938, 288, 414, 364, 810, 1774, 626, 1228, 1038, 1360, 232, 1472, 862, 174, 1066, 1306, 1914, 1314, 1716, 976, 1090, 170, 826, 1296, 1720, 1076, 564, 474, 1492, 1574, 560, 860, 1254, 936, 610};

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
