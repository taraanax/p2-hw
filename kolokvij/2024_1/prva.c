#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
/*
    for (int i = 0; i < n; i++) {
        printf(" [%d] ", arr[i]);
    }
    printf("\n");
*/
    int gor = 1;
    int dol = 1;

    for (int i = 0; i < n; i++) {

        //printf("i: %d\n", i);

        if (arr[i] < arr [i+1]) {
            dol++;
            if (gor > 1) printf("%d\n", gor);
            gor = 1;
        }
        if (arr[i] > arr [i+1]) {
            gor++;
            if (dol > 1) printf("%d\n", dol);
            dol = 1;
        }
    }

    return 0;
}