#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5, INF = 1e9;

int n, m, s, t, sum, d[N], rd[N];
vector<vector<pii> > g(N);

void dijkstra(int s, int d[]) {
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	fill(d, d + N, INF);
	Q.emplace(d[s] = 0, s);
	while(!Q.empty()) {
		auto u = Q.top(); Q.pop();
		if(d[u.y] != u.x) continue;
		for(auto v : g[u.y]) if(d[v.x] > d[u.y] + v.y) {
			d[v.x] = d[u.y] + v.y;
			Q.emplace(d[v.x], v.x);
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);
	vector<tuple<int, int, int> > E;
	for(int i = 0, u, v, w; i < m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		E.emplace_back(u, v, w);
		g[u].emplace_back(v, w), g[v].emplace_back(u, w);
		sum += w;
	}
	dijkstra(s, d);
	dijkstra(t, rd);
	int mx = 0;
	for(auto x : E) {
		int u = get<0>(x), v = get<1>(x), w = get<2>(x);
		mx = max(mx, sum - d[u] - rd[v]);
		mx = max(mx, sum - rd[u] - d[v]);
	}
	cout << mx << endl;
}