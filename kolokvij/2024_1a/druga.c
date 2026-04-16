#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void racionaliziraj(char** nizi);

int main () {



    return 0;
}

void racionaliziraj(char** nizi) {

    for (int i = 0; nizi[i] != NULL; i++){
        for (int j = i + 1; nizi[j] != NULL; j++) {
            if (strcmp(nizi[i], nizi[j]) == 0) nizi[j] = nizi[i];
        }
    }

    return nizi;
}