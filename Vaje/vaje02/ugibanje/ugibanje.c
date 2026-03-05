#include <stdio.h>

int povprecje(int a, int b){
    return (a + b)/2;
}

int main() {

    int a;
    int b;

    scanf("%d%d", &a, &b);

    int odgovor = 67;
    int guess = povprecje(a, b);

    while (scanf("%d", &odgovor) == 1) {
        if (odgovor == 0) {
            if (a > b){
                printf("PROTISLOVJE");
                return 0;
            } else {
                printf("%d", guess);
                return 0;
            }  
        }

        if (odgovor == 1) a = guess + 1;
        
        if (odgovor == -1) b = guess - 1;

        guess = povprecje(a, b);

    }

    if (a == b) printf("%d", guess);

    if (a > b) printf("PROTISLOVJE");

    if (a < b) printf("%d %d", a, b);
    

    return 0;
}
