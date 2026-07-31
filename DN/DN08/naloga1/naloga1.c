#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main () {

    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    int* zap = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &zap[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", zap[i]);
    }

    return 0;
}