#include <stdio.h>

int main() {

    int n = getchar() - '0';
    getchar();
    int prvo = -1;
    int drugo = -1;

    for (int i = 0; i < n + 1; i++) {
        int stevilo = getchar() - '0';
        getchar();
        
        if (stevilo > prvo) {
            drugo = prvo;
            prvo = stevilo;
            
            //printf(" kr nekje umes %d\n", drugo);
        }
        else if (stevilo == prvo) {
            prvo = stevilo;
        }
        else if (stevilo < prvo && stevilo > drugo) {
            drugo = stevilo;
            //printf(" kr nekje umes %d\n", drugo);
        }
    }
    
    printf("%d\n", drugo);

    
    return 0;  
}
    