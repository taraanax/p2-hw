#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>
#include <math.h>

void append(int* podmn, int st, bool* used, int index) {
    int i = 0;
    while(podmn[i] != 0) i++;
    podmn[i] = st;
    used[index] = false;
    return;
}

void back(int* podmn, bool* used, int index) {
    int i = 0;
    while(podmn[i] != 0) i++;
    podmn[i-1] = 0;
    used[index] = true;
    return;
}

int targetVsota(int* M, int n, int k) {
    int vsota = 0;
    for (int i = 0; i < n; i++) {
        vsota = vsota + M[i];
    }

    if (vsota % k != 0) return 0;

    vsota = vsota / k;
    return vsota;
}

bool jeVsota(int* podmn, int* M, int n, int k) {
    int vsota = 0; 
    for (int i = 0; i < n; i++) { 
        vsota = vsota + podmn[i]; 
    } 
    if (vsota == targetVsota(M, n, k)) return true; 
    else return false;
}

void izpis (int** podmn, int n, int k) {
    for (int i = 0; i < k; i++) {
        printf("{");

        int len = 0;
        while (podmn[i][len] != 0) len++;
        for (int j = 0; j < len - 2; j++) {
            printf("%d, ", podmn[i][j]);
        }

        printf("%d}}\n", podmn[i][len-1]);
    }
}

void razbitje(int n, int k, int K, int* M, int** podmn, int index, bool* used, int start) {
    if (k == 0) {
        izpis(podmn, n, K);
        return;
    }
    if (index >= K) return;

    for (int i = start; i < n; i++) {
        if (used[i] == false) continue;

        append(podmn[index], M[i], used, i);
        if (jeVsota(podmn[index], M, n, K)) {
            razbitje (n, k-1, K, M, podmn, index+1, used, 0);
        } else {
            razbitje(n, k, K, M, podmn, index, used, i+1);
        }

        back(podmn[index], used, i);
    }

}

int main () {

    int n, k;
    scanf("%d %d", &n, &k);

    int* M = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &M[i]);
    }

    int** podmn = calloc(k, sizeof(int*));
    for (int i = 0; i < k; i++) {
        podmn[i] = calloc(n, sizeof(int));
    } 
    
    bool used[n];
    for (int i = 0; i < n; i++) {
        used[i] = true;
    } 
    razbitje(n, k, k, M, podmn, 0, used, 0);

    free(M);
    free(podmn);

    return 0;
}