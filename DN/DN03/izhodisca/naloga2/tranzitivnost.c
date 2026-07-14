
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b) {

    bool trans = true;
    bool antitrans = true;

    for (int x = a; x <= b; x++) {
        for (int y = a; y <= b; y++) {
            if (!f(x, y)) continue;

            for (int z = a; z <= b; z++) {
                if (!f(y, z)) continue;

                if (f(x, z)) antitrans = false;
                else trans = false;
            }
        }
    }
    
    if (trans == true && antitrans == true) return 1;
    if (trans == true && antitrans == false) return 2;
    if (trans == false && antitrans == true) return 3;
    if (trans == false && antitrans == false) return 1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
