#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


    int pari(int* desno, int* levo, int count, int k){
        
        /*if (n == 1) return count;
        if (arr[0] > arr[n-1]) return count;

        if ((arr[0] + arr[n-1]) == k) {
            //printf(" (%d, %d) ", arr[0], arr[n-1]);
            return pari(n - 1, arr, count + 1, k);
        } 
        
        else if ((arr[0] + arr[n-1]) > k){
            return pari(n-1, arr, count, k);
        } 
        
        else if ((arr[0] + arr[n-1]) < k) {
            return pari(n, arr + 1, count, k);
        }
*/

        


        return 0;
    }

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
    
    int count = 0;
    int* end = arr + (n - 1);
    int sum = pari(end, arr, count, k);
    
    printf("%d\n", sum);

/*debugging
    printf(" \n");

    

    printf("arr: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
*/
    return -1;
}