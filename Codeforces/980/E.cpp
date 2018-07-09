#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, k, par[N][21], dep[N], chk[N];
vector<int> g[N];

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u][0] = p;
	for(int i = 1; i <= 20; ++i) par[u][i] = par[par[u][i-1]][i-1];
	for(auto v : g[u]) if(v != p) dfs(v, u);
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(n, 0);
	k = n-k;
	stack<int> S;
	chk[n] = true, chk[0] = true;
	int cnt = 1;
	for(int i = n; i != 0; --i) {
		if(chk[i]) continue;
		int ret = i;
		int zz = 0;
		for(int j = 20; j >= 0; --j) {
			if(chk[par[ret][j]] == 0) ret = par[ret][j], zz += (1 << j);
		}
		zz++;
		if(cnt + zz <= k) {
			cnt += zz;
			int y = i;
			while(!chk[y]) chk[y] = true, y = par[y][0];
		} else S.emplace(i);
	}
	while(!S.empty()) {
		printf("%d ", S.top());
		S.pop();
	}
}