#include <stdio.h>

int main() {
    
    int a = getchar() - '0';
    getchar();
    int b = getchar() - '0';

    printf("%d\n", (a + b) % 10);

    return 0;
}
