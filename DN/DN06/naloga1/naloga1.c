
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char* zdruzi(char** nizi, char* locilo) {
    int i = 0;
    while(nizi[i] != NULL) {
        printf("[");
        int j = 0;
        while(nizi[i][j] != locilo[0]) {
            printf(" %c", nizi[i][j]);
            j++;
        }
        printf("]\n");
        i++;
    }
    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje
    return 0;
}

#endif
