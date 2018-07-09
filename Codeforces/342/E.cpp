#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e5+5;

int n, m, par[N][18], dep[N], dp[N], H[N], ans[N];
vector<int> g[N];
bool chk[N];

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u][0] = p;
	for(int i = 1; i <= 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
	for(auto v : g[u]) if(v != p) dfs(v, u);
}

int d(int u, int v) {
	auto lca = [&](int a, int b) {
		if(dep[a] < dep[b]) swap(a, b);
		for(int i = 17; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
		if(a == b) return a;
		for(int i = 17; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
		return par[a][0];
	};
	return dep[u] + dep[v] - 2*dep[lca(u, v)];
}

int build(int u, int p) {
	dp[u] = 1;
	for(auto v : g[u]) if(v != p and !chk[v]) dp[u] += build(v, u);
	return dp[u];
}

void find(int u, int p, int sz, pii &ret) {
	int mx = sz - dp[u];
	for(auto v : g[u]) if(v != p and !chk[v]) find(v, u, sz, ret), mx = max(mx, dp[v]);
	if(ret.x > mx) ret = pii(mx, u);
}

void build_centroid(int u, int p) {
	int sz = build(u, 0);
	pii ret(sz, -1);
	find(u, 0, sz, ret);
	u = ret.y;
	H[u] = p, chk[u] = true;
	for(auto v : g[u]) if(!chk[v]) build_centroid(v, u);
}

void update(int x) {
	for(int u = x; u; u = H[u]) ans[u] = min(ans[u], d(u, x));
}

int query(int x) {
	int mn = n;
	for(int u = x; u; u = H[u]) mn = min(mn, ans[u] + d(u, x));
	return mn;
}

int main() {
	scanf("%d %d", &n, &m);
	fill(ans, ans + N, n);
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	dfs(1, 0);
	build_centroid(1, 0);
	update(1);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		if(a == 1) update(b);
		else printf("%d\n", query(b));
	}
}