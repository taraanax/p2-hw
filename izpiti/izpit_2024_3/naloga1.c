#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    Vozlisce* naslednje; // kazalec na naslednje vozlišče v seznamu ( NULL, če ga ni)
    Vozlisce* nn; // kazalec na naslednika naslednjega vozlišča ( NULL, če ga ni)
};

void nastavi(Vozlisce* zacetek) {
    if (zacetek == NULL) return;

    Vozlisce* snd = zacetek->naslednje;
    Vozlisce* trd;
    if (snd == NULL) trd = NULL;
    else trd = zacetek->naslednje->naslednje;

    zacetek->nn = trd;
    nastavi(snd);
}

int main() {

    // TEST 1

    {
        Vozlisce v1, v2, v3, v4, v5;

        v1.naslednje = &v2;
        v2.naslednje = &v3;
        v3.naslednje = &v4;
        v4.naslednje = &v5;
        v5.naslednje = NULL;

        v1.nn = NULL;
        v2.nn = NULL;
        v3.nn = NULL;
        v4.nn = NULL;
        v5.nn = NULL;

        nastavi(&v1);

        if (v1.nn == &v3 &&
            v2.nn == &v4 &&
            v3.nn == &v5 &&
            v4.nn == NULL &&
            v5.nn == NULL) {

            printf("Test 1: OK\n");

        } else {

            printf("Test 1: NAPAKA\n");
        }
    }

    // TEST 2

    {
        Vozlisce v1;

        v1.naslednje = NULL;
        v1.nn = NULL;

        nastavi(&v1);

        if (v1.nn == NULL) {
            printf("Test 2: OK\n");
        } else {
            printf("Test 2: NAPAKA\n");
        }
    }

    // TEST 3

    {
        Vozlisce v1, v2;

        v1.naslednje = &v2;
        v2.naslednje = NULL;

        v1.nn = NULL;
        v2.nn = NULL;

        nastavi(&v1);

        if (v1.nn == NULL &&
            v2.nn == NULL) {

            printf("Test 3: OK\n");

        } else {

            printf("Test 3: NAPAKA\n");
        }
    }

    // TEST 4

    {
        Vozlisce v1, v2, v3;

        v1.naslednje = &v2;
        v2.naslednje = &v3;
        v3.naslednje = NULL;

        v1.nn = NULL;
        v2.nn = NULL;
        v3.nn = NULL;

        nastavi(&v1);

        if (v1.nn == &v3 &&
            v2.nn == NULL &&
            v3.nn == NULL) {

            printf("Test 4: OK\n");

        } else {

            printf("Test 4: NAPAKA\n");
        }
    }

    // TEST 5: 

    {
        nastavi(NULL);

        printf("Test 5: OK\n");
    }

    // TEST 6

    {
        Vozlisce v[10];

        for (int i = 0; i < 9; i++) {
            v[i].naslednje = &v[i + 1];
            v[i].nn = NULL;
        }

        v[9].naslednje = NULL;
        v[9].nn = NULL;

        nastavi(&v[0]);

        int pravilno = 1;

        for (int i = 0; i < 8; i++) {
            if (v[i].nn != &v[i + 2]) {
                pravilno = 0;
            }
        }

        if (v[8].nn != NULL)
            pravilno = 0;

        if (v[9].nn != NULL)
            pravilno = 0;

        if (pravilno) {
            printf("Test 6: OK\n");
        } else {
            printf("Test 6: NAPAKA\n");
        }
    }

    // TEST 7

    {
        Vozlisce v[100];

        for (int i = 0; i < 99; i++) {
            v[i].naslednje = &v[i + 1];
            v[i].nn = NULL;
        }

        v[99].naslednje = NULL;
        v[99].nn = NULL;

        nastavi(&v[0]);

        int pravilno = 1;

        for (int i = 0; i < 98; i++) {
            if (v[i].nn != &v[i + 2]) {
                pravilno = 0;
                break;
            }
        }

        if (v[98].nn != NULL)
            pravilno = 0;

        if (v[99].nn != NULL)
            pravilno = 0;

        if (pravilno) {
            printf("Test 7: OK\n");
        } else {
            printf("Test 7: NAPAKA\n");
        }
    }

    // TEST 8

    {
        Vozlisce v1, v2, v3, v4;

        v1.naslednje = &v2;
        v2.naslednje = &v3;
        v3.naslednje = &v4;
        v4.naslednje = NULL;

        nastavi(&v1);

        if (v1.naslednje == &v2 &&
            v2.naslednje == &v3 &&
            v3.naslednje == &v4 &&
            v4.naslednje == NULL) {

            printf("Test 8: OK\n");

        } else {

            printf("Test 8: NAPAKA\n");
        }
    }

    // TEST 9

    {
        Vozlisce v1, v2, v3, v4;

        v1.naslednje = &v2;
        v2.naslednje = &v3;
        v3.naslednje = &v4;
        v4.naslednje = NULL;

        // Namenoma napačne vrednosti
        v1.nn = &v4;
        v2.nn = &v1;
        v3.nn = &v2;
        v4.nn = &v3;

        nastavi(&v1);

        if (v1.nn == &v3 &&
            v2.nn == &v4 &&
            v3.nn == NULL &&
            v4.nn == NULL) {

            printf("Test 9: OK\n");

        } else {

            printf("Test 9: NAPAKA\n");
        }
    }


    printf("\nVsi testi koncani.\n");

    return 0;
}