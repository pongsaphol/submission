#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5, B = 22, INF = 1e9;

int n, pos[N], dep[N], sz[N], mark[N], col[N], in[N], out[N], mx[1<<B], ans[N];
vector<int> g[N];

void get_sz(int u) {
	static int idx = 0;
	in[u] = ++idx; pos[idx] = u, sz[u] = 1;
	for(int &v : g[u]) {
		dep[v] = dep[u] + 1;
		mark[v] = mark[u] ^ (1 << col[v]);
		get_sz(v);
		sz[u] += sz[v];
		if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
	}
	out[u] = idx;
}

void dfs(int u, bool st) {
	for(int v : g[u]) if(v != g[u][0]) dfs(v, false);
	if(g[u].size()) dfs(g[u][0], true);
	for(int j = 0; j <= B; ++j) {
		int now = j == B ? mark[u] : (mark[u] ^ (1 << j));
		ans[u] = max(ans[u], mx[now] - dep[u]);
	}
	mx[mark[u]] = max(mx[mark[u]], dep[u]);
	for(int v : g[u]) if(v != g[u][0]) {
		for(int i = in[v]; i <= out[v]; ++i) {
			int z = pos[i];
			for(int j = 0; j <= B; ++j) {
				int now = j == B ? mark[z] : (mark[z] ^ (1 << j));
				ans[u] = max(ans[u], mx[now] + dep[z] - 2*dep[u]);
			}
		}
		for(int i = in[v]; i <= out[v]; ++i) {
			int z = pos[i];
			mx[mark[z]] = max(mx[mark[z]], dep[z]);
		}
	}
	if(!st) for(int i = in[u]; i <= out[u]; ++i) {
		int z = pos[i];
		mx[mark[z]] = -INF;
	}
	for(int v : g[u]) ans[u] = max(ans[u], ans[v]);
}

int main() {
	scanf("%d", &n);
	for(int j = 0; j < (1 << B); ++j) mx[j] = -INF;
	for(int i = 2; i <= n; ++i) {
		int p; char c; scanf("%d %c", &p, &c);
		g[p].emplace_back(i);
		col[i] = c - 'a';
	}
	get_sz(1);
	dfs(1, false);
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}
