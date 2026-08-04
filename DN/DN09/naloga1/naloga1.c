#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>
#include <math.h>

int targetVsota(int* M, int n, int k);
void append(int* podmn, int st, bool* used, int index);
void back(int* podmn, bool* used, int index);

void izpis (int** podmn, int n, int k) {
    printf("{");
    for (int i = 0; i < k; i++) {
        if (i > 0) printf(", ");
        printf("{");

        int len = 0;
        while (podmn[i][len] != 0) len++;
        for (int j = 0; j < len; j++) {
            if (j > 0) printf(", ");
            printf("%d", podmn[i][j]);
        }

        printf("}");
    }
    printf("}\n");
}

void razbitje(int n, int k, int K, int* M, 
                int** podmn, int index, bool* used, int start,
                int vsota, int curVsota) {
    if (k == 0) {
        izpis(podmn, n, K);
        return;
    }
    if (index >= K) return;

    if (curVsota == 0) {
        while (start < n && !used[start]) {
        start++;
        }

        if (start == n)
            return;

        append(podmn[index], M[start], used, start);

        razbitje(n, k, K, M, podmn,
                    index, used, start + 1, vsota, M[start]);

        back(podmn[index], used, start);
        return;
    } else {
        for (int i = start; i < n; i++) {
            if (used[i] == false) continue;
            
            append(podmn[index], M[i], used, i);
            curVsota = curVsota + M[i];

            if (curVsota == vsota) {
            razbitje (n, k-1, K, M, podmn,
                        index+1, used, 0, vsota, 0);
        } else if (curVsota < vsota){
            razbitje(n, k, K, M, podmn,
                        index, used, i+1, vsota, curVsota);
        }

        curVsota = curVsota - M[i];
        back(podmn[index], used, i);
    }
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

    int vsota = targetVsota(M, n, k);
    if (vsota == 0) return 0;

    razbitje(n, k, k, M, podmn, 0, used, 0, vsota, 0);

    free(M);
    for (int i = 0; i < k; i++)
        free(podmn[i]);

    free(podmn);

    return 0;
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
