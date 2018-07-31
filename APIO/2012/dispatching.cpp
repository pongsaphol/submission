#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5+5;

long ans;
int n, m, in[N], out[N], pos[N], sz[N];
int c[N], l[N];
vector<int> g[N];

void get_sz(int u) {
	static int idx = 0;
	in[u] = ++idx, pos[idx] = u, sz[u] = 1;
	for(int &v : g[u]) {
		get_sz(v), sz[u] += sz[v];
		if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
	}
	out[u] = idx;
}

priority_queue<int> Q;
int sum = 0;

void add(int u) {
	Q.emplace(u), sum += u;
	if(sum > m) sum -= Q.top(), Q.pop();
}

void dfs(int u, bool keep) {
	for(int v : g[u]) if(v != g[u][0]) dfs(v, false);
	if(g[u].size()) dfs(g[u][0], true);
	add(c[u]);
	for(int v : g[u]) if(v != g[u][0]) 
		for(int i = in[v]; i <= out[v]; ++i) add(c[pos[i]]);
	ans = max(ans, 1ll * l[u] * (long)Q.size());
	if(!keep) sum = 0, Q = priority_queue<int>();	
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1, p; i <= n; ++i) {
		scanf("%d %d %d", &p, c+i, l+i);
		if(p) g[p].emplace_back(i);
	}
	get_sz(1);
	dfs(1, false);
	printf("%lld\n", ans);
}