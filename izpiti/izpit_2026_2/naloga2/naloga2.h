
#ifndef _NALOGA2_H
#define _NALOGA2_H

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int x;
    Vozlisce* nasl;
};

void razdeli(Vozlisce* vhod, Vozlisce** sodi, Vozlisce** lihi);

#endif
