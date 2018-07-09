#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, A[MAXN];

int query(int l, int r) {
	if(r <= n) return A[r] - A[l-1];
	else return A[n] - A[l-1] + A[r-n];
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		A[i] += A[i-1];
	}
	int a, b;
	scanf("%d %d", &a, &b);
	int sz = b-a;
	b--;
	int mx = 0, ans = 1000000;
	for(int i = 1; i <= n; ++i) {
		int now = query(i, i + sz - 1);
		int t = a - i + 1;
		if(t <= 0) t += n;
		if(now == mx) ans = min(ans, t);
		if(now > mx) {
			mx = now;
			ans = t;
		}
	}
	printf("%d\n", ans);
}