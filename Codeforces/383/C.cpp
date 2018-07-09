#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int n, m, c[2], A[MAXN], pos[MAXN], dep[MAXN], par[MAXN], t[2][MAXN], d[2][MAXN];
vector<int> g[MAXN];
void dfs(int u, int p) {
	par[u] = p;
	d[dep[u] = dep[p]^1][u]++;
	for(auto v:g[u]) if(v != p) {
		dfs(v, u);
		d[0][u] += d[0][v], d[1][u] += d[1][v];
	}
	pos[u] = ++c[dep[u]];
}

void update(int t[], int x, int v) {
	for(int i = x; i != 0; i -= i&-i) t[i] += v;
}

int query(int t[], int x) {
	int v = 0;
	for(int i = x; i <= n; i += i&-i) v += t[i];
	return v;
}

void upd(int a, int b) {
	update(t[dep[a]], pos[a], b);
	update(t[dep[a]], pos[a] - d[dep[a]][a], -b);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) update(t[dep[i]], pos[i], A[i]), update(t[dep[i]], pos[i]-1, -A[i]);
	while(m--) {
		int met, a, b;
		scanf("%d %d", &met, &a);
		if(met == 1) {
			scanf("%d", &b);
			upd(a, b);
			for(auto v:g[a]) if(v != par[a]) upd(v, -b);
		} else printf("%d\n", query(t[dep[a]], pos[a]));
	}
}