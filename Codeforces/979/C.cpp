#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n, x, y, d[N];
bool chk[N];
vector<vector<int> > g(N);

bool dfs(int u, int p) {
	d[u]++;
	bool st = u == y;
	for(auto v : g[u]) if(v != p) {
		st |= dfs(v, u);
		d[u] += d[v];
	}
	return chk[u] = st;
}

int main() {
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(x, 0);
	int sum = 1;
	for(auto v : g[x]) if(!chk[v]) sum += d[v];
	printf("%lld\n", 1ll * n * (n - 1) - 1ll * sum * d[y]);
}