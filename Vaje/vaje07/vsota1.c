#include <stdio.h>
#include <stdbool.h>

int steviloVsot (int k, int n);

int main () {

    int n;
    int k;
    scanf("%d%d", &n, &k);

    printf("%d\n", steviloVsot(k, n));


    return 0;
}

int steviloVsot (int k, int n) {
    if (n == 0) return 1;
    if (n < 0 || k == 0) return 0;

    return steviloVsot(k, n - k) + steviloVsot(k - 1, n);
}