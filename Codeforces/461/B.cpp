#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1e5 + 5;

int n, dp[MAXN][2], mod = 1e9 + 7;
bool A[MAXN];
vector<int> g[MAXN];

int plu(int a, int b) {
	return (a + b) % mod;
}

int mul(int a, int b) {
	return ((long)a * b) % (long)mod;
}

void dfs(int u, int p) {
	dp[u][0] = 1, dp[u][1] = 0;
	for(auto v : g[u]) if(v != p) {
		dfs(v, u);
		dp[u][1] = plu(mul(dp[u][1], dp[v][0]), mul(dp[u][0], dp[v][1]));
		dp[u][0] = mul(dp[u][0], dp[v][0]);
	}
	if(A[u]) dp[u][1] = dp[u][0];
	else dp[u][0] = plu(dp[u][0], dp[u][1]);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int v; scanf("%d", &v);
		g[i].emplace_back(v), g[v].emplace_back(i);
	}
	for(int i = 0; i < n; ++i) scanf("%d", A + i);
	dfs(0, -1);
	printf("%d\n", dp[0][1]);
}