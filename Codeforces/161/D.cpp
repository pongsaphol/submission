#include <bits/stdc++.h>
#define long long long
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

const int MAXN = 5e4 + 5;

int dp[505][MAXN], n, k;
vector<int> g[MAXN];
long cnt;

void dfs(int u, int p) {
	dp[0][u] = 1;
	for(auto v:g[u]) if(v != p) {
		dfs(v, u);
		for(int i = 0; i < k; ++i) cnt += (long)dp[i][u] * dp[k-i-1][v];
		for(int i = 1; i <= k; ++i) dp[i][u] += dp[i-1][v];
	}
}

int main() {
	ref();
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i)  {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0);
	printf("%lld\n", cnt);
}