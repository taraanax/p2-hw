#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node {
        struct _node* levo;
        struct _node* desno;
    } node;

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int visina (node* koren) {
    if (koren == NULL) return 0;
    return 1 + max(visina(koren->levo), visina(koren->desno));
}

int main () {

    int n; 
    scanf("%d", &n);
    
    node* vozlisca[1000];
    for (int i = 0; i < n; i++) {
        vozlisca[i] = malloc(sizeof(node));
        vozlisca[i]->levo = NULL;
        vozlisca[i]->desno = NULL;
    }

    for (int i = 0; i < n; i++) {
        int l, d;
        scanf("%d %d", &l, &d);

        if (l != -1) vozlisca[i]->levo = vozlisca[l];
        
        if (d != -1) vozlisca[i]->desno = vozlisca[d];
    }

    node* koren = vozlisca[0];

    int dolzina = visina(koren);
    printf("%d", dolzina);



    return 0;
}