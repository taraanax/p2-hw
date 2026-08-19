
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

char* BESEDILO = "bbaabaaaabbbaaaabbbbaabbabbabbaabaaabaabbbbabaaabbbbbbbabaababbaaaaabbbababbabbaaababbbabbbbabaaabbbbaaaabababbbbaababbabbaaaabbbbbbabbabbabbabbbbbaaaabaabaaaabbabbabaaaaabbabbbaaaaababaababaababb";

char* VZORCI[] = {
    "bbaabaaaabbbaaaabbbbaabbabbabbaabaaabaabbbbabaaabbbbbbbabaabab*aaabbbabab*ababbba*aaabbbbaaaabababbbbaababbabb*b*babbbbbaaaabaabaaaabbabb*aaaabbabbb*abaababb",
    "bbaabaaaa*babbaabaaabaabbbbabaa*bbbbabaababbaaaaabbbabab*aabab*abababbbbaab*abbbbbbabbabbabbabbbbbaaaabaa*a*ba*b",
    "bbaabaaaabbbaa*bbbb*abbabbabbaabaaabaabbbbabaaabbbbbbbabaababbaaa*bbbababbabbaaababbbabbbbabaaabbbbaaa*aabab*a*bbbbaaaa*b*abbb*aabab*bb",
    "b*aab*aabbbaaaabbbbaabbabbabba*bbabaaabbbbbbbabaab*bbaaaaabbbababbabbaaababbbabb*aaabbbbaaaabab*bbbbaababbabbaaaabbbbbbabbabbabbab*bbba*babb*abbabbbaaaaababaababaababb",
    "bbaabaaaabbbaaaabbbbaabbabbabbaabaaabaabbbbab*a*bbbabbbbab*aabbbbaaaab*bbbaa*ba*baababaa*b",
    "*bbba*babbaabaaa*aaabbbbbbbabaababbaaaaabbbababbabbaaababbbabbbbaaaaabbbbaaa*aababbabbaaaabbb*bbabbabbabbabbbbbaaaabaabaaaabbabbabaaaaabbabb*aaabbabaababaababb",
    "bbaabaaaabbbaaaabbbbaabbabbabbaabaaabaabbbba*baaababbba*aaaa*ab*aaa*a*aabaabaaaabbabbabaaaaabbabbbaaaa*baababb",
    "bbaabaaaab*bbbabbbbabaaabbbb*abbbb*abbbbbbabbabbabb*ababaababaababb",
    "bbaaba*aabbbaaaabbbbaabbabbabbaabaaabaabbbb*bbbab*aaaba*b*abbaaaabbbbbbabbabbabbabbbbbaaa*abaaaa*babaababb",
    "b*bbbbaab*baab*a*ababbabb*abbaaaabbbbbbabbabbabbabbbbbaaaabaabaaaabb*abb"
};

int main() {
    int stVzorcev = sizeof(VZORCI) / sizeof(VZORCI[0]);
    for (int i = 0; i < stVzorcev; i++) {
        int z = zamenjave(VZORCI[i], BESEDILO);
        printf("%d\n", z);
    }
    return 0;
}
