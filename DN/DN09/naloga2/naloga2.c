#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void izpisiSam(bool osebek, int index, int m, int s, int g, char** im,
                char** toz, char** povedek, bool* usedS, bool* usedP);

void izpisiStavek(int index, int m, int s, int g, char** im, char** toz,
                    char** povedek, bool* usedS, bool* usedP) {
    //osebek
    izpisiSam(true, index, m, s, g, im, toz, povedek, usedS, usedP);
    
    printf(" ");

    //glagol
    for (int j = 0; j < g; j++) {
            if (usedP[j] == false){
                usedP[j] = true;
                printf("%s ", povedek[j]);
                usedP[j] = false;
            }
        }

    printf(" ");

    //predmet
    for (int i = 0; i < s; i++) {
        if (!usedS[i]) {
            usedS[i] = true;
            izpisiSam(false, i, m, s, g, im, toz, povedek, usedS, usedP);
            usedS[i] = false;
        }
    }

    printf(".\n");

    return;
}

void izpisiSam(bool osebek, int index, int m, int s, int g, char** im,
                char** toz, char** povedek, bool* usedS, bool* usedP) {

    if (osebek)
        printf("%s", im[index]);
    else
        printf("%s", toz[index]);

    if (m == 0 || s == 2) return;

    printf(", ki ");
    izpisiStavek(index, m - 1, s, g, im, toz, povedek, usedS, usedP);

}


void resitev(int s, char** im, char** toz, int g, char** povedek,
             int m, bool* usedS, bool* usedP) {
    
    for (int i = 0; i < s; i++) {
        usedS[i] = true;
        izpisiStavek(i, m, s, g, im, toz, povedek, usedS, usedP);
        usedS[i] = false;
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
        usedS[i] = false;
    }

    bool usedP[g];
    for (int i = 0; i < g; i++) {
        usedP[i] = false;
    }

    resitev(s, im, toz, g, povedek, m, usedS, usedP);

    return 0;
}