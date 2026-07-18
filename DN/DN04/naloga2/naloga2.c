#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {

    //input
    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    int* arr = malloc(n*sizeof(int));
    for (int i = 0; i< n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int count = 0;
    int levo = 0;
    int desno = n - 1;

    while (levo < desno) {
        int sum = arr[levo] + arr[desno];
        if (sum == k) count++;
        else if (sum >= k) {
            desno--;
        } else levo++;
    }
    
    printf("%d\n", count);

/*debugging
    printf(" \n");

    

    printf("arr: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
*/
    return -1;
}