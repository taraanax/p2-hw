#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

    int* arr = malloc((2*n)*sizeof(int));
    
    memcpy(arr, arr1, n * sizeof(int));
    memcpy(arr + n, arr1, n * sizeof(int));

    int* lps;
    lps = (int*)calloc(n, sizeof(int));

    int i = 0;
    int j = 0;

    while (i < n) {
        if (arr1[i] == arr2[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            lps[i] = 0;
            i++;
            
        }
    }

    int curr = 0;
    int max = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        curr = lps[i];

        if (curr > max) {
            max = curr;
            k = i - curr + 1;
        } else if (curr == max){
            int kandidat = i - curr + 1;
                if (kandidat < k) {
                    k = kandidat;
                }
            }
        }

    printf("%d ", k);


    printf(" \n");

    printf("arr1: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr1[i]);
    }

    printf(" \n");
/*
    printf("arr2: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr2[i]);
    }

    printf(" \n");
*/
    printf("arr:  ");
    for (int i = 0; i < (2*n); i++) {
        printf("[%d] ", arr[i]);
    }
 
 /*   printf(" \n");
    
    printf("lps:  ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", lps[i]);
    }
*/
    return -1;
}
