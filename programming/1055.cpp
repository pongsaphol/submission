#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int n, m, A[MAXN], chk[MAXN], ans[MAXN], p;

void add() {
	while(1) {
		p++;
		p %= n;
		if(chk[p] == 0) break;
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	for(int i = 0; i < n; ++i) {
		int now;
		scanf("%d", &now);
		while(now--) add();
		ans[i%m] += A[p];
		chk[p] = 1;
		if(i != n-1) add();
	}
	for(int i = 0; i < m; ++i) printf("%d\n", ans[i]);
}