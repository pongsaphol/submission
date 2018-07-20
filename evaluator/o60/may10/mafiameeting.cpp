#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

const int N = 2e5+5;

int n, m, q;
vector<vi> g, ccs;

int id[N], low[N], pre[N];
bitset<N> art, mark;
vi sz;

void find_component(int u, int p) {
	static int idx = 0;
	static stack<int> S;
	pre[u] = low[u] = ++idx;
	mark[u] = true;
	S.emplace(u);
	for(auto v : g[u]) if(!mark[v]) {
		find_component(v, u);
		low[u] = min(low[u], low[v]);
		if(low[v] >= pre[u]) {
			art[u] = true;
			ccs.emplace_back(vi());
			ccs.back().emplace_back(u);
			while(ccs.back().back() != v) ccs.back().emplace_back(S.top()), S.pop();
		}
	} else if(v != p) low[u] = min(low[u], pre[v]);
}

bitset<N> idart;

void gen_bctree() {
	g.clear();
	g.emplace_back(vi());
	sz.emplace_back(0);
	for(int i = 1; i <= n; ++i) if(art[i]) {
		idart[id[i] = g.size()] = true;
		g.emplace_back(vi());
		sz.emplace_back(1);
	}
	for(auto &cc : ccs) {
		g.emplace_back(vi());
		sz.emplace_back(cc.size());
		for(auto v : cc) {
			if(art[v]) g[id[v]].emplace_back(g.size()-1), g.back().emplace_back(id[v]);
			else id[v] = g.size() - 1; 
		}
	}
}

int dep[N], par[N][18], sum_sz[N], sum_block[N];

void init_lca(int u, int p) {
	par[u][0] = p, dep[u] = dep[p] + 1;
	sum_sz[u] = sum_sz[p] + sz[u], sum_block[u] = sum_block[p] + !idart[u];
	for(int i = 1; i <= 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
	for(int v : g[u]) if(v != p) init_lca(v, u);
}

int get_lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 17; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
	if(a == b) return a;
	for(int i = 17; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
	return par[a][0];
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	g.resize(N);
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	find_component(1, 0);
	gen_bctree();
	init_lca(1, 0);
	for(int i = 0, u, v; i < q; ++i) {
		scanf("%d %d", &u, &v);
		if(id[u] == id[v]) {
			printf("%d\n", sz[id[u]]-2);
			continue;
		}
		int lca = get_lca(id[u], id[v]);
		int ret = sum_sz[id[u]] + sum_sz[id[v]] - sum_sz[lca] - sum_sz[par[lca][0]];
		ret -= 2*(sum_block[id[u]] + sum_block[id[v]] - sum_block[lca] - sum_block[par[lca][0]]);
		ret -= art[u] + art[v];
		printf("%d\n", ret);
	}
}

