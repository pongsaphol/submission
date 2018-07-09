#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 2e5 + 5;

int n, A[MAXN], dp[MAXN][4], ans;
vector<int> g[MAXN], in;
bool chk[MAXN];

int dfs(int u, int p) {
	if(chk[u]) return u;
	chk[u] = true;
	for(auto v : g[u]) if(v != p) {
		int ret = dfs(v, u);
		if(ret == -2) {
			chk[u] = false;
			return -2;
		}
		if(ret == -1) continue;
		in.emplace_back(u);
		if(ret == u) return -2;
		return ret;
	}
	chk[u] = false;
	return -1;
}

int mic(int u, int p) {
	dp[u][0] = A[u];
	vector<int> ret = {0, 0, 0};
	for(auto v : g[u]) if(!chk[v] && v != p) 
		ret.emplace_back(mic(v, u));
	sort(all(ret), greater<int>());
	for(int i = 1; i <= 3; ++i) dp[u][i] = dp[u][i-1] + ret[i-1];
	ans = max(ans, dp[u][3]);
	return dp[u][2];
}

int dpl[MAXN], dpr[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", A + i);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(0, -1);
	for(auto v : in) mic(v, -1);
	int path = 0, mn = 0, pv = n, sum = 0;
	for(auto v : in) {
		sum += dp[v][1];
		dpl[v] = max(dpl[pv], path + dp[v][2]);
		pv = v;
		ans = max(ans, path - mn + dp[v][2]);
		mn = min(mn, path - dp[v][2] + dp[v][1]);
		path += dp[v][1];
	}
	ans = max(ans, sum);
	path = 0, pv = n;
	for(int i = in.size() - 1; i != 0; --i) {
		int v = in[i];
		dpr[v] = max(dpr[pv], path + dp[v][2]);
		pv = v;
		path += dp[v][1];
		ans = max(ans, dpl[in[i-1]] + dpr[in[i]]);
	}
	printf("%d\n", ans);
}