#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void izpisi(unsigned char* bajt, FILE* f, int n, int m) {
    
    fread(bajt, 1, n, f);
    

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            printf("%d", (bajt[i] >> j) & 1);
        }
    }


    return;
}

int main (int argc, char* argv[]) {

    FILE* datoteka = fopen(argv[1], "rb");
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);

    int ostanek = (q - p) % 8;
    int celota = (q - p) / 8;

    unsigned char bajt[celota];
    unsigned char ostalo[1];

    izpisi(bajt, datoteka, celota, 7);
    if (ostanek != 0) izpisi(ostalo, datoteka, 1, ostanek-1);

    return 0;
}