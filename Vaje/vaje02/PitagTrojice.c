#include <stdio.h>
#include <stdbool.h>

int readint();

int main() {

    int m = readint();
    //printf("m: %d\n", m);
    int n = readint();
    //printf("n: %d\n", n);
    int count = 0;
    int c = m;
    int a = 1;
    int b = 1; 

    for (int c = m; c <= n; c++) {
        printf("c: %d\n", c);
        a = 1;
        while (a < n) {
            //printf("a: %d\n", a);
            b = 1;
            while (b < n) {
                //printf("b: %d\n", b);

                if ((a*a + b*b) == c*c) {
                    count = count + 1;
                    printf("count vmes: %d\n", count);
                } 
                b++;
            }
            a++;
        }
    }
    
    printf("%d\n", count);

    return 0;
}

int readint() {
    
    int c;
    int i = 0;

    while (true) {
        c= getchar();

        if(('0' <= c) && (c <= '9')) {
            i = i * 10 + (c - '0');
        }
        if (c == ' ') break;
    }

    return i;
}
