
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "bbbababababaabbababaaaabaaababaabaabaaaaabbbbaabaaaaaababbbabbbaaabababbaabaaabbabaaabbaababbaabbabbabaaaababbbbbbb";

char* VZORCI[] = {
    "bbbababab*baabbababaaaabaabbabaabaabaaaaabbbbaabaa*b*babbbaaaba*baba*baaba*baaaababbbbabb",
    "bbb*baaaabaaabab*ab*bbabbbaaabababbaabaaabbaba*ababbaabbabbab*bbbb",
    "bb*a*ababaabbabab*baabaaaaabbbbaab*a*ababbbabbbaaabababbaabaaabbabaa*babbaabbab*baaaa*bb",
    "bbbababa*babaaa*bbbaabaaaaaaba*aa*baaa*babbaabbabbabaaaababbbbbbb",
    "bbb*abbababaaaabaaabab*a*aaabbaababbaabbabba*abbbb*bb",
    "bbbababababaabba*aaaabbbbaab*aabababbaabaaabbabaaabba*bbbbbbb",
    "bb*babababaa*babaaaabaaababaabaabaaa*aabaaaabababbbabbbaaab*abbaabaaabbabaaabbaababbaabb*baaaa*aabbbbbb",
    "bbbababababaabb*aababbb*aabbabaaabbaaba*ababbbbbbb",
    "bbbababa*ababaaaa*abbaaba*abbaba*babbbbbbb",
    "bbbababababa*aaababaa*aaba*bb*aa*aababbb*baabaaabbaba*bbabaaaababbbbbbb"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
