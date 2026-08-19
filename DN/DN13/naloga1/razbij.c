#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

    FILE* datoteka = fopen(argv[1], "rb");
    int k = atoi(argv[2]);

    int i = 0;
    char temp[k];
    int bajti;
    
    while ((bajti = fread(temp, 1, k, datoteka)) > 0) {
        char ime[100];
        sprintf(ime, "%s.%d", argv[1], i);

        FILE* dat = fopen(ime, "wb");
        fwrite(temp, 1, bajti, dat);

        fclose(dat);

        i++;
    }

    fclose(datoteka);
    
    return 0;
}