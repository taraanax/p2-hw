#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void append(int* poteze, int poteza) {
    int i = 0;
    while(poteze[i] != 0) i++;
    poteze[i] = poteza;
    return;
}

void resitev(int n, int k, bool beli, int* poteze) {
    if (n == 0 && beli == true) {
        printf("CRNI");
        return;
    }
    if (n == 0 && beli == false) {
        printf("%d ->", poteze[0]);
        int i = 1;
        while (poteze[i+1] != 0) {
            printf(" [%d] -> %d", poteze[i], poteze[i+1]);
            i = i + 2;
        }
        return;
    } else {
        for (int i = 1; i < k + 1; i++) {
            append(poteze, i);
            resitev(n - i, k, !beli, poteze);
        }
        return;
    }
}

int main () {
    int n, k;
    scanf("%d %d", &n, &k);

    int* poteze = calloc(n, sizeof(int));

    resitev(n,k,true,poteze);

    return 0;
}