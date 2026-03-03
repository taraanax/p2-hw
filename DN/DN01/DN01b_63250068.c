#include <stdio.h>
#include <stdbool.h>

int dolzina(int stevilo);
int poStevkah(int stevilo);
int powie(int osnova, int eksponent);


int main() {

    //branje, dobivanje dolzine in št. enic
    int c = 0;
    int enice = 0;
    int dolzina = 0;
    bool zacelo = false;

    while ((c= getchar()) != '\n') {
        if (!zacelo) {
            if (c == '1') {
                zacelo = true;
                dolzina = dolzina + 1;
                enice = enice + 1;
            }
        }else{
            dolzina = dolzina + 1;
            if (c == '1') enice = enice + 1;
        } 
    }
    
    printf("enice: %d\n", enice);
    printf("dolzina: %d\n", dolzina);
    
    //logaritem pri potencah z osnovo 2
    if (enice == 1) {
        poStevkah(dolzina - 1);
    //logaritem pri usem drugem
    } else {
        poStevkah(dolzina);
    }

    return 0;  
}


int poStevkah(int stevilo) {
    int predznak = 1;

    int stevka = 0;
    int ostanek = 0;
    if (stevilo < 0) {
        predznak = -1;
        stevilo = stevilo*predznak;
        putchar('-');
    }

    for (int i = dolzina(stevilo) ; i > 0; i--) {
        //printf("i: %d\n", i);
        
        ostanek = stevilo % powie(10, i);
        stevka = ostanek / powie(10, i-1);
       //printf("stevka: %d\n", stevka);
        putchar(stevka + '0');
        //stevilo = stevilo - stevka*powie(10, i);
        
    }
    return 0;
}

int powie(int osnova, int eksponent) {
    int rezultat = osnova;
    if (eksponent== 0) return 1;
    for (int i = 1; i < eksponent; i++) {
        rezultat = rezultat * osnova;
    }
    return rezultat;
}

int dolzina(int stevilo) {
    int dolzina = 1;

    for (int i = 1; i > 0; i++) {
        if (stevilo % powie(10, i) == stevilo) {
            dolzina = i;
            //printf("dolzina: %d\n", i);
            return dolzina;
        }
    }
}