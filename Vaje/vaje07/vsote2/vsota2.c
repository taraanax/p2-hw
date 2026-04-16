#include <stdio.h>
#include <stdbool.h>

main () {

    int n;
    int k;


    return 0;
}

void f(int k, int n, int arr[], int len) {
    
    if (n == 0) {
        //izpisi arr
        return;
    }

    for (int i = k; i >= 1; i--) {
        if (i <= n) {
            arr[len] = i;
            f(i, n - i, arr, len + 1);
        }
    }
}