#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n, k;
    scanf("%d %d", &n, &k);

    if (n - k == 1 || ((n % 2 == 0) && k == 1)) printf("CRNI");

    return 0;
}