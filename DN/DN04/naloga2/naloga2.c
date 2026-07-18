#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {

    //input
    long long n;
    scanf("%lld", &n);

    long long k;
    scanf("%lld", &k);

    int* arr = malloc(n*sizeof(int));
    for (int i = 0; i< n; i++) {
        scanf("%d", &arr[i]);
    }
    
    /*printf("arr: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
    printf(" \n");
    */

    long long count = 0;
    long long levo = 0;
    long long desno = n - 1;

    while (levo < desno) {
        long long sum = arr[levo] + arr[desno];
        
        if (sum == k) {
            //printf("(%d, %d) ", arr[levo], arr[desno]);

            if(arr[levo] != arr[desno]){
                long levoEnaki = 1;
                while (levo + 1 < desno && arr[levo+1] == arr[levo]) {
                    levoEnaki++;
                    levo++;
                }

                long desnoEnaki = 1;
                while (levo < desno - 1 && arr[desno-1] == arr[desno]) {
                    desnoEnaki++;
                    desno--;
                }

                count = count + (desnoEnaki * levoEnaki);
                levo++;
                desno--;

            } else {
                long long m = desno - levo + 1;
                count = count + (m * (m - 1)) / 2;
                break;
            }
            
        } else if (sum > k) {
            desno--;
        } else levo++;
    }
    //printf(" \n");
    printf("%lld\n", count);

    return -1;
}