#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

const int MAXN = 2e3+5;

int n, m, k, dp[MAXN][MAXN];

int main() {
	ref();
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		char now;
		scanf(" %c", &now);
		dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (now == '.');
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i) for(int j = k; j <= m; ++j) {
		if(dp[i][j] - dp[i-1][j] - dp[i][j-k] + dp[i-1][j-k] == k) cnt++;
	}
	if(k != 1)
	for(int i = k; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(dp[i][j] - dp[i][j-1] - dp[i-k][j] + dp[i-k][j-1]== k) cnt++;
	}
	printf("%d\n", cnt);
}