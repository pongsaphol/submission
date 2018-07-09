#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, dp[N], ans[N];
vector<vector<int> > g(N);
bool chk[N];

int find(int u, int p, int sz, pii &ret) {
	int mx = 0;
	dp[u] = 1;
	for(auto v : g[u]) if(v != p and !chk[v]) {
		dp[u] += find(v, u, sz, ret);
		mx = max(mx, dp[v]);
	}
	mx = max(mx, sz - dp[u]);
	if(ret.x > mx) ret = pii(mx, u);
	return dp[u];
}

void solve(int u, int lv, int sz) {
	pii ret(sz, -1);
	find(u, -1, sz, ret);
	u = ret.y;
	chk[u] = true;
	ans[u] = lv;
	for(auto v : g[u]) if(!chk[v]) solve(v, lv+1, (dp[v] > dp[u]) ? (sz - dp[u]): dp[v]);
}

int main() {
	memset(ans, -1, sizeof ans);
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	solve(1, 0, n);
	for(int i = 1; i <= n; ++i) printf("%c ", ans[i] + 'A');
}