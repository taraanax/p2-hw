#include <stdio.h>
#include <stdbool.h>

/* ne tega delat */

bool isprime(int n) {
    int d = 2;
    loop:
        if (d <= n - 1){
            if (n % d == 0) return false;
            d = d + 1;
            goto loop;
        }
}

int main() {
    for (int n = 1; n <= 100; n++ ) {
        if (isprime(n)) printf("%d ", n);
    }
    printf("\n"); 
    return 0;
}