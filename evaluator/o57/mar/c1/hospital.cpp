#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1e5 + 5;

int n, d[MAXN];
long sum[MAXN], ans = 1e18;
vector<int> g[MAXN];

int dfs(int u, int p) {
	for(auto v : g[u]) if(v != p) d[u] += dfs(v, u), sum[u] += sum[v] + d[v];
	return ++d[u];
}

void mic(int u, int p, long dis = 0, int deg = 0) {
	ans = min(ans, dis + sum[u]);
	for(auto v : g[u]) if(v != p) {
		mic(v, u, dis + (deg + d[u] - d[v]) + sum[u] - (sum[v] + d[v]),
			deg + d[u] - d[v]);
	}
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0);
	mic(1, 0);
	printf("%lld\n", ans);
}