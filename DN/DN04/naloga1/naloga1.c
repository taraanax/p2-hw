#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int* arr1 = malloc(n*sizeof(int));
    for (int i = 0; i< n; i++) {
        scanf("%d", &arr1[i]);
    }

    int* arr2 = malloc(n*sizeof(int));
    for (int i = 0; i< n; i++) {
        scanf("%d", &arr2[i]);
    }

    int* lps;
    lps = (int*)calloc(n, sizeof(int));

    int i = 1;
    int j = 0;

    while (i < n) {
        if (arr1[i] == arr1[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
        
    }

    /*
    printf(" \n");

    for (int i = 0; i < n; i++) {
        printf(" [%d] ", arr1[i]);
    }

    printf(" \n");

    for (int i = 0; i < n; i++) {
        printf(" [%d] ", arr2[i]);
    }

    printf(" \n");
    
    for (int i = 0; i < n; i++) {
        printf(" [%d] ", lps[i]);
    }
    */

    return -1;
}
