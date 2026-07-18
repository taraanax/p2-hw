#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {

    //input
    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

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

    int count = 0;
    int levo = 0;
    int desno = n - 1;

    while (levo < desno) {
        int sum = arr[levo] + arr[desno];
        
        if (sum == k) {
            //printf("(%d, %d) ", arr[levo], arr[desno]);

            if(arr[levo] != arr[desno]){
                int levoEnaki = 1;
                while (levo + 1 < desno && arr[levo+1] == arr[levo]) {
                    levoEnaki++;
                    levo++;
                }

                int desnoEnaki = 1;
                while (levo < desno - 1 && arr[desno-1] == arr[desno]) {
                    desnoEnaki++;
                    desno--;
                }

                count = count + (desnoEnaki * levoEnaki);
                levo++;
                desno--;

            } else {
                int m = desno - levo + 1;
                count = count + (m * (m - 1)) / 2;
                break;
            }
            
        } else if (sum > k) {
            desno--;
        } else levo++;
    }
    //printf(" \n");
    printf("%d\n", count);

    return -1;
}