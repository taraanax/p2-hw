#include <stdio.h>

int main() {

    int n = getchar() - '0';
    getchar();

    int b;
    int count = 0;

    for (int i = n; i > 0; i--) {
        if (i==n) b = getchar() - '0';
        getchar();

        int a = getchar() - '0';
        if (a != b) {
            printf("%d\n", count);
            printf("0");
            break;
        } else count = count + 1; 

        if (count == n-1) {
            printf("1");
            break;
        }

        
    }
    
    return 0;
}