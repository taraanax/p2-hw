#include <stdio.h>
#include <math.h>

int main() {
    
    printf("Primer 1\n");
    float x = 0.1;
    
    printf("x = %f\n", x);
    printf("x = %30.25f\n", x);
    
    /* zacikla se
    while (x != 1.0)*/
    
    /* lahko gre out of bounds
    while (x < 1.0)*/ 
    
    while (fabs(x - 1.0) >= 0.001) {
        x = x + 0.1;
        printf("x = %f\n", x);
    }
    
    printf("Primer 2\n");
    float y, z;
    x = 2.0;
    y = 3.0;
    z = 4.0;
    
    printf("x + y + z = %f\n", x + y + z);
    printf("x + y + z = %30.25f\n", x + y + z);

    printf("Primer 3\n");
    x, y = 1.0;

    while ( (x + y) + y == x + (y + y)) {
        y = y / 2.0;
    }
    
    printf("x = %30.25f, y = %30.25f\n", x, y);
    printf("x + (y + y) = %30.25f, (x + y) + y = %30.25f\n", x + (y + y), (x + y) + y);

    return 0;
}