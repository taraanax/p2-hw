#include <stdio.h>
#include <stdlib.h>

int sumMnoz(int n, int m);

int main() {

    int n;
    int m;
    scanf("%d %d", &n, &m);

    printf("%d\n", sumMnoz(n, m));

    return 0;
}

int sumMnoz(int n, int m) {
    
    if (n == 0) return 1;
    if (n < 0) return 0;
    int count = 0;

    for (int b = m; b <= n; b++) {
        for (int a = 1; a < b; a++) {
            count = count + sumMnoz(n - a*b, m);
        }
    }
    return count;
}