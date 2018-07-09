#include <bits/stdc++.h>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 1 << 17;

long n, A[N], qs[N];
pii t[N << 1];

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }

void update(int x, int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p].y++;
		t[p].x += l;
		return;
	}
	int m = (l + r) >> 1;
	if(x <= m) update(x, p << 1, l, m);
	else update(x, p << 1 | 1, m + 1, r);
	t[p] = add(t[p<<1], t[p<<1|1]);
}

pii query(int x, int y, int p = 1, int l = 1, int r = n) {
	if(x <= l and r <= y) return t[p];
	if(x > r or l > y) return pii(0, 0);
	int m = (l + r) >> 1;
	return add(query(x, y, p<<1, l, m), query(x, y, p<<1|1, m+1, r));
}

void brute_force() {
	puts("----------------");
	for(int i = n; i != 0; --i) {
		long rhs = 1ll * i * (i-1);
		for(int k = i+1; k <= n; ++k) rhs += min(1ll*i, A[k]);
		printf("%lld %lld\n", qs[i], rhs);
	}
	puts("----------------");
}

bool solve() {
	fill(t, t+N+N, pii(0, 0));
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", A+i);
	sort(A+1, A+n+1, greater<long>());
	// for(int i = 1; i <= n; ++i) printf("%lld ", A[i]);
	// puts("");
	for(int i = 1; i <= n; ++i) qs[i] = qs[i-1] + A[i];
	if(qs[n] % 2) return false;
	// brute_force();
	for(long i = n; i != 0; --i) {
		auto ret = query(1, i);
		long lhs = qs[i], rhs = i*(i-1) + ret.x + (n-i-ret.y)*i;
		// printf("%lld %lld\n", lhs, rhs);
		if(lhs > rhs) return false;
		update(A[i]);
	}
	
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) puts(solve() ? "Yes" : "No");
}