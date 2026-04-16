#include <stdio.h>
#include <stdbool.h>

void izpisi(int arr[], int len);
void f(int k, int n, int arr[], int len);

int main () {

    int n;
    int k;
    scanf("%d %d", &n, &k);

    int arr[100];
    f(k, n, arr, 0);

    return 0;
}

void izpisi(int arr[], int len) {
    
    for (int i = 0; i < len; i++) {
        if (i > 0) printf(" + ");
        printf("%d", arr[i]);
    }
    printf("\n");

    return;
}

void f(int k, int n, int arr[], int len) {
    
    if (n == 0) {
        izpisi(arr, len);
        return;
    }

    for (int i = k; i >= 1; i--) {
        if (i <= n) {
            arr[len] = i;
            f(i, n - i, arr, len + 1);
        }
    }
}