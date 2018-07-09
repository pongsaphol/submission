#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1 << 17;

int n, sz, t[MAXN<<1];
long pref[MAXN];
vector<long> V;

int idx(long x) {
	return lower_bound(all(V), x) - V.begin();
}

void compidx() {
	V.reserve(n+5);
	for(int i = 0; i <= n; ++i) V.emplace_back(pref[i]);
	sort(all(V));
	V.resize(unique(all(V)) - V.begin());
	sz = V.size();
}

void update(int x, int v) {
	for(t[x += sz] = v; x != 0; x >>= 1) t[x>>1] = max(t[x], t[x^1]);
}

int query(int l, int r) {
	int mx = 0;
	for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if(l & 1) mx = max(mx, t[l++]);
		if(r & 1) mx = max(mx, t[--r]);
	}
	return mx;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", pref+i), pref[i] += pref[i-1];
	compidx();
	update(idx(0), 1);
	for(int i = 1; i <= n; ++i) {
		if(i == n) return !printf("%d\n", query(0, idx(pref[i])));
		int now = query(0, idx(pref[i]));
		if(now) update(idx(pref[i]), 1 + now);
	}
}