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

void swap(int* zap, int n, int r, int index, int j){
    int temp [5];
    for (int i = 0; i < r; i++) {
        temp[i] = zap[index + i];
        zap[index + i] = zap[j + i];
        zap[j + i] = temp[i];
    }
    /*for (int i = 0; i < n; i++) {
        printf("%d ", zap[i]);
    }*/
}

int resitev(int n, int k, int r, int* zap) {
    int count = 0;
    if (isSorted(zap, n)) {
        count += 1;
    }
    if (k == 0) return count;
    else {
        for (int i = 0; i < n - r + 1; i++) {
            for (int j = i + r; j < n - r + 1; j++) {
                swap(zap, n, r, i, j);
                count += resitev(n, k-1, r, zap);
                swap(zap, n, r, i, j);
            }
        }
        return count;
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
    printf("%d", resitev(n, k, r, zap));


    return 0;
}