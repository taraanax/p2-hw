#include <stdio.h>
#include <stdlib.h>

int sumMnoz(int n, int m);

int main() {

    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *obrnjena = malloc(n * sizeof(int));
    int j = 0;
    for (int i = n - 1; i > -1; i--) {
        obrnjena[j] = arr[i];
        j++;
    }

    int jepali = 0;
    for (int i = 0; i < n; i++) {
        if (obrnjena[i] != arr[i]) jepali = 1;
    }
    if (jepali == 0) printf("DA\n");
    if (jepali == 1) printf("NE\n");

    int vsota = 0;
    for (int i = 0; i < n; i++) {
        vsota = vsota + arr[i];
    }
    printf("%d\n", vsota);

    return 0;
}
