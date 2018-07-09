#include <bits/stdc++.h>
#define tiii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5, M = 33331;

int n, m, u, v, w, q, H[N], dep[N], par[N][18], d[N];
vector<tiii> E;
vector<pii> g[N];

int find(int x) { return H[x] = H[x] == x ? x : find(H[x]); }

int pow2(int x) {
	int ret = 1, m = 2;
	for(; x; x >>= 1) {
		if(x & 1) ret = (ret * m) % M;
		m = (m*m) % M;
	}
	return ret;
}

void dfs(int u, int p) {
	par[u][0] = p;
	dep[u] = dep[p] + 1;
	for(int i = 1; i < 18; ++i) par[u][i] = par[par[u][i-1]][i-1];
	for(auto v : g[u]) if(v.x != p) d[v.x] = (d[u] + v.y)%M, dfs(v.x, u);
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 17; i >= 0; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
	if(a == b) return a;
	for(int i = 17; i >= 0; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
	return par[a][0];	
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) H[i] = i;
	while(m--) {
		scanf("%d %d %d", &u, &v, &w);
		E.emplace_back(u, v, w);
	}
	sort(E.begin(), E.end(), [&](const tiii &a, const tiii &b) {
		return get<2>(a) < get<2>(b);
	});
	for(auto x : E) {
		u = find(get<0>(x)), v = find(get<1>(x));
		if(u != v) {
			H[u] = v;
			tie(u, v, w) = x;
			w = pow2(w);
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
	}
	dfs(1, 0);
	while(q--) {
		scanf("%d %d", &u, &v);
		printf("%d\n", ((d[u] + d[v] - 2*d[lca(u, v)]) % M + M) % M);
	}
}