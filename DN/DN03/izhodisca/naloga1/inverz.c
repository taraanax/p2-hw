
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h> 
#include "inverz.h"

long inverz(long y, long a, long b) {
    
    /*for (long i = a; i <= b; i++) {
        long x_nov = f(i);
        if (x_nov == y) return i;
    }*/

    if (y == f(a)) return a;
    if (y == f(b)) return b;

    long offset = (b - a)/2;
    
    long mid = a + offset;
    long x_nov = f(mid);

    if (y < x_nov) return inverz(y, a, mid);
    if (y > x_nov) return inverz(y, mid, b);

    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.