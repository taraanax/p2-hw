#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {

//input
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

//lps
    int* lps;
    lps = (int*)calloc(n, sizeof(int));

    int i = 1;
    int j = 0;

    while (i < n) {
        if (arr2[i] == arr2[j]) {
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

//iskanje k
    i = 0;
    j = 0;

    while (i < (2*n)) {
        if (arr[i] == arr2[j]) {
            j++;
            i++;
            
            if (j == n) {
                int k = i - n;

                if (k < n) {
                    printf("%d\n", k);
                    return 0;
                }

                j = lps[j - 1];
            }

        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
        
    }

/*debugging
    printf(" \n");

    printf("arr1: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr1[i]);
    }

    printf(" \n");

    printf("arr2: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr2[i]);
    }

    printf(" \n");

    printf("arr:  ");
    for (int i = 0; i < (2*n); i++) {
        printf("[%d] ", arr[i]);
    }
 
    printf(" \n");
    
    printf("lps:  ");
    for (int i = 0; i < (n); i++) {
        printf("[%d] ", lps[i]);
    }
*/
    return -1;
}
