#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

    int n = atoi(argv[2]);
    FILE* vhod = fopen(argv[1], "r");
    if (vhod == NULL) return 1;

    char** vrstice = malloc(1000000 * sizeof(char*));
    char vrstica[11];
    int i = 0;
    while (fgets(vrstica, 11, vhod) != NULL) {
        vrstice[i] = malloc((strlen(vrstica) + 1) * sizeof(char));
        strcpy(vrstice[i], vrstica);
        i++;
    }

   
    int j;
    if (n >= i) j = 0;
    else j = i - n;

    while (j < i) {
        printf("%s", vrstice[j]);
        j++;
    }

    return 0;
}