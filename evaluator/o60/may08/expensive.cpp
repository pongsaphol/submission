#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5, C = 105, INF = 1e9;

struct data {
	int x, y, d;
	data(int x, int y, int d) : x(x), y(y), d(d) { }
	data() : x(0), y(0), d(0) { } 
};

int n, m, q, cor[N], rcr[C], d[C][C], sz, id;
data sssp[N][2];
vector<pii> g[N];

void dfs(int rot, int u, int p, int w, int id) {
	if(cor[u]) {
		d[rot][cor[u]] = min(d[rot][cor[u]], w);
		return;
	}
	if(!sssp[u][0].x) sssp[u][0] = data(w, rot, id);
	else sssp[u][1] = data(w, rot, id);
	for(auto v : g[u]) if(v.x != p) dfs(rot, v.x, u, w + v.y, id);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &q);
	fill(d[0], d[C-1] + C, INF);
	while(m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	}
	for(int i = 1; i <= n; ++i) if(g[i].size() > 2) {
		cor[i] = ++sz; rcr[sz] = i;
	}
	if(!sz) cor[1] = ++sz, rcr[1] = 1;
	for(int i = 1; i <= sz; ++i) {
		d[i][i] = 0;
		for(auto v : g[rcr[i]]) {
			dfs(i, v.x, rcr[i], v.y, ++id);
		}
		sssp[rcr[i]][0] = sssp[rcr[i]][1] = data(0, i, id);
	}
	for(int i = 1; i <= n; ++i) if(!sssp[i][1].d) sssp[i][1] = data(0, 0, ++id);
	for(int k = 1; k <= sz; ++k) for(int i = 1; i <= sz; ++i)
	for(int j = 1; j <= sz; ++j) if(d[i][j] > d[i][k] + d[k][j])
		d[i][j] = d[i][k] + d[k][j];
	while(q--) {
		int u, v, mn = 1e9; scanf("%d %d", &u, &v);
		for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) {
		if(sssp[u][i].d == sssp[v][j].d) mn = min(mn, abs(sssp[u][i].x - sssp[v][j].x));
		mn = min(mn, sssp[u][i].x + d[sssp[u][i].y][sssp[v][j].y] + sssp[v][j].x);
		}
		printf("%d\n", mn);
	}
}