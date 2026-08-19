
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "bbbababbbbaaabbaabbaabaabbababbbaaabbbbbaaaabaabaaaababbbbaababbbbaaaaaabbabbaabababaaaaabbbbbaababbbababbabaaababbbbbabbbaab";

char* VZORCI[] = {
    "bbbababbbbaaabbaabbaabaabb*baabaaa*abbb*aababbbbaaaaaabbabbaabababaaaaabbbbbaabab*abbbb*abbbaab",
    "bbbababbbbaa*bbaa*ababbb*baaaababbaaaabab*aababbbbaaa*aba*aaaaababbbaab*bababba*b",
    "bbbababbbbaaabba*bbaaabbbbbaaaabaabaaaaba*bb*bababbabaaababbbbbabbbaab",
    "bbbababb*bbaaaaaabbabbaabababaaaaabbbbbaaba*ababbabaaab*babbbaab",
    "bbbababbbbaaabbaabbaaba*b*bbbbbaaaabaabaaaababbbba*bbbaaaaaabbabba*baab",
    "*bbaaabbaabbaabaaabababbb*abbb*bbaabaaaababbbbaababbbbaaaaaabba*bbbbbaababb*babaaa*bbbabbbaab",
    "b*bbbaaabbaabbaabaa*bbbba*baaaaa*baabababaa*bbb*ab*abaaababbbbbabbbaab",
    "*ba*aaabbaabbaabaabbababbb*abbbbbaaa*aaba*aababbbbaaba*bbbaaaaaabbabbaabab*baa*bababbabaaabab*bbba*b",
    "*a*bbaaabbaa*bbba*aa*bbbaababbbbaaaaa*bababaaaaabb*aaababbbb*aab",
    "bbbaba*bbbbaaa*abbbbbaababbbababba*aababbbbbabbbaab"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
