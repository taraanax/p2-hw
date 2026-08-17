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
    int z = 0;
    bool oklepaj = false;

    while (fgets(vrstica, 1000, vhod) != NULL) {

        int presledki = 0;
        while (vrstica[presledki] == ' ') {
        presledki++;
        }

        if (oklepaj) {
            z += 4;
            oklepaj = false;
        }

        if (vrstica[presledki] == '}') {
            if (z <= 0) z = 0;
            else z -= 4;
        }

        int i = 0;
        while(vrstica[i] != '\0') {

            if (vrstica[i] == '{' && vrstica[i + 1] == '\n') oklepaj = true;
            i++;
            
        }

        for (int i = 0; i < z; i++) {
        fputc(' ', izhod);
        }

        fputs(vrstica + presledki, izhod);
    }
    
    fclose(vhod);
    fclose(izhod);

    return 0;
}