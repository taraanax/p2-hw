
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int UlomekToInt (Ulomek ulomek) {
    return ulomek.st/ulomek.im;
}

Ulomek skupniIm (Ulomek ulomek, int a) {
    ulomek.st = ulomek.st * a;
    ulomek.im = ulomek.im * a;
    return ulomek;
}

Tocka projekcija(Tocka t, Premica p) {
    Ulomek x, y;
    x.st = 0;
    y.st = 0;
    x.im = 1;
    y.im = 1;

    int tx = UlomekToInt(t.x);
    int ty = UlomekToInt(t.y);
    int k = UlomekToInt(p.k);
    int n = UlomekToInt(p.n);

    if(p.navpicna)  {
        x = p.n;
        y = t.y;
        return (Tocka) {x, y};
    }

    if(UlomekToInt(t.y) == (UlomekToInt(p.k) * UlomekToInt(t.x) + UlomekToInt(p.n))) {
        x = t.x;
        y = t.y;
        return (Tocka) {x, y};
    }

    x.im = k*k + 1;
    y.im = k*k + 1;

    x.st = k*(k*tx - ty + n);
    y.st = k*tx - ty + n;

    x = skupniIm(x, t.x.im);
    y = skupniIm(y, t.y.im);
    t.x = skupniIm(t.x, k*k + 1);
    t.y = skupniIm(t.y, k*k + 1);

    x.st = t.x.st - x.st;
    y.im = t.y.st + y.st;

    return (Tocka) {x, y};
}

#ifndef test

int main() {
    return 0;
}

#endif
