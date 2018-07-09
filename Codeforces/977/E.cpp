#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
vector<int> g[N];
bool st, chk[N];


void dfs(int u, int p) {
	chk[u] = true;
	if(g[u].size() != 2) st = false;
	for(auto v : g[u]) if(v != p and !chk[v]) dfs(v, u);
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	int sum = 0;
	for(int i = 1; i <= n; ++i) if(!chk[i]) st = true, dfs(i, i), sum += st;
	printf("%d\n", sum);
}