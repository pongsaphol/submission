#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17, M = 1e9+9;

int n;
int t[N<<1], lz[N<<1], p2[N];
int par[N], rot[N], spi[N], dep[N], pos[N];
vector<int> g[N];

void pushlazy(int p, int l, int r) {
	t[p] = (1ll * t[p] * p2[lz[p]]) % M;
	if(l != r) lz[p<<1] += lz[p], lz[p<<1|1] += lz[p];
	lz[p] = 0;
}

void updatet(int x, int y, int p = 1, int l = 1, int r = n) {
	pushlazy(p, l, r);
	if(x <= l and r <= y) {
		lz[p]++; pushlazy(p, l, r);
		return;
	}
	if(x > r or l > y) return;
	int m = (l + r) >> 1;
	updatet(x, y, p << 1, l, m), updatet(x, y, p << 1 | 1, m+1, r);
	t[p] = (t[p << 1] + t[p << 1 | 1]) % M;
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
	t[p] = (t[p << 1] + t[p << 1 | 1]) % M;
}

int dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u] = p;
	int sum = 1;
	pii ret(0, -1);
	for(auto v : g[u]) if(v != p) {
		int now = dfs(v, u);
		if(now > ret.x) ret = pii(now, v);
		sum += now;
	}
	spi[u] = ret.y;
	return sum;
}

void hld() {
	spi[n] = -1;
	dfs(0, n);
	for(int i = 0, id = 0; i < n; ++i) if(spi[par[i]] != i) {
		for(int j = i; j != -1; j = spi[j]) rot[j] = i, pos[j] = ++id;
	}
}

void update(int a, int b) {
	while(rot[a] != rot[b]) {
		if(dep[rot[a]] < dep[rot[b]]) swap(a, b);
		updatet(pos[rot[a]], pos[a]);
		a = par[rot[a]];
	}
	if(pos[a] > pos[b]) swap(a, b);
	updatet(pos[a], pos[b]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	p2[0] = 1;
	for(int i = 1; i < N; ++i) p2[i] = (p2[i-1] << 1) % M;
	hld();
	fill(t, t + (N<<1), 1);
	build();
	int q, e; scanf("%d %d", &q, &e); q += e;
	while(q--) {
		int met, a, b; scanf("%d", &met);
		if(met) printf("%d\n", t[1]);
		else {
			scanf("%d %d", &a, &b);
			update(a, b);
		}
	}
}