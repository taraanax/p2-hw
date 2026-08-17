#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    FILE *vhod = fopen(argv[1], "r");
    if (vhod == NULL) return 1;

    FILE *izhod = fopen(argv[2], "w");
    if (izhod == NULL) return 1;

    char vrstica[1000];
    while (fgets(vrstica, 1000, vhod) != NULL) {
        
        fputs(vrstica, izhod);
    }
    
    fclose(vhod);
    fclose(izhod);

    return 0;
}