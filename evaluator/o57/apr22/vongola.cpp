#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1 << 17;

int n, m, A[MAXN], pl[MAXN][18], pr[MAXN][18], pos[MAXN], dep[MAXN];
long d[MAXN];
vector<int> cc[MAXN], g[MAXN];

void dfs(int u = 0, int p = -1) {
	if(p != -1) dep[u] = dep[p] + 1;
	bool st = true;
	pl[u][0] = pr[u][0] = -1;
	for(auto v : g[u]) {
		if(st) pl[u][0] = v, st = false;
		pr[u][0] = v;
		dfs(v, u);
	}
	cc[dep[u]].emplace_back(u);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		A[i] = b;
		if(a != -1) g[a].emplace_back(i);
	}
	dfs();
	for(int i = 0, idx = 0; !cc[i].empty(); ++i) {
		int n = cc[i].size(), ret = -1;
		for(int j = n-1; j >= 0; --j) 
			if(pl[cc[i][j]][0] == -1) pl[cc[i][j]][0] = ret;
			else ret = pl[cc[i][j]][0];
		ret = -1;
		for(int j = 0; j < n; ++j) 
			if(pr[cc[i][j]][0] == -1) pr[cc[i][j]][0] = ret;
			else ret = pr[cc[i][j]][0];
		for(auto v : cc[i]) pos[v] = ++idx;
	}
	for(int i = 1; i <= 17; ++i) for(int j = 0; j < n; ++j) {
		pl[j][i] = pl[pl[j][i-1]][i-1];
		pr[j][i] = pr[pr[j][i-1]][i-1];
	}
	for(int i = 0; i < n; ++i) d[pos[i]] += A[i], d[pos[i]+1] -= A[i];
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int x = a, y = a;
		for(int i = 17; i >= 0; --i) 
			if(b - (1 << i) >= 0) x = pl[x][i], y = pr[y][i], b -= (1 << i);
		d[pos[a]] -= (long)(c) * (pos[y] - pos[x] + 1);
		d[pos[a]+1] += (long)(c) * (pos[y] - pos[x] + 1);
		d[pos[x]] += c;
		d[pos[y]+1] -= c;
	}
	for(int i = 1; i <= n; ++i) if(i) d[i] += d[i-1];
	for(int i = 0; i < n; ++i) printf("%lld\n", d[pos[i]]);
}