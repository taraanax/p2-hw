#include <stdio.h>

int n = 17;
int m;

int f() {
    
    int a = 3;
    return a;
}

int main () {

    int* p;
    p = &n;
    printf("%p\n", p);

    m = *p;

    return 0;
}