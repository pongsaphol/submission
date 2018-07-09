#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int n, m, len, pv, memo[2][MAXN];
char A[MAXN], B[MAXN], cc[MAXN];

int f(int x) { return x - 'a' + 1; }
int l(int x) { if(x < 0) return n; return x;}
void rabin(int &p, int idx, int ret) {
	int h1, h2, hd = 1, sz = ret - pv; h1 = h2 = 0;
	for(int i = 0; i < p; ++i) {
		h1 = (h1 * 31) + f(A[i]);
		h2 = (h2 * 31) + f(cc[i]);
		hd = (hd * 31); 
		if(i + 1 == p) 
		if(i >= ret-1) if(memo[(idx-1)&1][l(i - sz)] == idx - 1 && h1 == h2) memo[idx&1][i] = idx;
	}
	for(int i = p; i < n; ++i) {
		// printf("%d %d\n", h1, h2);
		h1 = (h1 * 31) - hd * f(A[i-p]) + f(A[i]);
		if(i >= ret-1) if(memo[(idx-1)&1][l(i - sz)] == idx - 1 && h1 == h2) memo[idx&1][i] = idx;
	}
	pv = ret;
	cc[p] = '\0';
	// printf("%d %s\n", sz, cc);
	p = 0;
}

void solve() {
	memset(memo, 0, sizeof memo);
	pv = 0;
	scanf("%d %s", &len, B);
	// I will solve with rabin karp
	int p = 0, idx = 0;
	while(len != 0 && B[len-1] == '?') len--, n--;
	B[len] = '?';
	for(int i = 0; i <= len; ++i) {
		if(B[i] == '?' && p) rabin(p, ++idx, i);
		else if(B[i] != '?') cc[p++] = B[i];
	}
	// printf("-> %d\n", idx);
	if(!idx) for(int i = 0; i < len-1; ++i) memo[0][i] = -1;
	printf("%d\n", count_if(memo[idx&1], memo[idx&1] + n, [&](int i) { 
		return i == idx; 
	}));
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	scanf("%s", A);
	A[n] = -1;
	int cn = n;
	while(m--) {
		n = cn;
		solve();
	}
}