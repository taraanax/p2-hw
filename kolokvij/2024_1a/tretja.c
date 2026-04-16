#include <stdio.h>
#include <stdlib.h>

void izpis(int arr[], int len){
    printf("%d", arr[0]);
    for(int i = 1; i < len; i++) {
        printf("_%d", arr[i]);
    }
    printf("\n");
    return ;
}

int main () {

    int v;
    int s;
    scanf("%d %d", &v, &s);

    int matrika[100][100];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < s; j++) {
            scanf("%d", &matrika[i][j]);
        }
    }
    int count = 0;
    int A[1000];
    int B[1000];
    int C[1000];
    
    int sum = 0;

    for(int i = 0; i < v; i++) {
        printf("i: %d\n", i);
        B[i] = sum;
        int nevem = 0;
        for(int j = 0; j < s; j++) {
            
            if (matrika[i][j] != 0) {
                A[count] = matrika[i][j];
                C[count] = j;
                count++;
                nevem++;
            }
        }
        sum = sum + nevem;
    }
    B[v] = count;

    izpis(A, count);
    izpis(B, v + 1);
    izpis(C, count);

    return 0;
}