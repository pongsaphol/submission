#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

struct data { 
	int l, r, m, s; 
	friend inline data operator+(const data &a, const data &b) {
		data now;
		now.l = max(a.l, a.s + b.l);
		now.r = max(b.r, b.s + a.r);
		now.m = max({a.m, b.m, a.r + b.l});
		now.s = a.s + b.s;
		return now;
	} 
} t[N << 1];
int n, m, A[N];

void build(int p = 1, int l = 0, int r = n-1) {
	if(l == r) {
		t[p].l = t[p].r = t[p].m = t[p].s = A[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m), build(p << 1 | 1, m+1, r);
	t[p] = t[p << 1] + t[p << 1 | 1];
}

void update(int x, int v, int p = 1, int l = 0, int r = n-1) {
	if(x < l || x > r) return;
	if(l == r) {
		t[p].l = t[p].r = t[p].m = t[p].s = v;
		return;
	}
	int m = (l + r) >> 1;
	update(x, v, p << 1, l, m), update(x, v, p << 1 | 1, m+1, r);
	t[p] = t[p << 1] + t[p << 1 | 1];
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	build(); printf("%d\n", t[1].m);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		update(a, b); printf("%d\n", t[1].m);
	}
}