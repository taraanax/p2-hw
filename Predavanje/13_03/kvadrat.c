#include <stdio.h>

int sqt(int n) {
    int s = n*n;
    return s;
}

int n;

int main () {
    int a = 5;
    int b = sqt(a);

    printf("%d\n", b);
    return 0;
}