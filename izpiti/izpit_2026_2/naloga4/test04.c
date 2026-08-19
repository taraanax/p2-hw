
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "dcddbcbbaadcbaadadadbabaaacbdabcdcbcbbbbdcbcaddaabcadcdddbdadbcbbddcaddacacbabcacbbbbbdabacccdbaabccdbcdbdcaaddcabcaccbcacaddaaaaccdadacdddbadd";

char* VZORCI[] = {
    "*cb*a*cb*bbdcbcaddaabcadcdddbdadbcbbddcaddacacbabcacb*bbcdbdcaadd*accbcacaddaaaaccdadacdd*dd",
    "dcddbcbbaadcbdadadad*dcbcaddaabcadcdddbdadbcbbddcadda*a*bbbdabacccdbaabccdbcdbdcaa*ddaaaaccdadacdadbadd",
    "d*dbcbbaadcbaadad*abaaacbdab*dcbcaddaabcadcdddbdadbcb*cadda*a*ba*a*bb*dabacccdbaabccdbcdbdcaaddcabcaccbcacaddaaaacc*add",
    "dcddbcbb*ba*aaacbdabcdcbcbbbbd*ad*d*b*badd",
    "dcddbcbbaadcbaadadadbabaaac*dcbcadda*b*d*da*cbbddcad*cdbaabccdbc*caaddca*a*cdddbadd",
    "dcddbcbbaadcbaadadadba*b*addacacbabcacbbbbbdaba*cdbaabccd*dbdca*daaaaccdadacdddbadd",
    "dcddb*aadadadbab*bcdcb*aabc*cbbddcaddaca*bcac*bbbd*baccc*baabccdbcdbdca*ddcabcac*d",
    "dc*babaaa*bdabcdcbcbbbbdcbcaddaabcadcdddbdadbcbbd*addaaaaccdadacdddbadd",
    "dcddbcbbaaccbaadadadbabaaacbdab*ddbcad*ddbdad*bbddcadd*a*cd*addcabcaccbcacaddaaaaccdadacdddbadd",
    "bcddbc*dabcdcbcbbbddcbc*dd*dbcbbddcadda*cbbbbbdabacccdbaabc*dca*ddaaaa*add"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
