#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, A[MAXN], pv[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		pv[i] = ((A[i] == A[i-1]) ? pv[i-1] : i-1);
	}
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(A[b] != c) printf("%d\n", b);
		else if(pv[b] >= a) printf("%d\n", pv[b]);
		else printf("-1\n");
	}
}