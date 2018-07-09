#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1<<17, inf = 1e9;

int n, l, q, anc[MAXN][17], level[MAXN], d[MAXN][10];
vector<int> g[MAXN];

void dfs(int x = 1, int p = 0, int lv = 1) {
	level[x] = lv;
	anc[x][0] = p;
	for(int i = 1; i <= 16; ++i) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for(auto now:g[x]) if(now != p) dfs(now, x, lv+1);
}

int lca(int a, int b) {
	if(level[a] < level[b]) swap(a, b);
	for(int i = 16; i >= 0; --i) {
		if(level[anc[a][i]] >= level[b]) a = anc[a][i];
	}
	if(a == b) return a;
	for(int i = 16; i >= 0; --i) {
		if(anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

void dijkstra(P z, int t) {
	int s;
	if(t&1) s = z.y;
	else s = z.x;
	d[s][t] = 0;
	priority_queue<P, vector<P>, greater<P> > Q;
	Q.push({0, s});
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(d[now.y][t] != now.x) continue;
		int u = now.y;
		for(auto v:g[u]) {
			if((u == z.x && v == z.y) || (u == z.y && v == z.x)) continue;
			if(d[v][t] > d[u][t] + 1) {
				d[v][t] = d[u][t] + 1;
				Q.push({d[v][t], v});
			}
		}
	}
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d%d", &n, &l, &q);
	int p = (1 << n);
	for(int i = 1; i < (1<< (n-1)); ++i) {
		g[i].emplace_back(i<<1);
		g[i].emplace_back(i<<1|1);
		g[i<<1].emplace_back(i);
		g[i<<1|1].emplace_back(i);
		g[i+p].emplace_back((i<<1)+p);
		g[i+p].emplace_back((i<<1|1)+p);
		g[(i<<1)+p].emplace_back(i+p);
		g[(i<<1|1)+p].emplace_back(i+p);
	}
	vector<P> E;
	dfs();
	while(l--) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		E.emplace_back(a, b);
	}

	fill_n(*d, 10*MAXN, inf);
	for(int i = 0; i < E.size(); ++i) {
		dijkstra(E[i], i<<1);
		dijkstra(E[i], i<<1|1);
	}
	// for(int i = 1; i < 32; ++i) {
	// 	printf("%d :: %d\n", i, d[i][0]);
	// }
	while(q--) {
		int ans = inf;
		int a, b;
		scanf("%d%d", &a, &b);
		for(int i = 0; i < E.size(); ++i) {
			ans = min(ans, d[a][i<<1] + d[b][i<<1|1] + 1);
			ans = min(ans, d[b][i<<1] + d[a][i<<1|1] + 1);
		}
		if(a < p && b < p) ans = min(ans, level[a] + level[b] - 2*level[lca(a, b)]);
		if(a >= p && b >= p) ans = min(ans, level[a-p] + level[b-p] - 2*level[lca(a-p, b-p)]);	
		printf("%d\n", ans);
	}
}