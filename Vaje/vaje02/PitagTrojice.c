#include <stdio.h>
#include <stdbool.h>

int readint();

int main() {

    int m;
    int n;

    //&m <- naslov spodne meje
    scanf("%d%d", &m, &n);
    
    int count = 0;
    int b = 1; 
    int prejsni = -1;

    for (int c = m; c <= n; c++) {
        printf("c: %d\n", c);
        for (int a = 1; a < n; a++) {
            //printf("a: %d\n", a);
            while (b < n) {
                //printf("b: %d\n", b);
                b = 1;
                if ((a*a + b*b) == c*c && b != prejsni) {
                    count = count + 1;
                    printf("count vmes: %d\n", count);
                    prejsni = a;
                }
                b++; 
            }
        }
    }
    
    printf("%d\n", count);

    return 0;
}