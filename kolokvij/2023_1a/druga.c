#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih);

int main() {

    char *nizi[] = {"Danes", "je", "kolokvij", "pri_P2!"};
    int stVhodnih = 4;
    int stIzhodnih;

    char **rez = poStolpcih(nizi, stVhodnih, &stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("[%s]\n", rez[i]);
    }

    printf("%d\n", stIzhodnih);

    return 0;
}

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {

    int maxDolz = 0; 
    for (int i = 0; i < stVhodnih; i++) {
        int count = 0;
        //ali pa int count = strlen(nizi[i]);
        for (int j = 0; nizi[i][j] != '\0' ; j++) {
            count++;
        }
        if (count > maxDolz) maxDolz = count;
    }

    char **rezultat = malloc (maxDolz * sizeof(char*));
    
    for (int i = 0; i < maxDolz; i++) {
        rezultat[i] = malloc((stVhodnih + 1) * sizeof(char));
        int k = 0;
        for (int j = 0; j < stVhodnih; j++) {
            
            if (i < strlen(nizi[j])) {
                rezultat[i][k++]  = nizi [j][i];
            }
        }
        rezultat[i][k++] = '\0';
    }


    *stIzhodnih = maxDolz;

    return rezultat;
}