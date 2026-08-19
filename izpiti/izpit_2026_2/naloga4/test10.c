
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "abacabcbacacbbbabbababbabbbbaaaabbbabbbcabbabccaabababaccababaaccbbcbbcacaaccaaaaaccbcabaaccbacacbcbbbcbcccaaaaaccbbacccbabcaccbaccccbcbacbbbbabbbbb";

char* VZORCI[] = {
    "aba*abbababbabbbbaaaabbbabbb*bababacbc*bcccaaaaaccbbacccba*caccbaccc*bbabbbbb",
    "aba*c*bbbabbab*bb*caaabbbabbbcabbabccaab*ababaaacbbcbbcacaacca*aaccbcabaaccbacac*aaa*ccbabcaccbac*bbabbbbb",
    "a*acab*ab*cababaaccbbcbbcacaaccaa*bcab*bacacbcbbbc*cbabcaccb*bcbacbbbbabbbbb",
    "cbaca*ab*aaccaa*aaccbac*ccbbaccababcaccbaccccbcbacbbbbabbbbb",
    "*b**bbabb*aaabbbabaabaccababaa*aacc*aaaccbcabaa*bcbb*aaaa*cccbcbacbbbbabbbbb",
    "abacabcbacacbbbabbabcbbab*bbbcabbaba*cc*ccbacac*ccbcbacbbbbabbbbb",
    "a*a*b*b*aa*bbabc*ababacca*baacc*ccbabcac*ccbcbacbb*bbbbb",
    "abacabcbacacbbbabbababbabbbbaaaabb*ababaccababaaccb*cbbcacaaccaaaaaccbcabaaccbacacbcbbbcbcc*ccbaccccbcbacbbbbabbbbb",
    "ab*babbababbab*baaa*abbbcabbabcaac*acacbcbbbcb*bbbbabbbbb",
    "abacabcbacacbbbabbababbabbb*abbabccaabababa*abaaccbbcb*b*ccbcbacbbbbabbbbb"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
