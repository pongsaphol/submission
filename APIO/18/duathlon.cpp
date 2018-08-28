#include <bits/stdc++.h>
#define vi vector<int>
#define long long long 
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 3e5+5;

long ans;
int n, m;
vector<vi> g, ccs;

int id[N], low[N], pre[N];
bitset<N> mark, art;
vi sz;

void find_component(int u, int p) {
	static int idx = 0;
	static stack<int> S;
	pre[u] = low[u] = ++idx;
	mark[u] = true;
	int cnt = 0;
	S.emplace(u);
	for(auto v : g[u]) if(!mark[v]) {
		++cnt;
		find_component(v, u);
		low[u] = min(low[u], low[v]);
		if(!p && cnt > 1 || p && low[v] >= pre[u]) art[u] = true;
		if(low[v] >= pre[u]) {
			ccs.emplace_back(vi());
			ccs.back().emplace_back(u);
			while(ccs.back().back() != v) ccs.back().emplace_back(S.top()), S.pop();
		}
	} else if(v != p) low[u] = min(low[u], pre[v]);
}

bitset<N> idart;

void gen_bctree() {
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
			else id[v] = g.size()-1;
		}
	}
}

bitset<N> chk;
int dp[N];

int find_centroid(int u, int p, int sz, pii &ret) {
	int mx = 0; dp[u] = 1;
	for(auto v : g[u]) if(v != p and !chk[v]) {
		dp[u] += find_centroid(v, u, sz, ret);
		mx = max(mx, dp[v]);
	}
	mx = max(mx, sz - dp[u]);
	if(ret.x > mx) ret = pii(mx, u);
	return dp[u];
}

int rsize[N];

long get(int u) {
	return sz[u] - 2 * (idart[u] ? 0 : 1);
} 

void fill_son(int u, int p, long &ret, long val, bool st, int &wanna) {
	if(st) ans += rsize[u] * (ret + wanna * (val - idart[u]));
	else {
		ret += rsize[u] * (val - idart[u]);
		wanna += rsize[u];
	}
	for(auto v : g[u]) if(v != p and !chk[v]) fill_son(v, u, ret, val + get(v), st, wanna);
}

void centroid_decompos(int u, int sz) {
	pii ret(sz, -1);
	find_centroid(u, 0, sz, ret); 
	chk[u = ret.y] = true;
	long val = (get(u) - idart[u]) * rsize[u];
	if(::sz[u] > 2) ans += (::sz[u] - 2ll) * ((rsize[u]) * (rsize[u]-1ll) / 2);
	int wanna = rsize[u];
	for(auto v : g[u]) if(!chk[v]) {
		fill_son(v, u, val, get(v), true, wanna), 
		fill_son(v, u, val, get(v) + get(u), false, wanna);
	}
	for(auto v : g[u]) if(!chk[v]) centroid_decompos(v, dp[v] < dp[u] ? dp[v] : sz - dp[u]);
}

int main() {
	scanf("%d %d", &n, &m);
	g.resize(n+1);
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	for(int i = 1; i <= n; ++i) if(!mark[i]) find_component(i, 0);
	g.clear();
	gen_bctree();
	for(int i = 1; i <= n; ++i) rsize[id[i]]++;
	pii temp;
	for(int i = 1; i < g.size(); ++i) if(!chk[i]) centroid_decompos(i, find_centroid(i, 0, 0, temp));
	printf("%lld\n", ans << 1);
}