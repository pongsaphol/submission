#include <stdio.h>
#include <stdlib.h>

#include "laugh_c.h"

char s[100001];

int main() {
	scanf("%s", s);
	int ans = longest_laugh(s);
    printf("%d\n", ans);
    return 0;
}
