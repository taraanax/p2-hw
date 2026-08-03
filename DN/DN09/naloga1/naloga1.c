#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>

int main () {

    int n, k;
    scanf("%d %d", &n, &k);

    int* zap = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", zap[i]);
    }

    

    return 0;
}