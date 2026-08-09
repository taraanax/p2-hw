
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Tocka projekcija(Tocka t, Premica p) {
    Ulomek x, y;

    if(p.navpicna)  {
        x = p.n;
        y = t.y;
    }
    return (Tocka) {x, y};
}

#ifndef test

int main() {
    return 0;
}

#endif
