#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 5e4+5, K = 1e3+5;

int n, k, m;
long dp[2][2][N], s[N], INF = 1e18;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 1; i <= n; ++i) scanf("%lld", s+i), s[i] += s[i-1];
	int cur = 1, pre = 0;
	for(int i = 1; i <= n; ++i) dp[1][pre][i] = min(dp[1][pre][i-1], -s[i]);
	for(int i = 1; i <= k; ++i, swap(cur, pre)) {
		fill(dp[0][cur], dp[0][cur]+N, INF);
		fill(dp[1][cur], dp[1][cur]+N, INF);
		for(int j = 1; j <= n; ++j) {
			dp[0][cur][j] = dp[0][cur][j-1];
			if(j >= m) dp[0][cur][j] = min(dp[0][cur][j], dp[1][pre][j-m] + s[j]);
			dp[1][cur][j] = min(dp[1][cur][j-1], dp[0][cur][j-1] - s[j]);
		}
	}
	printf("%lld\n", s[n] - dp[0][pre][n]);
}