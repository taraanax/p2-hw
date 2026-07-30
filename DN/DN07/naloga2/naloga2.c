#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

    int i = 0; j = 0;
    while(nizi[i][j] != '\0') {
        for (int i = 0; i < n; i++) {
            printf("%c", nizi[i][j]);
        }
        j++;
    }

    return 0;
}