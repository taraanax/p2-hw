#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



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
    bool usedP[g];

    return 0;
}