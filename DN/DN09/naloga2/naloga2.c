#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void izpis (int s, char* im, char** toz, int g, char* povedek, int start) {
    im[0] = im[0] - 32;
    for (int i = start + 1; i < s; i++) {
        
        printf("%s %s %s.\n", im, povedek, toz[i]);
    }
    im[0] = im[0] + 32;
    return;
}

void resitev(int s, char** im, char** toz, int g, char** povedek, int m, bool* usedS, bool* usedP, int start) {
    if (start == s) return;
    if (usedS[start] == true) {
        for (int i = 0; i < g; i++) {
            izpis (s, im[start], toz, g, povedek[i], start);
            usedP[i] = false;
        }
        usedS[start] = false;
        resitev(s, im, toz, g, povedek, m, usedS, usedP, start + 1);
    }
    return;
}

int main() {

    int s, g, m;
    scanf("%d", &s);
    getchar();

    char** im = malloc(s * sizeof(char*));
    char** toz = malloc(s * sizeof(char*));

    for (int i = 0; i < s; i++) {
        im[i] = malloc(21 * sizeof(char));
        toz[i] = malloc(21 * sizeof(char));
        
        scanf("%20s %20s", im[i], toz[i]);
    }

    scanf("%d", &g);
    getchar();

    char** povedek = malloc(g * sizeof(char*));

    for (int i = 0; i < g; i++) {
        povedek[i] = malloc(21 * sizeof(char));
        scanf("%20s", povedek[i]);
    }

    scanf("%d", &m);

    bool usedS[s];
    for (int i = 0; i < s; i++) {
        usedS[i] = true;
    }

    bool usedP[g];
    for (int i = 0; i < g; i++) {
        usedP[i] = true;
    }

    resitev(s, im, toz, g, povedek, m, usedS, usedP, 0);

    return 0;
}