
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "baaabaaaaabaaaabaabaaaaaabbaabaaaaaabababbaabbbbbaababaabbabbabababbababbaaaaabbaabbabbaaabababaaaaabaaabaabbba";

char* VZORCI[] = {
    "b*baaaa*ab*aaaabba*ba*abbaabb*abab*babbabababba*baabbabb*baaa*a",
    "baaabaaaaa*aabaabaaaaaabbaa*aaaba*bb*ab*babbababbaab*aaaaabab*a*ba",
    "b*a*ba*babbababbaaaaabbaabbabbaaa*b*baabbba",
    "baaabaaaaab*a*abbaabaaaaa*baab*bbaababaaababbabab*aab*b*aaa*aa*bbba",
    "baaabaa*aabaabaaaaaabb*aaaaba*bbbbbaabab*abbabbabab*ababbaa*aabaaaaabaaaba*a",
    "baaab*abaabaaaaaabbaa*babba*baababaa*babbaaaaabb*babaa*aabbba",
    "baa*baaa*aaaab*aba*bbbbbaa*abbabbabababbababbaaaaab*abbabbaaabababaaaa*aaab*bba",
    "*aa*aabaaa*aaa*bbaaba*aabbbbbaabab*abbabababbaba*aabbaabba*babaa*b*ba",
    "baaa*b*aaaaaab*bbaabbbbbaababaabbabb*ababbababbaaaa*bbaa*abababaaaaabaaa*ba",
    "baa*a*a*a*aabaaaaaabababbaa*b*ba*aabbabbbaaaaa*aaabab*ba*abbba"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
