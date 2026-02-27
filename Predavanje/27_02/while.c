#include <stdio.h>
#include <stdbool.h>

bool isprime(int n) {
    int d = 2;
    while (d <= n - 1) {
        if (n % d == 0) return false;
        d = d + 1;
    }
    return true;
}

int main() {
    for (int n = 1; n <= 100; n++ ) {
        if (isprime(n)) printf("%d ", n);
    }
    printf("\n"); 
    return 0;
}