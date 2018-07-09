#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<18;

vector<int> g[MAXN];
int n, m, cc, pos[MAXN], d[MAXN], t[MAXN<<1], rps[MAXN];
bool A[MAXN], lz[MAXN<<1];

int dfs(int u) {
	for(auto v:g[u]) d[u] += dfs(v);
	pos[u] = ++cc, rps[cc] = u;
	return ++d[u];
}

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = A[rps[l]];
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] = (r-l+1) - t[p];
		if(l != r) {
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
		lz[p] = 0;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p<<1, l, m), travel(x, y, f, p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

void update(int p) {
	int _l = pos[p] - d[p] + 1, _r = pos[p];
	travel(_l, _r, [&](int p, int l, int r) {
		t[p] = (r-l+1) - t[p];
		if(l != r) {
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
	});
}

int query(int p) {
	int _l = pos[p] - d[p] + 1, _r = pos[p], sum = 0;
	travel(_l, _r, [&](int p, int l, int r) {
		sum += t[p];
	});
	return sum;
}

int main() {
	// freopen("r", "r", stdin);	
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		g[x].emplace_back(i);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	build();
	scanf("%d", &m);
	while(m--) {
		char inp[10];
		int p;
		scanf("%s %d", inp, &p);
		if(!strcmp(inp, "pow")) update(p);
		else printf("%d\n", query(p));
	}
}