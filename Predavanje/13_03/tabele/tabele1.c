#include <stdio.h>

main() {

    int t[100];
    
    //1. način
    for (int i = 0; i < 100; i++) t[i] = 2*i;

    //2. način
    int *p = &(t[0]);
    for (int i = 0; i < 100; i++) p[i] = 2*i;

    return 0;
}