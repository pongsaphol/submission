#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;
vector<vector<pii> g;
vector<int> mark;
vector<bool> chk;

void dfs(int u) {
	mark[u] = 1;
	for(auto v : g[u]) {
		if(!mark[v.x]) chk[v.y] = true, dfs(v.x);
		else if(mark[v.x] == 1) mark[v.x] = 2, chk[v.y] = true;
	} 
}

void solve() {
	scanf("%d %d", &n, &m);
	g.clear(), g.resize(n+1);
	chk.clear(), chk.resize(m+1);
	mark.clear(), mark.resize(n+1);
	vector<pii> E;
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v, i), E.emplace_back(u, v);
	}	
	dfs(1);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
}
