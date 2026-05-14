#include <stdio.h>
#include <stdlib.h>

void pretvori(int** t);

int main () {



    return 0;
}

void pretvori(int** t) {

    for (int i = 0; t[i] != NULL; i++) {
        for (int j = i + 1; t[j] != NULL; j++) {
            if (t[i] == t[j]){
                //dolzina + nov arr
                int len = 0;
                while (t[i][len] != 0) len++;
                int* nova = malloc((len + 1) * sizeof(int));

                int k = 0;
                while (t[i][k] != 0) {
                    nova[k] = t[i][k];
                    k++;
                }
                nova[k] = 0;
                t[j] = nova;
            }
        }
    }

}