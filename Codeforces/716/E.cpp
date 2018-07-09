#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define mii map<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

long ans;
int n, m, ipw10[N], pw10[N], dp[N];
vector<vector<pii> > g(N);
bool chk[N];

int phi(int x) {
	int ret = x;
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			while(x % i == 0) x /= i;
			ret -= ret / i;
		}
	}
	if(x ^ 1) ret -= ret / x;
	return ret;
}

int pw(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = (1ll * ret * a) % m;
		a = (1ll * a * a) % m;
		b >>= 1;
	}
	return ret;
}

int find(int u, int p, int sz, pii &ret) {
	dp[u] = 1;
	int mx = 0;
	for(auto v : g[u]) if(v.x != p and !chk[v.x]) {
		dp[u] += find(v.x, u, sz, ret);
		mx = max(mx, dp[v.x]);
	}
	mx = max(mx, sz - dp[u]);
	if(ret.x > mx) ret = pii(mx, u);
	return dp[u];
}

void dfs(int u, int p, int len, int d, mii &M, bool st) {
	if(st) {
		M[d]++;
		for(auto v : g[u]) if(v.x != p and !chk[v.x]) 
			dfs(v.x, u, len+1, (d + 1ll * (m - v.y) * pw10[len]) % m, M, st);
	} else {
		ans += M[(1ll * ipw10[len] * d) % m];
		for(auto v : g[u]) if(v.x != p and !chk[v.x]) 
			dfs(v.x, u, len+1, (v.y + 1ll * d * 10) % m, M, st);
	}
}

void solve(int u, int sz) {
	pii ret(sz+1, -1);
	find(u, -1, sz, ret);
	u = ret.y;
	mii M; M[0]++;
	for(auto v : g[u]) if(!chk[v.x]) {
		dfs(v.x, u, 1, v.y, M, false);
		dfs(v.x, u, 1, (m - v.y % m) % m, M, true);	
	}
	M.clear(); 
	for(auto z = g[u].rbegin(); z != g[u].rend(); ++z) if(!chk[z->x]) {
		dfs(z->x, u, 1, z->y, M, false);
		dfs(z->x, u, 1, (m - z->y % m) % m, M, true);	
	}
	ans += M[0];
	chk[u] = true;
	for(auto v : g[u]) if(!chk[v.x]) solve(v.x, dp[v.x] < dp[u] ? dp[v.x] : sz - dp[u]);
}

int main() {
	scanf("%d %d", &n, &m);
	ipw10[0] = pw10[0] = 1;
	int z = pw(10 % m, phi(m) - 1);
	for(int i = 1; i <= n; ++i) pw10[i] = (1ll * pw10[i-1] * 10) % m, ipw10[i] = (1ll * ipw10[i-1] * z) % m;
	for(int i = 1; i < n; ++i) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	}
	solve(1, n);
	printf("%lld\n", ans);
} 