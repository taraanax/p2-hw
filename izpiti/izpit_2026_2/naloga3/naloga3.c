
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 02--06: vi"sina = 1
 * 01, 02, 07, 08: ro"cno izdelani oz. izbrani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* vhodna =  fopen(argv[1], "rb");
    FILE* izhodna =  fopen(argv[2], "wb");

    char crka; int st;
    fscanf(vhodna, "%c%d", &crka, &st);
    fprintf(izhodna, "%c%d\n", crka, st);

    int w, h;
    fscanf(vhodna, "%d %d", &w, &h);
    fprintf(izhodna, "%d %d\n", h, w);

    int cifra;
    fscanf(vhodna, "%d", &cifra);
    fprintf(izhodna, "%d\n", cifra);

    fgetc(vhodna);

    int px = w * h;
    unsigned char matrika[h][w];
    fread(&matrika, 1, px, vhodna);

    for (int i = w-1; i > -1; i--) {
        for (int j = 0; j < h; j++) {
            fputc(matrika[j][i], izhodna);
        }
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}
