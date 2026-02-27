#include <stdio.h>
#include <stdbool.h>

/* ne tega delat */

bool isprime(int n) {
    int d = 2;
    
    loop:
        if (d <= n - 1) goto body;
            goto end;
    body:
            if (n % d == 0) goto fail;
            d = d + 1;
            goto loop;
    fail:
        return false;
    end: 
        return true;
}

int main() {
    for (int n = 1; n <= 100; n++ ) {
        if (isprime(n)) printf("%d ", n);
    }
    printf("\n"); 
    return 0;
}