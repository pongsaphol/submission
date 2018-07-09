#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, d[MAXN], low[MAXN], scc[MAXN], cnt[MAXN], idx, cc;
bool is[MAXN];
vector<int> g[MAXN];
stack<int> S;

void tar(int u) {
	d[u] = low[u] = ++idx;
	is[u] = true;
	S.push(u);
	for(auto v : g[u]) {
		if(!d[v]) {
			tar(v);
			low[u] = min(low[u], low[v]);
		} else if(is[v]) low[u] = min(low[u], low[v]);
	}
	if(d[u] == low[u]) {
		cc++;
		while(!S.empty()) {
			int v = S.top();
			S.pop();
			scc[v] = cc;
			is[v] = false;
			if(u == v) break;
		}
	}
}

vector<int> G[MAXN];

void dfs(int u) {
	is[u] = true;
	for(auto v : G[u]) if(!is[v]) dfs(v);
	S.push(u);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
	}
	for(int i = 1; i <= n; ++i) if(!d[i]) tar(i);
	for(int i = 1; i <= n; ++i) {
		printf("%d -> %d\n", i, scc[i]);
		for(auto v : g[i]) if(scc[i] != scc[v]) G[scc[i]].emplace_back(scc[v]);
		cnt[scc[i]]++;
	}
	for(int i = 1; i <= cc; ++i) dfs(i);
	while(!S.empty()) {
		auto now = S.top();
		S.pop();
		for(auto v : G[now]) cnt[now] += cnt[v];
	}
	for(int i = 1; i <= n; ++i) printf("%d\n", cnt[scc[i]]);
}