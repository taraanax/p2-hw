#include <stdio.h>
#include <stdlib.h>

int main () {

    int n;
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int vsota = arr[0];
    int povpr = 0;
    for (int d = 1; d < n; d++) {
        vsota = vsota + arr[d];
        povpr = vsota / (d+1);
        //printf("vsota: %d, povprečje: %d, d: %d\n" , vsota, povpr, d);
        if (arr[d] <= povpr) {
            printf("%d", d);
            break;
        }
        if (d == n-1) {
            printf("%d", n);
            break;
        }
        
    }

    return 0;
}