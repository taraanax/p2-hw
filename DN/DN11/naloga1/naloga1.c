
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    if (k == 1 || zacetek == NULL) return zacetek;

    Vozlisce* curr = zacetek;
    Vozlisce* prev = NULL;

    int i = 1;
    while(curr != NULL) {
        if (i % k != 0) {
            
            Vozlisce* temp1 = curr;
            curr = curr->naslednje;

            if (prev == NULL) {
                zacetek = curr;
            } else {
                prev->naslednje = curr;
            }

            free(temp1);
        } else {
            prev = curr;
            curr = curr->naslednje;
        }

        i++;
    }
    
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
