#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

struct item {
	int v, idx, st;
	item() { }
	item(int v, int idx, int st) : v(v), idx(idx), st(st) { }
};

int n, m, sum, w[N];
vector<vector<item> > g(N);
bool chk[N], ans[N];

void euler(int u) {
	while(!g[u].empty() and chk[g[u].back().idx]) g[u].pop_back();
	if(g[u].empty()) return;
	auto now = g[u].back(); g[u].pop_back();
	chk[now.idx] = true, ans[now.idx] = now.st, euler(now.v);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int u, v; scanf("%d %d %d", &u, &v, w+i), sum += w[i];
		g[u].emplace_back(v, i, 1);
		g[v].emplace_back(u, i, 0);
	}
	euler();
	bool st = true;
	for(int i = 1; i <= m; ++i) st &= chk[i];
	assert(st);
	int cnt = 0, ret = 0, z = 0, zz = 0; for(int i = 1; i <= m; ++i) if(ans[i]) cnt++, ret += w[i];
	printf("%d\n", z = 2ll * ret > sum ? m - cnt : cnt);
	for(int i = 1; i <= m; ++i) if(2ll * ret > sum != ans[i]) zz++, printf("%d\n", i);
}