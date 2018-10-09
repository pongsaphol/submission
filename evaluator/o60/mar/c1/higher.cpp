#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;

int n, k, t[MAXN<<1];

void update(int x, int v) { for(t[x += n] = v; x != 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]); }
int f(int x) {
	if(x < 0) return 0;
	if(x >= n) return n-1;
	return x;
}
int query(int l, int r) {
	int mx = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) mx = max(mx, t[l++]);
		if(r&1) mx = max(mx, t[--r]);
	}
	return mx;
}

int main() {
	scanf("%d %d", &n, &k);
	while(k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		update(a, b);
		int l = 0, r = n;
		while(l < r) {
			int m = (l + r + 1) >> 1;
			if(query(f(a-m), f(a+m)) == b) l = m;
			else r = m - 1;
		}
		printf("%d\n", l);
	}
}
