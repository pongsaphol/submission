#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17;

int n, k, par[N], rot[N], pos[N], dep[N], spi[N];
vector<vector<int> > g(N);

int dfs(int u, int p) {
	dep[u] = dep[p] + 1, par[u] = p;
	int sz = 1;
	pii ret(0, -1);
	for(auto v : g[u]) {
		int z = dfs(v, u);
		sz += z;
		if(ret.x < z) ret = pii(z, v);
	}
	spi[u] = ret.y;
	return sz;
}

void hld() {
	dfs(1, 0);
	for(int i = 1, id = 0; i <= n; ++i) if(spi[par[i]] != i)
		for(int j = i; j != -1; j = spi[j]) rot[j] = i, pos[j] = ++id; 
}

int t[N<<1][20], lz[N<<1];

void pushlazy(int p, int l, int r) {
	if(lz[p]) {
		lz[p] %= k;
		vector<int> ret(20);
		for(int i = 0; i < k; ++i) ret[(i+lz[p])%k] = t[p][i];
		for(int i = 0; i < k; ++i) t[p][i] = ret[i];
		if(l != r) lz[p<<1] += lz[p], lz[p<<1|1] += lz[p];
		lz[p] = 0;
	}
}

void updt(int x, int y, int p = 1, int l = 1, int r = n) {
	pushlazy(p, l, r);
	if(x <= l && r <= y) {
		lz[p]++, pushlazy(p, l, r);
		return;
	}
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	updt(x, y, p<<1, l, m), updt(x, y, p<<1|1, m+1, r);
	for(int i = 0; i < k; ++i) t[p][i] = t[p<<1][i] + t[p<<1|1][i];
}

void update(int u) {
	while(u) {
		updt(pos[rot[u]], pos[u]);
		u = par[rot[u]];
	}
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) t[p][0] = 1;
	else {
		int m = (l + r) >> 1;
		build(p<<1, l, m), build(p<<1|1, m+1, r);
		t[p][0] = t[p<<1][0] + t[p<<1|1][0];
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 2, v; i <= n; ++i) {
		scanf("%d", &v);
		g[v].emplace_back(i);
	}
	hld();
	build();
	update(1);
	for(int i = 2; i <= n; ++i) {
		update(i);
		if(i % k) {
			puts("NO");
			continue;
		}
		puts(((t[1][0] - n + i) == i/k) ? "YES" : "NO");
	}
}