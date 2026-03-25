#include <stdio.h>

int n = 3;

int inc1(int n) {
    n = n + 1;
    return n;
}

int inc2(int *n) {
    *n = *n + 1;
    return *n;
}

int main () {

    int m = inc1(n);
    printf("1. m = %d, n = %d\n", m, n);

    m = inc2(&n);
    printf("2. m = %d, n = %d\n", m, n);

    n = 3;
    m = inc1(n+3);
    printf("3. m = %d, n = %d\n", m, n);

    m = inc1(17*2);
    printf("4. m = %d, n = %d\n", m, n);

    return 0;
}