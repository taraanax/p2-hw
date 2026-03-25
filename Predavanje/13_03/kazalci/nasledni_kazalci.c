#include <stdio.h>

int main () {

    int n;
    int *pn = &n;
    printf("%p %p\n", pn, pn + 3 /* == pn + 3*sizeof(int) */);

    double x;
    double *px = &x;
    printf("%p %p\n", px, px + 3 /* == px + 3*sizeof(double) */);

    return 0;
}