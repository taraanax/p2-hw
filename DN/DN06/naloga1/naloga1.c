
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char* zdruzi(char** nizi, char* locilo) {
    /*
    int i = 0;
    while(nizi[i] != NULL) {
        printf("[");
        int j = 0;
        while(nizi[i][j] != '\0') {
            printf("%c", nizi[i][j]);
            j++;
        }
        printf("]\n");
        i++;
    }
    */

   //DOLZINA
    int i = 0;
    int h = 0;
    while(nizi[i] != NULL) {
        int j = 0;
        while(nizi[i][j] != '\0') j++;
        h = h + j;
        //printf("h [%d] = h + j[%d]\n", h, j);
        i++;
    }

    int k = 0;
    while(locilo[k] != '\0') k++;

    int len = h + (i - 1) * k + 1;
    //printf("len[%d] = h[%d] + (i[%d] - 1) * k[%d] + 1\n", len, h, i, k);

    
    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje
    return 0;
}

#endif
