#include <stdio.h>
#include <math.h>


int main() {

    int m;
    int n;

    scanf("%d%d", &m, &n);

    int steviloc = 0;
    int b = 1; 

    for (int c = m; c <= n; c++) {
        int count = 0;
        
        for (int a = 1; a < c && !count; a++) {
        /* O(n^3) scary shit
            b = a;
            while (b < c) {
                if ((a*a + b*b) == c*c) {
                    steviloc = steviloc + 1;
                    count = 1;
                    break;
                } 
                b++;
            }
            a++;
        */
        //preverjam, če je popoln kvadrat
            int b2 = c*c - a*a;
            int b = sqrt(b2);

            if (b > 0 && b*b == b2) {
                steviloc++;
                count = 1;
            }
        }
    }
    
    printf("%d\n", steviloc);

    return 0;
}