#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 2e5+5;

int n, m, q, t[MAXN], d[MAXN], level[MAXN], anc[MAXN][18], par[MAXN];
vector<P> g[MAXN];

void update(int x, int v) {
	while(x <= m) {
		t[x] += v;
		x += x & -x;
	}
}

int query(int x) {
	int v = 0;
	while(x > 0) {
		v += t[x];
		x -= x & -x;
	}
	return v;
}

void dfs(int z, int x, int p, int lv, int dis) {
	anc[x][0] = p;
	par[x] = z;
	d[x] = dis;
	level[x] = lv;
	for(int i = 1; i < 18; ++i) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for(auto v:g[x]) {
		if(v.x <= m || v.x == p) continue;
		dfs(z, v.x, x, lv+1, dis+v.y);
	}
}

int lca(int a, int b) {
	if(level[a] < level[b]) swap(a, b);
	for(int i = 17; i >= 0; --i) {
		if(level[anc[a][i]] >= level[b]) a = anc[a][i];
	}
	if(a == b) return a;
	for(int i = 17; i >= 0; --i) {
		if(anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 1; i <= m; ++i) {
		int now = input();
		update(i, now);
	}
	for(int i = m+1; i <= n; ++i) {
		int v = input(), w = input();
		g[i].emplace_back(v, w);
		g[v].emplace_back(i, w);
	}
	for(int i = 1; i <= m; ++i) dfs(i, i, i, 1, 0);
	while(q--) {
		int met = input(), a = input(), b = input();
		if(met) {
			if(par[a] == par[b]) {
				int LCA = lca(a, b);
				printf("%d\n", d[a] + d[b] - 2*d[LCA]);
			} else {
				int sum = d[a] + d[b];
				a = par[a];
				b = par[b];
				if(a > b) swap(a, b);
				int dcy = min(query(m) - query(b-1) + query(a-1), query(b-1) - query(a-1));
				sum += dcy;
				printf("%d\n", sum);
			}
		} else update(a, b - query(a) + query(a-1));
	}
}
