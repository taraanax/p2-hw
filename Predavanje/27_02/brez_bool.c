#include <stdio.h>

int isprime(int n) {
    for (int d = 2; d <= n - 1; d++) {
        if (n % d == 0) return 0;
    }
    return 1;
}

int main() {
    for (int n = 1; n <= 100; n++ ) {
        if (isprime(n) /* ==1 */) printf("%d ", n);
    }
    printf("\n"); 
    return 0;
}