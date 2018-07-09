#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5 + 5;

int n, A[MAXN];
P M(1000000007, 1000000009);
P add(P a, P b) { return P(a.x + b.x, a.y + b.y); }
P mul(P a, P b) { return P(a.x * b.x, a.y * b.y); }

int f(int x) { return (x + n) % n;}

bool process(int m) {
	P h1(0, 0), h(1, 1);
	set<P> S;
	for(int i = 0; i < m; ++i) {
		h = mul(h, M);
		h1 = add(mul(h1, M), P(A[i], A[i]));
		S.emplace(h1);
	}
	h = P(-h.x, -h.y);
	for(int i = m; i < n + m - 1; ++i) {
		h1 = add(mul(h1, M), add(P(A[f(i)], A[f(i)]), mul(h, P(A[i-m], A[i-m]))));
		if(S.find(h1) != S.end()) return true;
		S.emplace(h1);
	}
	return false;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", A+i), A[i]++;
	int l = 0, r = n;
	while(l < r) {
		int m = (l + r + 1) >> 1;
		if(process(m)) l = m;
		else r = m - 1;
	}
	if(l == n) return !printf("-1\n");
	printf("%d\n", l);
}