#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+5;

int n, m, ans, dp[MAXN];
char A[MAXN], st[MAXN];
vector<int> g[MAXN], topo;

void dfs(int u) {
	st[u] = 1;
	for(auto v : g[u])  {
		if(st[v] == 1) {
			puts("-1");
			exit(0);
		} else if(!st[v]) dfs(v);
	}
	st[u] = 2;
	topo.emplace_back(u);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	scanf("%s", A + 1);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
	}
	for(int i = 1; i <= n; ++i) if(!st[i]) dfs(i);
	for(auto x : topo) cerr << x << endl;
	for(int i = 'a'; i <= 'z'; ++i) {
		memset(dp, 0, sizeof dp);
		for(auto u : topo) {
			for(auto v : g[u]) dp[u] = max(dp[u], dp[v]);
			if(A[u] == i) dp[u]++;
		}
		ans = max(ans, *max_element(dp, dp + MAXN));
	}
	printf("%d\n", ans);
}