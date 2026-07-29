#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node {
        int value;
        struct _node* levo;
        struct _node* desno;
    } node;

int main () {

    int n = scanf("%d", &n);

    node* koren = malloc(sizeof(node));
    koren->value = 0;
    koren->levo = scanf("%d", &koren->levo);
    koren->desno = scanf("%d", &koren->desno);
    
    for (int i = 2; i < n; i++)  {
        
    }



    return 0;
}