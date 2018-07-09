#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

long ans[N];
int n, m, deg[N], d[N];
vector<vector<pii> > g(N);

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
		deg[u]++, deg[v]++;
	}
	queue<int> Q;
	for(int i = 1; i <= n; ++i) {
		d[i] = 1;
		if(deg[i] == 1) Q.emplace(i);
	}
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(auto v : g[u]) if(deg[v.x] > 1) {
			ans[v.y] = 1ll * d[u] * (n - d[u]);
			d[v.x] += d[u];
			if(--deg[v.x] == 1) Q.emplace(v.x);
		}
	}
	for(int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
}