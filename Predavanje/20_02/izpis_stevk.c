#include <stdio.h>
#include <stdbool.h>

int readint() {
    
    int c;
    int i = 0;

    while (true) {
        c= getchar();
        printf("[%d]\n", c);

        if(('0' <= c) && (c <= '9')) {
            i = i * 10 + (c - '0');
        }
        else break;
    }

    return i;
}

int main() {
    
    int i = readint();
    
    printf("int = %d \n", i);

    return 0;
}