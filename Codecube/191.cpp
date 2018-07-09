#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;
char A[2005], B[2005];

pii pw[26], iden(2003, 2007);
pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }

int main() {
	scanf("%s %s", A+1, B+1);
	n = strlen(A+1), m = strlen(B+1);
	for(int i = 1; i <= n; ++i) A[i] -= 'A';
	for(int j = 1; j <= m; ++j) B[j] -= 'A';
	pw[0] = pii(1, 1);
	for(int i = 1; i < 26; ++i) pw[i] = mul(pw[i-1], iden);
	for(int len = min(m, m); len; --len) {
		set<pii> S;
		pii sum1, sum2;
		for(int j = 1; j <= len; ++j) sum1 = add(sum1, pw[A[j]]), sum2 = add(sum2, pw[B[j]]);
		S.emplace(sum1);
		for(int j = len+1; j <= n; ++j) sum1 = add(sum1, sub(pw[A[j]], pw[A[j-len]])), S.emplace(sum1);
		if(S.find(sum2) != S.end()) return !printf("%d\n", len);
		for(int j = len+1; j <= m; ++j) {
			sum2 = add(sum2, sub(pw[B[j]], pw[B[j-len]]));	
			if(S.find(sum2) != S.end()) return !printf("%d\n", len);
		}
	}
	printf("0");
}