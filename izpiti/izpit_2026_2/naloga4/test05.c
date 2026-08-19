
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "aabbcbccbccdccadcbabadddddbcbacbdcadacddcaaddcccdcaddbcbdabbbdbaabccaccacaadccbacbdcadccbdabbbccbbaddbdbaabcbdacddbaccababadaabcadbbdbbccddcdbbabaabddaccc";

char* VZORCI[] = {
    "aabbcbc*ccdccadcbabadddddbcb*dbcb*abbbb*cbacbdcadccbdabbbccbbadd*db*abc*dacdd*badaabcadbbdbdccddcdbbabaabddaccc",
    "aabbcbccbccdcbadcbabad*cc*aaccbd*ccababadaabcadb*c",
    "aabbcbccbccdccadcbabadddddb*caaddcccdcadd*dabb*aabccacc*a*abcbdacddbacca*cddcdbbabaabddaccc",
    "aabbcbccbccdccadcbabadddddbcbacbdcadacd*addbcbdabbbdba*acaadccbacbdcadccbdabbbccb*baabcbdacddbaccababadaabcadbbdbbccddcdbbabaabddaccc",
    "aabbcbccbccdccadcba*bacbdc*cddcaa*adbaabcc*cad*abbbc*dbabbcbd*ac*babadaa*bbdbbccddcd*abddaccc",
    "aabbcbccbccdcca*babaddd*ddcaad*caddbcbdabbbdb*bc*ccbacb*abcb*cddbaccab*b*bddaccc",
    "aab*ccbccdc*c*acddcaaddcccdcaddbcbdabdbdbaabccaccacaad*bdcad*cbbabbbccbba*a*cca*a*ddaccc",
    "aabbcbcb*cdccadcbabadddddbcbacbdcadacdd*cbd*bccaccacaadccbacbdcadccbdabbbccbba*abcbdacddca*ccc",
    "aab*adddddb*bcadbbdbc*",
    "a*c*dddddbcbacbdcadacddcaa*bbbdbaabccaccaca*bacbdc*dccbdabbbcc*cb*bccddcdbaa*cc"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
