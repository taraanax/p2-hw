#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    char vrstica[1001];
    fgets(vrstica, sizeof(vrstica), vhodna);

    char* beseda = strtok(vrstica, " \n");
    int s = -1;
    int c = -1;
    int i = 0;
    while (beseda != NULL) {
        if (strcmp(beseda, argv[3]) == 0) c = i;
        if (strcmp(beseda, "starost") == 0) s = i;
        beseda = strtok(NULL, " \n");
        i++;
    }

    char** arrc = malloc(1000 * sizeof(char*));
    int* arrs = malloc(1000 * sizeof(int));
    
    int j = 0;
    while (fgets(vrstica, sizeof(vrstica), vhodna) != NULL) {
       
        beseda = strtok(vrstica, " \n");
        int i = 0;
        
        while (beseda != NULL) {
            if (i == s) {
                arrs[j] = atoi(beseda);
            }
            if (i == c) {
                arrc[j] = malloc(101 * sizeof(char));
                strcpy(arrc[j], beseda);
            }
            beseda = strtok(NULL, " \n");
            i++;
        }
        j++;
    }

    char** razlicni = malloc(j * sizeof(char*));
    int stRaz = 0;

    for (int i = 0; i < j; i++) {

        int obstaja = 0;

        for (int k = 0; k < stRaz; k++) {
            if (strcmp(razlicni[k], arrc[i]) == 0) {
                obstaja = 1;
                break;
            }
        }

        if (obstaja == 0) {
            razlicni[stRaz] = malloc(101 * sizeof(char));
            strcpy(razlicni[stRaz], arrc[i]);
            stRaz++;
        }
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}