#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int m;
    scanf("%d %d", &n, &m);

    int a = 1;

    return 0;
}

int sumMnoz(int n, int m, int a) {
    int b = m;
    if (n == 0) return 1;
    if (n < 0 || a > b) return 0;
    int count = 0;

    while (b <= n) {
        if (a < b) {
            count = count + sumMnoz(n - a*b, b, a + 1);
        }
        b++;
    }
    return count;
}