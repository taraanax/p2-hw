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

void swap(int* zap, int n, int r, int index){
    int* temp = malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        temp[i] = zap[index + i];
        zap[index + i] = zap[index + r + i];
        zap[index + r + i] = temp[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", zap[i]);
    }
}

int resitev(int n, int k, int r, int* zap, int index) {
    if (isSorted(zap, n) && k >= 0) return 1;
    if (isSorted(zap, n) && k < 0) return 0;
    else {
        swap(zap, n, r, index);
        k = k - 1;
        return 1 + resitev(n, k, r, zap, index + 1);
    }
}

int main () {

    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    int* zap = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &zap[i]);
    }
/*
    for (int i = 0; i < n; i++) {
        printf("%d ", zap[i]);
    }
*/
    swap(zap, n, r, 0);
    //printf("%d", resitev(n, k, r, zap, 0));


    return 0;
}