#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5;

int n, sz[N];
long d[N], ans;
vector<int> g[N];

void dfs(int u, int p) {
	sz[u] = 1;
	long mx1 = 0, mx2 = 0;
	for(auto v : g[u]) if(v != p) {
		dfs(v, u);
		sz[u] += sz[v];
		long ret = d[v];
		if(ret > mx1) swap(ret, mx1);
		if(ret > mx2) swap(ret, mx2);
	}
	ans = max(ans, mx1 + mx2);
	d[u] = mx1 + 1ll * sz[u] * (n - sz[u]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
}