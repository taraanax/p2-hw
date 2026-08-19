
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 02: velikost slike je 1 x 1
 * 03: velikost slike je 1 x 2
 * 04--10: samodejno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhod = fopen(argv[2], "wb");

    char crka;
    int st;
    fscanf(vhodna, "%c%d", &crka, &st);
    fprintf(izhod, "%c%d\n", crka, st);

    int w, h;
    fscanf(vhodna, "%d %d", &w, &h);
    fprintf(izhod, "%d %d\n", w, h);

    int cifra;
    fscanf(vhodna, "%d", &cifra);
    fprintf(izhod, "%d\n", cifra);

    fgetc(vhodna);

    //printf("w: %d | h: %d\n", w, h);

    int piksli = w * h;
    unsigned char r[piksli];
    unsigned char g[piksli];
    unsigned char b[piksli];

    for (int i = 0; i < piksli; i++) {
        fread(&r[i], 1, 1, vhodna);
        fread(&g[i], 1, 1, vhodna);
        fread(&b[i], 1, 1, vhodna);
    }

    fwrite(r, 1, piksli, izhod);
    fwrite(g, 1, piksli, izhod);
    fwrite(b, 1, piksli, izhod);
    
    fclose(vhodna);
    fclose(izhod);

    return 0;
}
