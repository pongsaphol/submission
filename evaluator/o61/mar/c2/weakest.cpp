#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5 + 5;

int n, par[N], rot[N], spi[N], pos[N], dep[N], t[N<<1];
vector<pii> g[N];

int dfs(int u, int p) {
	int sz = 1;
	if(u == 0) dep[u] = 1, par[u] = 0;
	else dep[u] = dep[p] + 1, par[u] = p;
	pii z(-1, -1);
	for(auto v : g[u]) if(v.x != p) {
		int ret = dfs(v.x, u);
		if(ret > z.x) z = make_pair(ret, v.x);
		sz += ret;
	}
	spi[u] = z.y;
	return sz;
}

void dfs1(int u, int p) {
	for(auto v : g[u]) if(v.x != p) {
		t[pos[v.x] + n] = v.y;
		dfs1(v.x, u);
	}
}

void hld() {
	dfs(0, 0);
	for(int i = 0, idx = 0; i < n; ++i) {
		if(spi[par[i]] != i) {
			for(int j = i; j != -1; j = spi[j]) {
				rot[j] = i;
				pos[j] = idx++;
			}
		}
	}
	dfs1(0, 0);
	for(int i = n-1; i != 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

int tquery(int l, int r) {
	int mx = 1e9;
	for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if(l&1) mx = min(mx, t[l++]);
		if(r&1) mx = min(mx, t[--r]);
	}
	return mx;
}

int query(int a, int b) {
	int mx = 1e9;
	while(rot[a] != rot[b]) {
		if(dep[rot[a]] < dep[rot[b]]) {
			mx = min(mx, tquery(pos[rot[b]], pos[b]));
			b = par[rot[b]];
		} else {
			mx = min(mx, tquery(pos[rot[a]], pos[a]));
			a = par[rot[a]];
		}
	}
	if(dep[a] < dep[b]) mx = min(mx, tquery(pos[a] + 1, pos[b]));
	else mx = min(mx, tquery(pos[b] + 1, pos[a]));
	return mx;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, w; scanf("%d %d", &u, &w);
		g[u].emplace_back(i, w);
	}
	hld();
	int q, k, m, a1, a2;
	scanf("%d %d %d %d %d", &q, &k, &m, &a1, &a2);
	while(q--) {
		int ans = query(a1, a2);
		int na1 = a2, na2 = (((long)a2 * k + ans) % m) % n;
		a1 = na1, a2 = na2;
		printf("%d\n", ans);
	}
}