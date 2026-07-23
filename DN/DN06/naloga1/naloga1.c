
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

    //prazna tabela
    if (nizi[0] == NULL) {
        char* nov = malloc(sizeof(char));
        nov[0] = '\0';
        return nov;
    }

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

    char* nov = malloc(len * sizeof(char));

    strcpy(nov, nizi[0]);

    for (int i = 1; nizi != NULL; i++){
        strcat(nov, locilo);
        strcat(nov, nizi[i]);
        
    }   
    
    printf("[");
    for (int i = 0; i < len; i++){
        printf("%c ", nov[i]);
    }
    printf("]");

    return nov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje
    return 0;
}

#endif
