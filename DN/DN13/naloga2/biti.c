#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

    FILE* datoteka = fopen(argv[1], "rb");
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);

    unsigned char bajt;
    int i = 0;

    while (i < q && fread(&bajt, 1, 1, datoteka) != NULL) {

        for (int j = 7; j >= 0; j--) {

            if (i >= p && i < q) {
                printf("%d", (bajt >> j) & 1);
            }

            i++;
        }
    }

    fclose(datoteka);
    return 0;
}