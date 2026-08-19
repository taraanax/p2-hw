
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 02--06: "stevilo argumentov = 3
 * 01, 07, 10: ro"cno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sum(int len, int* arr) {
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }

    return sum;
}

void izpis (int* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("[%d]",arr[i]);
    }

    return;
}

int main(int argc, char** argv) {
    
    int* neg = calloc(500, sizeof(int));
    int* poz = calloc(500, sizeof(int));

    poz[0] = atoi(argv[1]);
    int j = 1;
    int k = 0;

    for (int i = 2; i < argc - 1; i++) {
        if (strcmp(argv[i],"-") == 0) {
            neg[k] = atoi(argv[i + 1]);
            k++;
        } else if (strcmp(argv[i],"+") == 0){
            poz[j] = atoi(argv[i + 1]);
            j++;
        }
    }

    //izpis(poz, j);
    //izpis(neg, k);

    int sum1= sum(k, neg);
    int sum2 = sum(j, poz);
    int sum = sum2 - sum1;
    
    printf("%d", sum);

    return 0;
}
