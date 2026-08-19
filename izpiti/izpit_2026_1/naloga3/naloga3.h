
#ifndef _NALOGA3_H
#define _NALOGA3_H

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int x;
    Vozlisce* nasl;
};

Vozlisce* prevezi(Vozlisce* zacetek);

#endif
