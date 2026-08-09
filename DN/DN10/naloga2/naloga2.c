
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Ulomek sestej(Ulomek a, Ulomek b);
Ulomek odstej(Ulomek a, Ulomek b);
Ulomek pomnozi(Ulomek a, Ulomek b);
Ulomek deli(Ulomek a, Ulomek b);
Ulomek okrajsaj(Ulomek a);

Tocka projekcija(Tocka t, Premica p) {
    Ulomek x, y;
    x.st = 0;
    y.st = 0;
    x.im = 1;
    y.im = 1;

    if(p.navpicna)  {
        x = p.n;
        y = t.y;
        return (Tocka) {x, y};
    }
    Ulomek ena;
    ena.im = 1; ena.st = 1;

    x = odstej(t.x, deli (pomnozi(p.k, sestej(odstej(pomnozi(p.k, t.x), t.y), p.n)), sestej(pomnozi(p.k, p.k), ena)));
    y = sestej(t.y, deli (sestej(odstej(pomnozi(p.k, t.x), t.y), p.n), sestej(pomnozi(p.k, p.k), ena)));

    x = okrajsaj(x);
    y = okrajsaj(y);

    return (Tocka) {x, y};
}

#ifndef test

int main() {
    return 0;
}

#endif

Ulomek sestej(Ulomek a, Ulomek b) {
    Ulomek r;

    r.st = a.st * b.im + b.st * a.im;
    r.im = a.im * b.im;

    return r;
}

Ulomek odstej(Ulomek a, Ulomek b) {
    Ulomek r;

    r.st = a.st * b.im - b.st * a.im;
    r.im = a.im * b.im;

    return r;
}

Ulomek pomnozi(Ulomek a, Ulomek b) {
    Ulomek r;

    r.st = a.st * b.st;
    r.im = a.im * b.im;

    return r;
}

Ulomek deli(Ulomek a, Ulomek b) {
    Ulomek r;

    r.st = a.st * b.im;
    r.im = a.im * b.st;

    return r;
}

Ulomek okrajsaj(Ulomek ulomek) {

    int a = ulomek.st;
    int b = ulomek.im;

    while (b != 0) {
        int ostanek = a % b;
        a = b;
        b = ostanek;
    }

    ulomek.st /= a;
    ulomek.im /= a;

    return ulomek;
}