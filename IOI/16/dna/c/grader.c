#include "dna_c.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char s[1001];
static int tests;

static char ss[2002];
static int pr[2002];

int make_test(char* p) {
	int plen = (int)strlen(p);
	int slen = (int)strlen(s);
	if (plen > slen) {
		return 0;
	}
	for (int i = 0; i < plen; i++) {
		if (p[i] != '0' && p[i] != '1') {
			return 0;
		}
	}
	strcpy(ss, p);
	strcat(ss, "#");
	strcat(ss, s);
	int sslen = slen + plen + 1;
	tests++;
	pr[0] = -1;
	int answer = 0;
	for (int i = 1; i <= sslen; i++) {
		int k = pr[i - 1];
		while (k >= 0 && ss[k] != ss[i - 1])
			k = pr[k];
		pr[i] = k + 1;
		if (pr[i] == plen) {
			answer = 1;
			break;
		}
	} 
	return answer;
}

int main() {
    int t;
    scanf("%s", s);
    scanf("%d", &t);
    char* ans = analyse((int)strlen(s), t);
    printf("%d\n", tests);
    printf("%s\n", ans);
    return 0;
}
