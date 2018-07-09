#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
long t[MAXN << 1];

long query(long x) {
	long mx = 0;
	for(long l = n, r = n+x; l < r; l >>= 1, r >>= 1) {
		if(l&1) mx = max(mx, t[l++]);
		if(r&1) mx = max(mx, t[--r]);
	}
	return mx;
}

void update(int x, long v) {
	for(t[x += n] = v; x != 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n); 
	for(int i = 0; i < n; ++i) {
		scanf("%lld", t + i + n);
	}
	for(int i = n-1; i != 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
	scanf("%d", &m);
	while(m--) {
		long a, b;
		scanf("%lld %lld", &a, &b);
		long ret = query(a);
		printf("%lld\n", ret);
		update(0, b + ret);
	}
}