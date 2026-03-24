#include <stdio.h>
#include <stdlib.h>

int sqt(int n) {
    int s = n*n;
    // c je vidna samo tej funkciji
    // c je živa ves čas med izvajanjem programa
    static int c = 0;
    c = c + 1;
    if (c == 100) exit(1);

    return s;
}

int n;

int main () {
    int a = 5;
    int b = sqt(a);

    printf("%d\n", b);
    return 0;
}