#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1<<19;

int n, m, idx, d[MAXN], A[MAXN], pos[MAXN], rpos[MAXN];
long t[MAXN<<1], lz[MAXN<<1];
vector<int> g[MAXN];

int dfs(int u, int p) {
	for(auto v : g[u]) if(v != p) d[u] += dfs(v, u);
	pos[u] = ++idx;
	rpos[idx] = u;
	return ++d[u];
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = (1ll << A[rpos[l]]);
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
	t[p] = t[p << 1] | t[p << 1 | 1];
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] = lz[p];
		if(l != r) lz[p << 1] = lz[p << 1 | 1] = lz[p];
		lz[p] = 0;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p << 1, l, m), travel(x, y, f, p << 1 | 1, m + 1, r);
	t[p] = t[p << 1] | t[p << 1 | 1];
}

void update(int x, int v) {
	travel(pos[x] - d[x] + 1, pos[x], [&](int p, int l, int r) {
		t[p] = (1ll << v);
		if(l != r) lz[p << 1] = lz[p << 1 | 1] = (1ll << v);
	});
}

int query(int x) {
	long now = 0;
	travel(pos[x] - d[x] + 1, pos[x], [&](int p, int l, int r) {
		now |= t[p];
	});
	int cnt = 0;
	for(; now; now >>= 1) if(now&1) cnt++;
	return cnt;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0);
	build();
	while(m--) {
		int a, b, c;
		scanf("%d %d", &a, &b);
		if(a == 1) {
			scanf("%d", &c);
			update(b, c);
		} else printf("%d\n", query(b));
	}
}