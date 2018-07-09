#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define P pair<int, int>
#define x first
#define y second
#define int long long
using namespace std;

struct edge{
	int u, v, w;
	edge(int u, int v, int w) : u(u), v(v), w(w) { }	
	friend inline bool operator<(const edge &a, const edge &b) {
		return a.w < b.w;
	}
};

const int MAXN = 1e5 + 5;

int n, m, H[MAXN], par[MAXN], spi[MAXN], rot[MAXN], dep[MAXN], pos[MAXN], t[MAXN<<1];
vector<edge> E;
vector<P> g[MAXN];

int find(int x) {
	if(H[x] == 0) return x;
	return H[x] = find(H[x]);
}

int dfs(int u, int p) {
	par[u] = p;
	dep[u] = dep[p] + 1;
	P mx(-1, 0);
	int sum = 1;
	for(auto v : g[u]) if(v.x != p) {
		int now = dfs(v.x, u);
		sum += now;
		if(mx.y < now) mx = P(v.x, now);
	}
	spi[u] = mx.x;
	return sum;
}

void dfs1(int u, int p) {
	for(auto v : g[u]) if(v.x != p) {
		t[pos[v.x] + n] = v.y;
		dfs1(v.x, u);
	}
}

void hld() {
	dfs(1, 0);
	for(int i = 1, idx = 0; i <= n; ++i) if(spi[par[i]] != i) {
		for(int u = i; u != -1; u = spi[u]) pos[u] = idx++, rot[u] = i;
	}
	dfs1(1, 0);
	for(int i = n-1; i != 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

int tquery(int l, int r) {
	int mx = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) mx = max(mx, t[l++]);
		if(r&1) mx = max(mx, t[--r]);
	}
	return mx;
}

int query(int a, int b) {
	int mx = 0;
	while(rot[a] != rot[b]) {
		if(dep[rot[a]] < dep[rot[b]]) swap(a, b);
		mx = max(mx, tquery(pos[rot[a]], pos[a]));
		a = par[rot[a]];
	}
	if(dep[a] < dep[b]) swap(a, b);
	mx = max(mx, tquery(pos[b]+1, pos[a]));
	return mx;
}

int32_t main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%lld %lld", &n, &m);
	while(m--) {
		int u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		E.emplace_back(u, v, w);
	}
	sort(all(E));
	vector<edge> ret;
	int sum = 0, mx = 1e18;
	for(auto x : E) {
		int a = find(x.u), b = find(x.v);
		if(a != b) {
			sum += x.w;
			H[a] = b;
			g[x.u].emplace_back(x.v, x.w);
			g[x.v].emplace_back(x.u, x.w);
		} else ret.emplace_back(x);
	}
	hld();
	for(auto x : ret) {
		int now = sum + x.w - query(x.u, x.v);
		if(now > sum && now < mx) mx = now;
	}
	printf("%lld\n", mx);
}