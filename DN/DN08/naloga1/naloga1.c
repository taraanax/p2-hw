#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isSorted(int* zap, int n) {
    for (int i = 0; i < n-1; i++) {
        if (zap[i] > zap[i+1]) 
            return false;
    }
    return true;
}

int* swap(int* zap, int n, int r, int index){
    
}

int resitev(int n, int k, int r, int* zap, int index) {
    if (isSorted(zap, n) && k >= 0) return 1;
    if (isSorted(zap, n) && k < 0) return 0;
    else {

    }
    return 0;
}

int main () {

    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    int* zap = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &zap[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", zap[i]);
    }

    resitev(n, k, r, zap, 0);


    return 0;
}