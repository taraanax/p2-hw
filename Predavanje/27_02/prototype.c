#include <stdio.h>
#include <stdbool.h>

bool isprime(int n); /* prototip funkcije isprime */

int main() {
    for (int n = 1; n <= 100; n++ ) {
        if (isprime(n)) printf("%d ", n);
    }
    printf("\n"); 
    return 0;
}

bool isprime(int n) {
    for (int d = 2; d <= n - 1; d++) {
        if (n % d == 0) return false;
    }
    return true;
}