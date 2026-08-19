
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "caccbabbbcccccabccbaaaaabbbbabacaaabccacbabacbabacbbbcacaacccbcacbcabaabbaacabccbbcabcbbcaacbacaaccbacabcababcccccbcaabccabcabacaabcacacbaabcbbbccaacbbabcbbaabcbcbbbbbbcccbcaaccccbccccbccca";

char* VZORCI[] = {
    "caccbabbbccccc*bccacbabacbabacbbbcacaacccbcacbcabaabbaacabccbbcabcbbcaacbaca*bcabacaabcacacbaa*acbbabcbbaabcbcbbbbb*cbcaaccccbccccbccca",
    "caccbabbbcccccabccbaaaaabbbbabacaaabccac*bcabcbbca*cabcababccbccbcaabccab*cacbaabccbbccaacbb*ccbccccbccca",
    "caccbabbbcccccabccbaa*caaabccacbabacbabacbbbcaca*b*b*a",
    "caccba*a*bcacaacccb*cabaabbaacabccb*ca*acbc*ccbccca",
    "caccbabbbcccccabccbaaaaabbb*abacaaabccacbabacbabacbbbcacaacc*cbbcaacbacaaccbacabcababcccccbcaabccabcabacaabcacacbaabcbb*acbbabcbbaabcbcbbbbbbcccbcaaccccbccccbccca",
    "caccbabbbcccccabccbaaaaabbbbabacaaabccacba*bbcaca*cbcaba*cbaca*cabcababcccc*caa*acbbabcbbaabcbcbbbbb*ccbccca",
    "caccbabbbcccccabc*c*acccbcacbcabaabbaacabccbbcabcbbcaacbacaaccbacabcababc*ccbcaabccabcabac*cacacbaabcbbbccaacbbabcbbaabcbcbbbbbbcccbcaaccccbccccbccca",
    "c*ccabccb*bab*abacb*acbb*cacbcabaabbaacabccbbcab*acbacaacabaca*aba*bcabccaabc*c*ccbccccbccca",
    "caccbabbbccccc*baaaaabbbbabacaaabccacbabacbabacbbbcacaacccbcac*aacabccbbcabcbbcaacbacaaccbacabcababcccc*bccabcabacaab*acbaabcbbb*cbcaaccccbccccb*ca",
    "cac*bbbcc*abbbb*aabc*bbcacaaccc*cabccb*bcaacbacaaccba*c*bb*cccbcaaccccb*ccca"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
