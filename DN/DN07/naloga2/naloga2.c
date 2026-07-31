#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void kartezicniProd(char** nizi, int n, int row, char* trenutni) {
    if (row == n) {
        trenutni[n] = '\0';
        printf("%s\n", trenutni);
        return;
    } else {
        for (int i = 0; nizi[row][i] != '\0'; i++) {
            trenutni[row] = nizi[row][i];
            kartezicniProd(nizi, n, row + 1, trenutni);
        }
    }
}

int main () {

    int n; 
    scanf("%d", &n);
    getchar();

    char** nizi = malloc(n * sizeof(char*));

    int a;
    int j;
    for (int i = 0; i < n; i++)  {
        nizi[i] = malloc(42 * sizeof(char));
        j = 0;
        while ((a = getchar()) != '\n') {
            nizi[i][j] = a;
            j++;
        }
        nizi[i][j] = '\0';
    }

    /*
    for(int i = 0; i < n; i++) {
        j = 0;
        printf("[");
        while (nizi[i][j] != '\0') {
            printf("%c", nizi[i][j]);
            j++;
        }
        printf("] \n");
    }
    */

    char *trenutni = malloc(n + 1);
    kartezicniProd(nizi, n, 0, trenutni);

    return 0;
}