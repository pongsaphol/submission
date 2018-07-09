#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 19;
int n, m, ptr, pos[MAXN], d[MAXN];
bool t[MAXN<<1], lz[MAXN<<1];
vector<int> g[MAXN];

int dfs(int u, int p) {
	for(auto v : g[u]) if(v != p) d[u] += dfs(v, u);
	pos[u] = ++ptr;
	return ++d[u];
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] = true;
		if(l != r) lz[p << 1] = lz[p << 1 | 1] = true;
		lz[p] = false;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p << 1, l, m), travel(x, y, f, p << 1 | 1, m + 1, r);
	t[p] = t[p << 1] & t[p << 1 | 1];
} 

void update(int x, bool v) {
	int l = pos[x] - d[x] + 1, r = pos[x];
	if(v) travel(r, r, [&](int p, int l, int r) { t[p] = false; });
	else travel(l, r, [&](int p, int l, int r) { 
		t[p] = true;
		if(l != r) lz[p << 1] = lz[p << 1 | 1] = true;
	});
} 

bool query(int x) {
	int l = pos[x] - d[x] + 1, r = pos[x];
	bool st = true;
	travel(l, r, [&](int p, int l, int r) { st &= t[p]; });
	return st;
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0);
	scanf("%d", &m);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 1) update(b, 0);
		if(a == 2) update(b, 1);
		if(a == 3) printf("%d\n", query(b));
	}
	return 0;
}