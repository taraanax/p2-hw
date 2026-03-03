#include <stdio.h>
#include <stdbool.h>

int readint();
int dolzina(int stevilo);
int poStevkah(int stevilo);
int powie(int osnova, int eksponent);


int main() {

    int a  = readint();
    int b = readint();
    int vsota = a + b;

    //printf("%d\n", poStevkah(vsota));
    //printf("po stevkah: %d\n", poStevkah(1234));
    poStevkah(vsota);

    return 0;  
}

int readint() {
    
    int c;
    int i = 0;
    int predznak = 1;

    while (true) {
        c= getchar();

        if (c == '-') {
            predznak = -1;
        }

        if(('0' <= c) && (c <= '9')) {
            i = i * 10 + (c - '0');
        }
        if (c == '\n') break;
    }

    return i*predznak;
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
