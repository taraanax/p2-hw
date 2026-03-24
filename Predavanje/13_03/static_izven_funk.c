#include <stdio.h>
#include <stdlib.h>

// c je vidna vsem funkcijam in jo lahko spreminjajo
// c je živa ves čas med izvajanjem programa
int c = 0;

int sqt(int n) {
    int s = n*n;
    
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