
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 01--05: ro"cno izdelani
 * 06--10: samodejno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* vhod = fopen(argv[1], "r");
    FILE* izhod = fopen(argv[2], "w");

    char stevilo[1000001];
    int* stevila = malloc(100000 * sizeof(int));

    int len = 0;
    while(fgets(stevilo, 1000001, vhod) != NULL) {
        stevila[len] = atoi(stevilo);
        len++;
    }


    int max = -100000000;
    int curr = 0;
    for (int i = 0; i < len - 2; i++) {
        curr = stevila[i] + stevila[i + 1] + stevila[i + 2];
        if(curr > max) max = curr;
    }

    char resitev[1000001];
    sprintf(resitev, "%d", max);
    fputs(resitev, izhod);

    fclose(vhod);
    fclose(izhod);

    return 0;
}
