#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {

    int jeInt = 1;
    int zacetek = 1;
    int samoNula = 0;
    int niz;
    
    while ((niz = getchar()) != '\n') {
        
        if (niz == ' ' || niz == '\n') {
            putchar(jeInt + '0');
            //printf("%d", jeInt);
            
            jeInt = 1;
            zacetek = 1;
            samoNula = 0;

        } else {
            if (zacetek) { //preverjam ce je prva cifra 0
                if (niz == '0') samoNula = 1;
                else if (niz >= '1' && niz <= '9') samoNula = 0;
                else jeInt = 0;
                
                zacetek = 0;

            } else { //preverjam ce je int
                if (samoNula) jeInt = 0;
                if (!isdigit(niz)) jeInt = 0;
            }
        }

    }

    return 0;  
}
